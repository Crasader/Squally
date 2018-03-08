#include "Hexium.h"

const std::string Hexium::HexiumGameStartEvent = "hexium_game_start_event";
const std::string Hexium::HexiumGameEndEvent = "hexium_game_end_event";

Hexium* Hexium::create()
{
	Hexium* hexium = new Hexium();

	hexium->autorelease();

	return hexium;
}

Hexium::Hexium()
{
	this->gameBackground = Sprite::create(Resources::Minigames_Hexium_Gameboard);
	this->gameState = GameState::create();
	this->avatars = Avatars::create();
	this->banners = Banners::create();
	this->cardPreview = CardPreview::create();
	this->controlDraw = ControlDraw::create();
	this->coinFlip = CoinFlip::create();
	this->deckCardCountDisplay = DeckCardCountDisplay::create();
	this->handCardCountDisplay = HandCardCountDisplay::create();
	this->lossesDisplay = LossesDisplay::create();
	this->rowTotals = RowTotals::create();
	this->scoreTotal = ScoreTotal::create();

	this->addChild(this->gameBackground);
	this->addChild(this->gameState);
	this->addChild(this->avatars);
	this->addChild(this->cardPreview);
	this->addChild(this->controlDraw);
	this->addChild(this->lossesDisplay);
	this->addChild(this->deckCardCountDisplay);
	this->addChild(this->handCardCountDisplay);
	this->addChild(this->rowTotals);
	this->addChild(this->scoreTotal);
	this->addChild(this->coinFlip);
	this->addChild(this->banners);
}

Hexium::~Hexium()
{
}

void Hexium::onEnter()
{
	FadeScene::onEnter();

	this->initializePositions();
	this->initializeListeners();
	this->addChild(Mouse::claimInstance());

	GameState::updateState(this->gameState, GameState::StateType::DrawInitialCards);
}

void Hexium::initializePositions()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->gameBackground->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
}

void Hexium::initializeListeners()
{
	EventListenerKeyboard* listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(Hexium::onKeyPressed, this);
	/*this->gameState->setCardPreviewCallback(CC_CALLBACK_1(Hexium::previewCard, this));
	this->gameState->setUpdateStateCallback(CC_CALLBACK_1(Hexium::updateDisplayState, this));
	this->gameState->setEndTurnCallback(CC_CALLBACK_0(Hexium::displayTurnBanner, this));
	this->gameState->setRequestAiCallback(Ai::performAiActions);*/

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void Hexium::onGameStart(EventCustom* eventCustom)
{
	Hexium::HexiumGameEventArgs* args = (Hexium::HexiumGameEventArgs*)(eventCustom->getUserData());

	args->playerDeck->copyTo(this->gameState->playerDeck);
	args->enemyDeck->copyTo(this->gameState->enemyDeck);

	GameUtils::navigate(GameUtils::GameScreen::Hexium);
}

void Hexium::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (!this->isRunning() || !this->isVisible())
	{
		return;
	}

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_ESCAPE:
		//this->gameState->cancelCurrentAction(true);
		break;
	}
}

void Hexium::onClose(MenuSprite* menuSprite)
{
	GameUtils::navigateBack();
}

/*
GameState::GameState()
{
this->stagedSacrifice = nullptr;
this->selectedCard = nullptr;
this->updateStateCallback = nullptr;
this->endTurnCallback = nullptr;
this->cardPreviewCallback = nullptr;
this->requestAiCallback = nullptr;
}

GameState::~GameState()
{
}

void GameState::onEnter()
{
Node::onEnter();

this->initializePositions();
this->initializeListeners();
}


void GameState::initializeListeners()
{
this->playerHand->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));
this->enemyHand->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));

this->playerBinaryCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));
this->playerDecimalCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));
this->playerHexCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));

this->enemyBinaryCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));
this->enemyDecimalCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));
this->enemyHexCards->setMouseOverCallback(CC_CALLBACK_1(GameState::onCardMouseOver, this));

this->playerHand->setMouseClickCallback(CC_CALLBACK_1(GameState::onHandCardClick, this));
this->enemyHand->setMouseClickCallback(CC_CALLBACK_1(GameState::onHandCardClick, this));

this->playerBinaryCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));
this->playerDecimalCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));
this->playerHexCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));

this->enemyBinaryCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));
this->enemyDecimalCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));
this->enemyHexCards->setMouseClickCallback(CC_CALLBACK_1(GameState::onRowCardClick, this));
}


void GameState::onCardMouseOver(Card* card)
{
if (this->cardPreviewCallback != nullptr)
{
this->cardPreviewCallback(card);
}
}

void GameState::onHandCardClick(Card* card)
{
if (card != this->selectedCard)
{
this->selectCard(card);
}
else
{
this->cancelCurrentAction(true);
}
}

void GameState::selectCard(Card* card)
{
if (this->selectedCard != nullptr)
{
this->cancelCurrentAction(false);
this->selectedCard->stopAllActions();
this->selectedCard->runAction(MoveTo::create(Config::cardSelectSpeed, this->selectedCard->position));
}

this->selectedCard = card;

if (this->selectedCard == nullptr)
{
return;
}

this->selectedCard->stopAllActions();
this->selectedCard->runAction(MoveTo::create(Config::cardSelectSpeed, this->selectedCard->position + Vec2(0.0f, Config::cardSelectOffsetY)));

switch (this->selectedCard->cardData->cardType)
{
case CardData::CardType::Binary:
this->playerBinaryCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
break;
case CardData::CardType::Decimal:
this->playerDecimalCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
break;
case CardData::CardType::Hexidecimal:
this->playerHexCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
break;
case CardData::CardType::Special_SHL:
case CardData::CardType::Special_SHR:
case CardData::CardType::Special_FLIP1:
case CardData::CardType::Special_FLIP2:
case CardData::CardType::Special_FLIP3:
case CardData::CardType::Special_FLIP4:
case CardData::CardType::Special_INV:
this->playerBinaryCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
this->playerDecimalCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
this->playerHexCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
this->enemyBinaryCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
this->enemyDecimalCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
this->enemyHexCards->enableRowSelection(CC_CALLBACK_1(GameState::playSelectedCard, this));
break;
case CardData::CardType::Special_AND:
case CardData::CardType::Special_OR:
case CardData::CardType::Special_XOR:
case CardData::CardType::Special_ADD:
case CardData::CardType::Special_SUB:
case CardData::CardType::Special:
this->playerBinaryCards->enableRowCardSelection(CC_CALLBACK_1(GameState::stageSelectedSacrificeCard, this));
this->playerDecimalCards->enableRowCardSelection(CC_CALLBACK_1(GameState::stageSelectedSacrificeCard, this));
this->playerHexCards->enableRowCardSelection(CC_CALLBACK_1(GameState::stageSelectedSacrificeCard, this));
break;
}
}

void GameState::cancelCurrentAction(bool clearSelectedCard)
{
if (this->selectedCard != nullptr)
{
switch (this->selectedCard->cardData->cardType)
{
case CardData::CardType::Binary:
this->playerBinaryCards->disableRowSelection();
break;
case CardData::CardType::Decimal:
this->playerDecimalCards->disableRowSelection();
break;
case CardData::CardType::Hexidecimal:
this->playerHexCards->disableRowSelection();
break;
case CardData::CardType::Special_SHL:
case CardData::CardType::Special_SHR:
case CardData::CardType::Special_FLIP1:
case CardData::CardType::Special_FLIP2:
case CardData::CardType::Special_FLIP3:
case CardData::CardType::Special_FLIP4:
case CardData::CardType::Special_INV:
this->playerBinaryCards->disableRowSelection();
this->playerDecimalCards->disableRowSelection();
this->playerHexCards->disableRowSelection();
this->enemyBinaryCards->disableRowSelection();
this->enemyDecimalCards->disableRowSelection();
this->enemyHexCards->disableRowSelection();
break;
case CardData::CardType::Special_AND:
case CardData::CardType::Special_OR:
case CardData::CardType::Special_XOR:
case CardData::CardType::Special_ADD:
case CardData::CardType::Special_SUB:
case CardData::CardType::Special:
this->playerBinaryCards->disableRowSelection();
this->playerDecimalCards->disableRowSelection();
this->playerHexCards->disableRowSelection();
break;
}

if (clearSelectedCard)
{
this->selectCard(nullptr);
}
}
}

void GameState::onRowCardClick(Card* card)
{
// TODO: potentially store up xor/and/or targets if one is queued up
}

void GameState::playSelectedCard(CardRow* cardRow)
{
if (this->selectedCard == nullptr)
{
return;
}

switch (this->selectedCard->cardData->cardType) {
case CardData::CardType::Binary:
this->playerHand->removeCard(this->selectedCard);
this->playerBinaryCards->disableRowSelection();
this->playerBinaryCards->insertCard(this->selectedCard, Config::insertDelay);
this->endTurn();
break;
case CardData::CardType::Decimal:
this->playerHand->removeCard(this->selectedCard);
this->playerDecimalCards->disableRowSelection();
this->playerDecimalCards->insertCard(this->selectedCard, Config::insertDelay);
this->endTurn();
break;
case CardData::CardType::Hexidecimal:
this->playerHand->removeCard(this->selectedCard);
this->playerHexCards->disableRowSelection();
this->playerHexCards->insertCard(this->selectedCard, Config::insertDelay);
this->endTurn();
break;
case CardData::CardType::Special_SHL:
case CardData::CardType::Special_SHR:
case CardData::CardType::Special_FLIP1:
case CardData::CardType::Special_FLIP2:
case CardData::CardType::Special_FLIP3:
case CardData::CardType::Special_FLIP4:
case CardData::CardType::Special_INV:
this->playerHand->removeCard(this->selectedCard);
this->selectedCard->disableInteraction();
this->playerGraveyard->insertCardTop(this->selectedCard, true, Config::insertDelay);

Card::Operation operation = Card::toOperation(this->selectedCard->cardData->cardType, 0);

for (auto it = cardRow->rowCards->begin(); it != cardRow->rowCards->end(); it++)
{
Card* card = *it;

card->addOperation(operation);
}

this->playerBinaryCards->disableRowSelection();
this->playerDecimalCards->disableRowSelection();
this->playerHexCards->disableRowSelection();
this->enemyBinaryCards->disableRowSelection();
this->enemyDecimalCards->disableRowSelection();
this->enemyHexCards->disableRowSelection();
this->endTurn();
break;
}

this->selectedCard = nullptr;
}

void GameState::stageSelectedSacrificeCard(Card* card)
{
if (this->selectedCard == nullptr)
{
return;
}

switch (this->selectedCard->cardData->cardType) {
case CardData::CardType::Special_AND:
case CardData::CardType::Special_OR:
case CardData::CardType::Special_XOR:
case CardData::CardType::Special_ADD:
case CardData::CardType::Special_SUB:
this->stagedSacrifice = card;
this->playerHand->removeCard(this->selectedCard);
this->selectedCard->disableInteraction();
this->playerGraveyard->insertCardTop(this->selectedCard, true, Config::insertDelay);

Card::Operation operation = Card::toOperation(this->selectedCard->cardData->cardType, 0);

for (auto it = cardRow->rowCards->begin(); it != cardRow->rowCards->end(); it++)
{
Card* card = *it;

card->addOperation(operation);
}

this->playerBinaryCards->disableRowSelection();
this->playerDecimalCards->disableRowSelection();
this->playerHexCards->disableRowSelection();
this->enemyBinaryCards->disableRowSelection();
this->enemyDecimalCards->disableRowSelection();
this->enemyHexCards->disableRowSelection();
this->endTurn();
break;
}

this->selectedCard = nullptr;
}

void GameState::gameStart(Deck* startPlayerDeck, Deck* startEnemyDeck)
{
this->playerLosses = 0;
this->enemyLosses = 0;

this->playerGraveyard->clear();
this->enemyGraveyard->clear();
this->playerHand->clear();
this->enemyHand->clear();
this->playerDeck->clear();
this->enemyDeck->clear();

startPlayerDeck->copyTo(this->playerDeck);
startEnemyDeck->copyTo(this->enemyDeck);


this->disableUserInteraction();
this->randomizeTurn();
}

void GameState::giveControl()
{
switch (this->turn)
{
case Turn::Enemy:
if (this->requestAiCallback != nullptr) {
this->requestAiCallback(this);
}
break;
case Turn::Player:
default:
this->enableUserInteraction();
break;
}
}

void GameState::endTurn()
{
float endTurnDelay = Config::endTurnDelay;

switch (this->turn)
{
case Turn::Enemy:
endTurnDelay = Config::enemyEndTurnDelay;
this->turn = Turn::Player;
break;
case Turn::Player:
default:
this->disableUserInteraction();
this->turn = Turn::Enemy;
break;
}

this->runAction(Sequence::create(
CallFunc::create(CC_CALLBACK_0(GameState::updateState, this)),
DelayTime::create(endTurnDelay),
CallFunc::create(CC_CALLBACK_0(GameState::callEndTurn, this)),
DelayTime::create(Config::betweenTurnDelay),
CallFunc::create(CC_CALLBACK_0(GameState::drawCard, this)),
nullptr
));
}

void GameState::updateState()
{
if (this->updateStateCallback != nullptr)
{
this->updateStateCallback(true);
}
}

void GameState::callEndTurn()
{
if (this->endTurnCallback != nullptr)
{
this->endTurnCallback();
}
}

void GameState::setCardPreviewCallback(std::function<void(Card*)> callback)
{
this->cardPreviewCallback = callback;
}

void GameState::setUpdateStateCallback(std::function<void(bool)> callback)
{
this->updateStateCallback = callback;
}

void GameState::setEndTurnCallback(std::function<void()> callback)
{
this->endTurnCallback = callback;
}

void GameState::setRequestAiCallback(std::function<void(GameState*)> callback)
{
this->requestAiCallback = callback;
}

void GameState::enableUserInteraction()
{
this->playerHand->enableInteraction();
this->playerBinaryCards->enableInteraction();
this->playerDecimalCards->enableInteraction();
this->playerHexCards->enableInteraction();
this->enemyBinaryCards->enableInteraction();
this->enemyDecimalCards->enableInteraction();
this->enemyHexCards->enableInteraction();
}

void GameState::disableUserInteraction()
{
this->playerHand->disableInteraction();
this->playerBinaryCards->disableInteraction();
this->playerDecimalCards->disableInteraction();
this->playerHexCards->disableInteraction();
this->enemyBinaryCards->disableInteraction();
this->enemyDecimalCards->disableInteraction();
this->enemyHexCards->disableInteraction();
}

*/