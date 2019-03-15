#include "InteractMenu.h"

#include "cocos/2d/CCLayer.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventListenerKeyboard.h"

#include "Engine/Input/ClickableNode.h"
#include "Engine/Input/ClickableTextNode.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/Localization/LocalizedString.h"

#include "Resources/SoundResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

InteractMenu* InteractMenu::create(LocalizedString* displayString)
{
	InteractMenu* instance = new InteractMenu(displayString);

	instance->autorelease();

	return instance;
}

InteractMenu::InteractMenu(LocalizedString* displayString)
{
	this->displayString = displayString;
	this->displayLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H1, this->displayString);
	this->backdrop = LayerColor::create(Color4B(0, 0, 0, 196), 196, 64);

	this->setOpacity(0);

	this->addChild(this->backdrop);
	this->addChild(this->displayLabel);
}

InteractMenu::~InteractMenu()
{
}

void InteractMenu::onEnter()
{
	super::onEnter();

	this->setOpacity(0);
}

void InteractMenu::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->backdrop->setPositionX(-196.0f / 2.0f);
	this->displayLabel->setPositionX(-196.0f / 2.0f);
}

void InteractMenu::initializeListeners()
{
	super::initializeListeners();
}

void InteractMenu::show()
{
	this->stopAllActions();
	this->runAction(FadeTo::create(0.5f, 255));
}

void InteractMenu::hide()
{
	this->stopAllActions();
	this->runAction(FadeTo::create(0.5f, 0));
}
