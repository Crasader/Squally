#include "Level.h"

Size Level::mapSize = Size::ZERO;
bool Level::hackerMode = false;

Level* Level::create(std::string levelResourceFilePath)
{
	Level* level = new Level(levelResourceFilePath);

	level->autorelease();

	return level;
}

Level::Level(std::string levelResourceFilePath)
{
	if (!FadeScene::initWithPhysics())
	{
		throw std::uncaught_exception();
	}

	// Physics / collision debugging
	// this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	this->getPhysicsWorld()->setGravity(Vec2(0.0f, 0.0f));

	experimental::TMXTiledMap* map = experimental::TMXTiledMap::create(levelResourceFilePath);
	Level::mapSize = Size(map->getMapSize().width * map->getTileSize().width, map->getMapSize().height * map->getTileSize().height);

	this->background = LevelParser::initializeBackground(map);
	this->hackerModeBackground = Sprite::create(Resources::Ingame_Background_MatrixRain_HackerModeBackground);
	this->hackerModeRain = MatrixRain::create();
	this->hackerModePostProcessGlow = PostProcess::create(Resources::Shaders_Vertex_Generic, Resources::Shaders_Fragment_GrayBlur);
	this->hud = HUD::create();
	this->backgroundParallax = LevelParser::initializeParallaxObjects(map, "background-parallax");
	this->backgroundLayer = LevelParser::initializeTileLayer(map, "background");
	this->backgroundDecor = LevelParser::initializeDecor(map, "background-decor");
	this->midgroundLayer = LevelParser::initializeTileLayer(map, "midground");
	this->midgroundDecor = LevelParser::initializeDecor(map, "midground-decor");
	this->foregroundLayer = LevelParser::initializeTileLayer(map, "foreground");
	this->foregroundDecor = LevelParser::initializeDecor(map, "foreground-decor");
	this->objectLayer = LevelParser::initializeObjects(map, CC_CALLBACK_1(HUD::registerHackableObject, this->hud));
	this->entityLayer = LevelParser::initializeEntities(map, CC_CALLBACK_1(HUD::registerHackableObject, this->hud));
	this->collisionLayer = LevelParser::initializeCollision(map);
	this->environmentLayer = LevelParser::initializeEnvironment(map);
	this->gameLayers = Layer::create();
	this->gamePostProcessInversion = PostProcess::create(Resources::Shaders_Vertex_Generic, Resources::Shaders_Fragment_Inverse);
	this->gamePostProcessNightVision = PostProcess::create(Resources::Shaders_Vertex_Generic, Resources::Shaders_Fragment_NightVision);
	this->addChild(InputManager::claimInstance());

	this->addChild(this->background);
	this->addChild(this->hackerModeBackground);
	this->addChild(this->hackerModeRain);
	this->addChild(this->hackerModePostProcessGlow);
	this->gameLayers->addChild(this->backgroundParallax);
	this->gameLayers->addChild(this->backgroundLayer);
	this->gameLayers->addChild(this->backgroundDecor);
	this->gameLayers->addChild(this->midgroundLayer);
	this->gameLayers->addChild(this->midgroundDecor);
	this->gameLayers->addChild(this->objectLayer);
	this->gameLayers->addChild(this->entityLayer);
	this->gameLayers->addChild(this->foregroundLayer);
	this->gameLayers->addChild(this->foregroundDecor);
	this->gameLayers->addChild(this->collisionLayer);
	this->gameLayers->addChild(this->environmentLayer);
	this->addChild(this->gameLayers);
	this->addChild(this->gamePostProcessInversion);
	this->addChild(this->gamePostProcessNightVision);
	this->addChild(this->hud);

	this->scheduleUpdate();
	this->update(0.0f);

	this->initializeListeners();
}

Level::~Level()
{
}

void Level::resume(void)
{
	Node::resume();

	this->initializeListeners();

	if (Level::hackerMode)
	{
		this->enableHackerMode();
	}
}

void Level::onEnter()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	FadeScene::onEnter();

	this->hackerModeBackground->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));

	this->addChild(Mouse::claimInstance());
}

void Level::update(float dt)
{
	FadeScene::update(dt);

	Size visibleSize = Director::getInstance()->getVisibleSize();

	// Handle camera scrolling from player traveling past scroll distance
	if (LevelCamera::cameraPosition.x < Player::position.x - LevelCamera::cameraScrollOffsetX - visibleSize.width / 2)
	{
		LevelCamera::cameraPosition.x = Player::position.x - LevelCamera::cameraScrollOffsetX - visibleSize.width / 2;
	}
	else if (LevelCamera::cameraPosition.x > Player::position.x + LevelCamera::cameraScrollOffsetX - visibleSize.width / 2)
	{
		LevelCamera::cameraPosition.x = Player::position.x + LevelCamera::cameraScrollOffsetX - visibleSize.width / 2;
	}

	if (LevelCamera::cameraPosition.y < Player::position.y - LevelCamera::cameraScrollOffsetY - visibleSize.height / 2)
	{
		LevelCamera::cameraPosition.y = Player::position.y - LevelCamera::cameraScrollOffsetY - visibleSize.height / 2;
	}
	else if (LevelCamera::cameraPosition.y > Player::position.y + LevelCamera::cameraScrollOffsetY - visibleSize.height / 2)
	{
		LevelCamera::cameraPosition.y = Player::position.y + LevelCamera::cameraScrollOffsetY - visibleSize.height / 2;
	}

	// Prevent camera from leaving level bounds
	LevelCamera::cameraPosition.x = min(LevelCamera::cameraPosition.x, this->mapSize.width - visibleSize.width);
	LevelCamera::cameraPosition.x = max(LevelCamera::cameraPosition.x, 0.0f);

	LevelCamera::cameraPosition.y = min(LevelCamera::cameraPosition.y, this->mapSize.height - visibleSize.height);
	LevelCamera::cameraPosition.y = max(LevelCamera::cameraPosition.y, 0.0f);

	// Scroll world
	this->gameLayers->setPosition(-LevelCamera::cameraPosition);
}

void Level::initializeListeners()
{
	EventListenerKeyboard* listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Level::onKeyPressed, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

// Implementation of the keyboard event callback function prototype
void Level::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (Level::hackerMode)
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_ESCAPE:
		case EventKeyboard::KeyCode::KEY_TAB:
			this->disableHackerMode();
			break;
		}
	}
	else
	{
		switch (keyCode)
		{
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			Director::getInstance()->pushScene(PauseMenu::create());
			break;
		case EventKeyboard::KeyCode::KEY_TAB:
			this->enableHackerMode();
			break;
		}
	}
}

void Level::enableHackerMode()
{
	Level::hackerMode = true;
	Utils::focus(this->hud);

	// We still want to process input while paused
	this->initializeListeners();
}

void Level::disableHackerMode()
{
	Level::hackerMode = false;
	Utils::resumeAll();
}

void Level::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
	// Manual drawing (to apply post processing effects)
	if (!Level::hackerMode)
	{
		// Set visibility of desired layers
		this->background->setVisible(true);
		this->hackerModeBackground->setVisible(false);
		this->hackerModeRain->setVisible(false);
		this->hackerModePostProcessGlow->setVisible(false);
		this->gameLayers->setVisible(true);
		this->hud->hackableObjectsHud->setVisible(false);
		this->gamePostProcessInversion->setVisible(false);
		this->gamePostProcessNightVision->setVisible(false);

		// Show parts of the game layer
		this->backgroundParallax->setVisible(true);
		this->backgroundLayer->setVisible(true);
		this->backgroundDecor->setVisible(true);
		this->midgroundLayer->setVisible(true);
		this->midgroundDecor->setVisible(true);
		this->foregroundLayer->setVisible(true);
		this->foregroundDecor->setVisible(true);
		this->environmentLayer->setVisible(true);
	}
	else
	{
		// Set visibility of desired layers
		this->background->setVisible(false);
		this->hackerModeBackground->setVisible(true);
		this->hackerModeRain->setVisible(true);
		this->hackerModePostProcessGlow->setVisible(true);
		this->gameLayers->setVisible(true);
		this->hud->hackableObjectsHud->setVisible(true);
		this->gamePostProcessInversion->setVisible(true);
		this->gamePostProcessNightVision->setVisible(true);

		// Hide parts of the game layer
		this->backgroundParallax->setVisible(false);
		this->backgroundLayer->setVisible(false);
		this->backgroundDecor->setVisible(false);
		this->midgroundLayer->setVisible(false);
		this->midgroundDecor->setVisible(false);
		this->foregroundLayer->setVisible(false);
		this->foregroundDecor->setVisible(false);
		this->environmentLayer->setVisible(false);

		// Draw hackermode level
		this->hackerModeRain->draw();

		this->gamePostProcessInversion->draw(this->gameLayers);
		this->gamePostProcessNightVision->draw(this->gamePostProcessInversion);

		// Prevent double render
		this->gameLayers->setVisible(false);
	}
}
