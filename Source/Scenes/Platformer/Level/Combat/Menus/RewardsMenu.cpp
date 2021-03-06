#include "RewardsMenu.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/Events/ObjectEvents.h"
#include "Engine/Input/ClickableTextNode.h"
#include "Engine/Inventory/CurrencyInventory.h"
#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/Item.h"
#include "Engine/Inventory/MinMaxPool.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Sound/Sound.h"
#include "Engine/UI/Controls/ScrollPane.h"
#include "Entities/Platformer/PlatformerEnemy.h"
#include "Entities/Platformer/StatsTables/StatsTables.h"
#include "Events/CombatEvents.h"
#include "Events/PlatformerEvents.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityDropTableBehavior.h"

#include "Resources/ObjectResources.h"
#include "Resources/SoundResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

RewardsMenu* RewardsMenu::create()
{
	RewardsMenu* instance = new RewardsMenu();

	instance->autorelease();

	return instance;
}

RewardsMenu::RewardsMenu()
{
	this->victoryMenu = Sprite::create(UIResources::Combat_VictoryMenu);
	this->expSprite = Sprite::create(UIResources::Menus_Icons_Stars);
	this->expValue = ConstantString::create(std::to_string(0));
	this->expLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H1, this->expValue);
	this->victorySound = Sound::create(SoundResources::Platformer_Combat_Victory);

	this->victoryLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::M2, Strings::Platformer_Combat_Victory::create());

	LocalizedLabel*	returnLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, Strings::Menus_Return::create());
	LocalizedLabel*	returnLabelHover = returnLabel->clone();

	returnLabel->enableOutline(Color4B::BLACK, 2);
	returnLabelHover->enableOutline(Color4B::BLACK, 2);

	this->returnButton = ClickableTextNode::create(returnLabel, returnLabelHover, Sprite::create(UIResources::Menus_Buttons_WoodButton), Sprite::create(UIResources::Menus_Buttons_WoodButtonSelected));

	this->expLabel->enableOutline(Color4B::BLACK, 2);
	this->victoryLabel->enableOutline(Color4B::BLACK, 2);

	this->expLabel->setAnchorPoint(Vec2(0.0f, 0.5f));

	this->addChild(this->victoryMenu);
	this->addChild(this->expSprite);
	this->addChild(this->expLabel);
	this->addChild(this->victoryLabel);
	this->addChild(this->returnButton);
	this->addChild(this->victorySound);
}

RewardsMenu::~RewardsMenu()
{
}

void RewardsMenu::onEnter()
{
	super::onEnter();

	this->setOpacity(0);
}

void RewardsMenu::initializePositions()
{
	super::initializePositions();

	this->victoryLabel->setPosition(Vec2(0.0f, 176.0f));
	this->victoryMenu->setPosition(Vec2(0.0f, 0.0f));
	this->expSprite->setPosition(Vec2(-48.0f, 32.0f));
	this->expLabel->setPosition(Vec2(16.0f, 32.0f));
	this->returnButton->setPosition(Vec2(16.0f, -160.0f));
}

void RewardsMenu::initializeListeners()
{
	super::initializeListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(CombatEvents::EventGiveRewards, [=](EventCustom* args)
	{
		this->loadRewards();
	}));

	this->returnButton->setMouseClickCallback([=](InputEvents::MouseEventArgs*)
	{
		CombatEvents::TriggerReturnToMap();
	});
}

void RewardsMenu::show()
{
	this->runAction(FadeTo::create(1.0f, 255));
	this->victorySound->play();
}

void RewardsMenu::loadRewards()
{
	int totalExpGain = 0;

	ObjectEvents::QueryObjects(QueryObjectsArgs<PlatformerEnemy>([&](PlatformerEnemy* enemy)
	{
		totalExpGain += StatsTables::getKillExp(enemy);

		enemy->getAttachedBehavior<EntityDropTableBehavior>([=](EntityDropTableBehavior* entityDropTableBehavior)
		{
			MinMaxPool* dropPool = entityDropTableBehavior->getDropPool();

			if (dropPool != nullptr)
			{
				PlatformerEvents::TriggerGiveItemsFromPool(PlatformerEvents::GiveItemsFromPoolArgs(dropPool));
			}
		});
	}), PlatformerEnemy::PlatformerEnemyTag);

	this->expValue->setString(std::to_string(totalExpGain));
}
