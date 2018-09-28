#include "HexusOpponentMenuBase.h"

const std::string HexusOpponentMenuBase::winsPrefix = "WINS_";

HexusOpponentMenuBase::HexusOpponentMenuBase(std::string chapterProgressSaveKey)
{
	this->chapterProgressSaveKey = chapterProgressSaveKey;
	this->opponents = std::vector<HexusOpponentPreview*>();
	this->scrollPane = ScrollPane::create(Size(1536.0f, 840.0f), Color4B(0, 0, 0, 196));
	this->background = Sprite::create(Resources::Menus_MinigamesMenu_Hexus_WoodBackground);
	this->opponentSelectLabel = Label::create("Select Opponent", Localization::getMainFont(), Localization::getFontSizeH1(Localization::getMainFont()));

	Label* manageDeckLabel = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	Label* manageDeckLabelHover = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	Label* manageDeckLabelClick = Label::create("Manage Cards", Localization::getMainFont(), Localization::getFontSizeP(Localization::getMainFont()));
	
	manageDeckLabel->enableOutline(Color4B::BLACK, 2);
	manageDeckLabelHover->enableOutline(Color4B::BLACK, 2);
	manageDeckLabelClick->enableOutline(Color4B::BLACK, 2);

	this->deckManagementButton = TextMenuSprite::create(
		manageDeckLabel,
		manageDeckLabelHover,
		manageDeckLabelClick,
		Resources::Menus_Buttons_GenericButton,
		Resources::Menus_Buttons_GenericButtonHover,
		Resources::Menus_Buttons_GenericButtonClick
	);

	this->opponentSelectLabel->enableOutline(Color4B::BLACK, 2);

	this->addChild(this->background);
	this->addChild(this->scrollPane);
	this->addChild(this->opponentSelectLabel);
	this->addChild(this->deckManagementButton);
	this->addChild(Mouse::create());
}

HexusOpponentMenuBase::~HexusOpponentMenuBase()
{
}

void HexusOpponentMenuBase::onEnter()
{
	FadeScene::onEnter();

	float delay = 0.25f;
	float duration = 0.35f;

	GameUtils::fadeInObject(this->scrollPane, delay, duration);

	// Just assume linear dependencies for now
	this->dependencies.clear();
	std::vector<HexusOpponentPreview*>::iterator prevIt;

	for (auto it = this->opponents.begin(); it != this->opponents.end(); prevIt = it, it++)
	{
		if (*it == this->opponents.front())
		{
			this->dependencies.emplace((*it), nullptr);
		}
		else
		{
			this->dependencies.emplace((*it), (*prevIt));
		}
	}

	for (auto it = this->opponents.begin(); it != this->opponents.end(); it++)
	{
		(*it)->disableInteraction();
	}

	this->loadProgress();
}

void HexusOpponentMenuBase::initializePositions()
{
	FadeScene::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->background->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->scrollPane->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 64.0f));

	Size scrollPaneSize = this->scrollPane->getPaneSize();

	int index = 0;

	for (std::vector<HexusOpponentPreview*>::iterator it = this->opponents.begin(); it != this->opponents.end(); ++it)
	{
		int x = index % 3;
		int y = (this->opponents.size() - 1 - index + (3 - this->opponents.size() % 3)) / 3 - (this->opponents.size() % 3 == 0 ? 1 : 0);

		(*it)->setPosition(Vec2(scrollPaneSize.width / 2.0f - 496.0f + 496.0f * x, y * 480.0f + 240.0f));

		index++;
	}

	this->scrollPane->fitSizeToContent();
	this->deckManagementButton->setPosition(Vec2(visibleSize.width / 2.0f + 756.0f, visibleSize.height - 64.0f));
	this->opponentSelectLabel->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height - 64.0f));
}

void HexusOpponentMenuBase::initializeListeners()
{
	FadeScene::initializeListeners();

	EventListenerKeyboard* keyboardListener = EventListenerKeyboard::create();

	keyboardListener->onKeyPressed = CC_CALLBACK_2(HexusOpponentMenuBase::onKeyPressed, this);
	this->deckManagementButton->setClickCallback(CC_CALLBACK_1(HexusOpponentMenuBase::onDeckManagementClick, this));

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);
}

void HexusOpponentMenuBase::onMouseOver(HexusOpponentPreview* opponent)
{
}

void HexusOpponentMenuBase::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
		case EventKeyboard::KeyCode::KEY_ESCAPE:
			event->stopPropagation();
			NavigationEvents::navigateBack();
			break;
		default:
			break;
	}
}

void HexusOpponentMenuBase::onCloseClick(MenuSprite* menuSprite)
{
	NavigationEvents::navigateBack();
}

void HexusOpponentMenuBase::onDeckManagementClick(MenuSprite* menuSprite)
{
	NavigationEvents::navigate(NavigationEvents::GameScreen::Minigames_Hexus_Deck_Management);
}

void HexusOpponentMenuBase::onGameEndCallback(HexusEvents::HexusGameResultEventArgs args)
{
	if (args.playerWon)
	{
		std::string key = HexusOpponentMenuBase::winsPrefix + args.opponentData->enemyNameKey;
		int wins = SaveManager::hasGlobalData(key) ? SaveManager::getGlobalData(key).asInt() + 1 : 1;

		if (args.opponentData == this->opponents.back()->hexusOpponentData)
		{
			SaveManager::saveGlobalData(this->chapterProgressSaveKey, cocos2d::Value(true));
		}

		SaveManager::saveGlobalData(key, cocos2d::Value(wins));
	}
}

void HexusOpponentMenuBase::loadProgress()
{
	for (auto it = this->dependencies.begin(); it != this->dependencies.end(); it++)
	{
		HexusOpponentPreview* opponent = (*it).first;
		HexusOpponentPreview* dependsOn = (*it).second;

		if (dependsOn == nullptr)
		{
			opponent->enableInteraction();
			continue;
		}

		std::string dependencyKey = HexusOpponentMenuBase::winsPrefix + dependsOn->hexusOpponentData->enemyNameKey;

		int wins = SaveManager::hasGlobalData(dependencyKey) ? SaveManager::getGlobalData(dependencyKey).asInt() : 0;

		if (wins > 0)
		{
			opponent->enableInteraction();
		}
	}
}
