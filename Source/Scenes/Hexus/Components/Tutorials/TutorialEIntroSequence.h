#pragma once

#include "Scenes/Hexus/Components/Tutorials/TutorialBase.h"

class FocusTakeOver;
class HelpArrow;
class LocalizedLabel;
class ClickableTextNode;

class TutorialEIntroSequence : public TutorialBase
{
public:
	static TutorialEIntroSequence* create();

protected:
	void onBeforeStateChange(GameState* gameState) override;
	void onAnyStateChange(GameState* gameState) override;

private:
	typedef TutorialBase super;
	TutorialEIntroSequence();
	~TutorialEIntroSequence();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void initializeCallbacks(GameState* gameState);
	bool tryHijackState(GameState* gameState) override;
	void unHijackState(GameState* gameState) override;
	void runTutorialHandCards(GameState* gameState);

	FocusTakeOver* focusTakeOver;
	LocalizedLabel* handCardsTutorialLabel;
	ClickableTextNode* handCardsNextButton;
	HelpArrow* helpArrowHandCards;
};
