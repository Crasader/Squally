#include "MarcelTutorialIntroSequence.h"

#include <vector>

#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableTextNode.h"
#include "Engine/Localization/LocalizedLabel.h"
#include "Engine/UI/Controls/HelpArrow.h"
#include "Engine/UI/HUD/FocusTakeOver.h"
#include "Scenes/Hexus/Config.h"
#include "Scenes/Hexus/StateOverride.h"

#include "Resources/UIResources.h"

#include "Strings/Hexus/Tutorials/Marcel/RealMatch.h"
#include "Strings/Menus/GotIt.h"

using namespace cocos2d;

MarcelTutorialIntroSequence* MarcelTutorialIntroSequence::create()
{
	MarcelTutorialIntroSequence* instance = new MarcelTutorialIntroSequence();

	instance->autorelease();

	return instance;
}

MarcelTutorialIntroSequence::MarcelTutorialIntroSequence() : super(GameState::StateType::RoundStart)
{
	this->focusTakeOver = FocusTakeOver::create();
	this->lossDisplayTutorialLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::P, Strings::Hexus_Tutorials_Marcel_RealMatch::create(), Size(420.0f, 0.0f));
	this->helpArrowLossDisplay = HelpArrow::create();

	LocalizedLabel* lossesDisplayNextLabel = LocalizedLabel::create(LocalizedLabel::FontStyle::Main, LocalizedLabel::FontSize::H3, Strings::Menus_GotIt::create());
	LocalizedLabel* lossesDisplayNextLabelSelected = lossesDisplayNextLabel->clone();

	lossesDisplayNextLabel->enableOutline(Color4B::BLACK, 2);
	lossesDisplayNextLabelSelected->enableOutline(Color4B::BLACK, 2);

	this->lossDisplayNextButton = ClickableTextNode::create(lossesDisplayNextLabel, lossesDisplayNextLabelSelected, Sprite::create(UIResources::Menus_Buttons_WoodButton), Sprite::create(UIResources::Menus_Buttons_WoodButtonSelected));

	this->lossDisplayTutorialLabel->enableOutline(Color4B::BLACK, 2);
	this->lossDisplayTutorialLabel->setAnchorPoint(Vec2(0.5f, 0.0f));

	this->helpArrowLossDisplay->setRotation(0.0f);

	this->addChild(this->focusTakeOver);
	this->addChild(this->lossDisplayTutorialLabel);
	this->addChild(this->lossDisplayNextButton);
	this->addChild(this->helpArrowLossDisplay);
}

MarcelTutorialIntroSequence::~MarcelTutorialIntroSequence()
{
}

void MarcelTutorialIntroSequence::onEnter()
{
	super::onEnter();

	this->lossDisplayTutorialLabel->setOpacity(0);
	this->lossDisplayNextButton->disableInteraction(0);
}

void MarcelTutorialIntroSequence::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->lossDisplayTutorialLabel->setPosition(visibleSize.width / 2.0f - 420.0f, visibleSize.height / 2.0f + 32.0f);
	this->lossDisplayNextButton->setPosition(visibleSize.width / 2.0f - 420.0f, visibleSize.height / 2.0f - 32.0f);
	this->helpArrowLossDisplay->setPosition(Vec2(visibleSize.width / 2.0f + Config::leftColumnCenter + (Config::socketAOffsetX + Config::socketBOffsetX) / 2.0f, visibleSize.height / 2.0f + Config::socketOffsetY + 128.0f));
}

void MarcelTutorialIntroSequence::initializeListeners()
{
	super::initializeListeners();
}

bool MarcelTutorialIntroSequence::tryHijackState(GameState* gameState)
{
	this->initializeCallbacks(gameState);
	this->runTutorialLossDisplay(gameState);

	return true;
}

void MarcelTutorialIntroSequence::onBeforeStateChange(GameState* gameState)
{
	super::onBeforeStateChange(gameState);
}

void MarcelTutorialIntroSequence::onAnyStateChange(GameState* gameState)
{
	super::onAnyStateChange(gameState);
}

void MarcelTutorialIntroSequence::initializeCallbacks(GameState* gameState)
{
	this->lossDisplayNextButton->setMouseClickCallback([=](InputEvents::MouseEventArgs* args)
	{
		this->tryUnHijackState(gameState);
	});
}

void MarcelTutorialIntroSequence::runTutorialLossDisplay(GameState* gameState)
{
	this->lossDisplayNextButton->enableInteraction(0);
	this->lossDisplayNextButton->runAction(FadeTo::create(0.25f, 255));
	this->lossDisplayTutorialLabel->runAction(FadeTo::create(0.25f, 255));
	this->helpArrowLossDisplay->showPointer();

	std::vector<Node*> focusTargets = std::vector<Node*>();
	focusTargets.push_back(gameState->lossesDisplayPointer);
	this->focusTakeOver->focus(focusTargets);
}

void MarcelTutorialIntroSequence::unHijackState(GameState* gameState)
{
	this->lossDisplayNextButton->disableInteraction();
	this->lossDisplayNextButton->runAction(FadeTo::create(0.25f, 0));
	this->lossDisplayTutorialLabel->runAction(FadeTo::create(0.25f, 0));
	this->helpArrowLossDisplay->hidePointer();
	this->focusTakeOver->unfocus();
}