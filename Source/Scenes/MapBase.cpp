#include "MapBase.h"

#include "cocos/2d/CCLayer.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCEventMouse.h"
#include "cocos/physics/CCPhysicsWorld.h"

#include "Engine/Camera/GameCamera.h"
#include "Engine/Deserializers/LayerDeserializer.h"
#include "Engine/Events/HackableEvents.h"
#include "Engine/Events/NavigationEvents.h"
#include "Engine/Hackables/CodeEditor/CodeHud.h"
#include "Engine/Hackables/RadialMenu.h"
#include "Engine/Maps/GameMap.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/UI/HUD/Hud.h"
#include "Events/PlatformerEvents.h"
#include "Menus/Confirmation/ConfirmationMenu.h"
#include "Menus/Ingame/IngameMenu.h"
#include "Menus/Options/OptionsMenu.h"
#include "Menus/Pause/PauseMenu.h"
#include "Scenes/Platformer/Level/Backgrounds/MatrixRain/MatrixRain.h"
#include "Scenes/Title/TitleScreen.h"

#include "Resources/BackgroundResources.h"

using namespace cocos2d;

MapBase::MapBase(bool useIngameMenu, bool allowHackerMode)
{
	this->allowHackerMode = allowHackerMode;
	this->layerDeserializers = std::vector<LayerDeserializer*>();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->map = nullptr;
	this->mapNode = Node::create();
	this->radialMenu = allowHackerMode ? RadialMenu::create() : nullptr;
	this->codeHud = allowHackerMode ? CodeHud::create() : nullptr;
	this->ingameMenu = useIngameMenu ? IngameMenu::create() : nullptr;
	this->pauseMenu = useIngameMenu ? (PauseMenu*)this->ingameMenu : PauseMenu::create();
	this->optionsMenu = OptionsMenu::create();
	this->confirmationMenu = ConfirmationMenu::create();
	this->hudNode = Node::create();
	this->hud = Hud::create();
	this->hackerModeVisibleHud = Hud::create();
	this->miniGameHud = Hud::create();
	this->menuBackDrop = Hud::create();
	this->menuHud = Hud::create();
	this->topMenuHud = Hud::create();

	this->hackerModeGlow = Hud::create();
	this->sensingGlow = Hud::create();
	this->hackerModeRain = MatrixRain::create();
	
	Sprite* glowFx = Sprite::create(BackgroundResources::Hacking_HackerModeBackground);
	glowFx->setAnchorPoint(Vec2::ZERO);
	
	Sprite* senseFx = Sprite::create(BackgroundResources::Hacking_SensingBackground);
	senseFx->setAnchorPoint(Vec2::ZERO);

	this->hackerModeGlow->addChild(glowFx);
	this->hackerModeGlow->setAnchorPoint(Vec2::ZERO);

	this->sensingGlow->addChild(senseFx);
	this->sensingGlow->setAnchorPoint(Vec2::ZERO);

	this->sensingGlow->setVisible(false);
	this->hackerModeGlow->setVisible(false);
	this->hackerModeRain->setVisible(false);

	this->menuBackDrop->addChild(LayerColor::create(Color4B::BLACK, visibleSize.width, visibleSize.height));

	if (allowHackerMode)
	{
		this->menuHud->addChild(this->radialMenu);
		this->menuHud->addChild(this->codeHud);
	}
	
	this->topMenuHud->addChild(this->pauseMenu);
	this->topMenuHud->addChild(this->optionsMenu);
	this->topMenuHud->addChild(this->confirmationMenu);
	this->addChild(this->hackerModeRain);
	this->addChild(this->mapNode);
	this->addChild(this->hudNode);
	this->addChild(this->hud);
	this->addChild(this->hackerModeVisibleHud);
	this->addChild(this->sensingGlow);
	this->addChild(this->hackerModeGlow);
	this->addChild(this->miniGameHud);
	this->addChild(this->menuBackDrop);
	this->addChild(this->menuHud);
	this->addChild(this->topMenuHud);
}

MapBase::~MapBase()
{
}

void MapBase::onEnter()
{
	super::onEnter();

	this->menuBackDrop->setOpacity(0);
	this->pauseMenu->setVisible(false);
	this->optionsMenu->setVisible(false);
	this->confirmationMenu->setVisible(false);

	if (this->map != nullptr)
	{
		GameCamera::getInstance()->setBounds(Rect(0.0f, 0.0f, this->map->getMapSize().width, this->map->getMapSize().height));
	}
}

void MapBase::onEnterTransitionDidFinish()
{
	super::onEnterTransitionDidFinish();
}

void MapBase::resume(void)
{
	super::resume();
}

void MapBase::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}

void MapBase::initializeListeners()
{
	super::initializeListeners();
	
	this->addEventListenerIgnorePause(EventListenerCustom::create(PlatformerEvents::EventAllowPause, [=](EventCustom* eventCustom)
	{
		this->canPause = true;
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(PlatformerEvents::EventDisallowPause, [=](EventCustom* eventCustom)
	{
		this->canPause = false;
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(PlatformerEvents::EventQueryMapArgs, [=](EventCustom* eventCustom)
	{
		PlatformerEvents::QueryMapArgsArgs* args = static_cast<PlatformerEvents::QueryMapArgsArgs*>(eventCustom->getUserData());

		if (args != nullptr && args->argRef != nullptr)
		{
			for (auto it = this->mapArgs.begin(); it != this->mapArgs.end(); it++)
			{
				args->argRef->push_back(*it);
			}
		}
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventHackerModeToggle, [=](EventCustom* eventCustom)
	{
		this->toggleHackerMode(eventCustom->getUserData());
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventSensingEnable, [=](EventCustom*)
	{
		this->sensingGlow->setVisible(true);
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventSensingDisable, [=](EventCustom*)
	{
		this->sensingGlow->setVisible(false);
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventAllowHackerMode, [=](EventCustom*)
	{
		this->allowHackerMode = true;
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventDisallowHackerMode, [=](EventCustom*)
	{
		this->allowHackerMode = false;
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::EventQueryHackerModeAllowed, [=](EventCustom* eventCustom)
	{
		HackableEvents::HackerModeQueryArgs* args = static_cast<HackableEvents::HackerModeQueryArgs*>(eventCustom->getUserData());

		if (args != nullptr)
		{
			args->hackerModeAllowed = this->allowHackerMode;
		}
	}));

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_ESCAPE }, [=](InputEvents::InputArgs* args)
	{
		if (!this->canPause ||!GameUtils::isFocused(this))
		{
			return;
		}
		
		args->handle();

		this->openPauseMenu(this);
	});

	this->optionsMenu->setBackClickCallback([=]()
	{
		this->optionsMenu->setVisible(false);
		this->openPauseMenu(this);
	});

	this->pauseMenu->setOptionsClickCallback([=]()
	{
		this->pauseMenu->setVisible(false);
		this->optionsMenu->setVisible(true);
		GameUtils::focus(this->optionsMenu);
	});

	this->pauseMenu->setQuitToTitleClickCallback([=]()
	{
		this->menuBackDrop->setOpacity(0);
		this->pauseMenu->setVisible(false);
		NavigationEvents::LoadScene(NavigationEvents::LoadSceneArgs(TitleScreen::getInstance()));
	});
}

void MapBase::addLayerDeserializer(LayerDeserializer* layerDeserializer)
{
	this->addChild(layerDeserializer);
	this->layerDeserializers.push_back(layerDeserializer);
}

void MapBase::addLayerDeserializers(std::vector<LayerDeserializer*> layerDeserializers)
{
	for (auto it = layerDeserializers.begin(); it != layerDeserializers.end(); it++)
	{
		this->addChild(*it);
		this->layerDeserializers.push_back(*it);
	}
}

bool MapBase::loadMap(std::string mapResource)
{
	if (this->map != nullptr)
	{
		this->mapNode->removeChild(this->map);
	}
	
	this->map = GameMap::deserialize(mapResource, this->layerDeserializers);

	if (this->map != nullptr)
	{
		this->mapNode->addChild(this->map);
		GameCamera::getInstance()->setBounds(Rect(0.0f, 0.0f, this->map->getMapSize().width, this->map->getMapSize().height));

		return true;
	}

	return false;
}

void MapBase::onDeveloperModeEnable(int debugLevel)
{
	if (this->map != nullptr)
	{
		this->map->setCollisionLayersVisible(true);
	}
}

void MapBase::onDeveloperModeDisable()
{
	if (this->map != nullptr)
	{
		this->map->setCollisionLayersVisible(false);
	}
}

void MapBase::onHackerModeEnable(int hackFlags)
{
	super::onHackerModeEnable(hackFlags);

	GameUtils::pause(this);
	GameUtils::resume(this->hackerModeVisibleHud);

	this->hud->setVisible(false);
	this->hackerModeGlow->setVisible(true);
	this->hackerModeRain->setVisible(true);
}

void MapBase::onHackerModeDisable()
{
	super::onHackerModeDisable();

	this->hud->setVisible(true);
	this->hackerModeGlow->setVisible(false);
	this->hackerModeRain->setVisible(false);

	GameUtils::resume(this);
}

void MapBase::toggleHackerMode(void* userData)
{
	if (!this->allowHackerMode)
	{
		return;
	}

	if (!this->hackermodeEnabled)
	{
		HackableEvents::HackToggleArgs args = *static_cast<HackableEvents::HackToggleArgs*>(userData);
		
		HackableEvents::TriggerHackerModeEnable(args);
	}
	else
	{
		HackableEvents::TriggerHackerModeDisable();
	}
}

void MapBase::openPauseMenu(Node* refocusTarget)
{
	if (!this->canPause)
	{
		return;
	}
	
	this->menuBackDrop->setOpacity(196);
	this->pauseMenu->open([=]()
	{
		this->menuBackDrop->setOpacity(0);
		GameUtils::focus(refocusTarget);
	});
}
