#pragma once

#include "Scenes/Cipher/Components/Tutorials/CipherTutorialBase.h"

class FocusTakeOver;
class HelpArrow;
class LocalizedLabel;
class ClickableTextNode;

class CipherAdditionTutorial : public CipherTutorialBase
{
public:
	static CipherAdditionTutorial* create();

	static const std::string MapKeyTutorial;

protected:
	void onBeforeStateChange(CipherState* cipherState) override;
	void onAnyStateChange(CipherState* cipherState) override;

private:
	typedef CipherTutorialBase super;
	CipherAdditionTutorial();
	virtual ~CipherAdditionTutorial();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void initializeCallbacks(CipherState* cipherState);
	bool tryHijackState(CipherState* cipherState) override;
	void unHijackState(CipherState* cipherState) override;

	void runTutorialPartA(CipherState* cipherState);
	void runTutorialPartB(CipherState* cipherState);
	void runTutorialPartC(CipherState* cipherState);

	FocusTakeOver* focusTakeOver;
	LocalizedLabel* introLabel;
	LocalizedLabel* buttonsLabel;
	LocalizedLabel* connectLabel;
	ClickableTextNode* nextButtonIntro;
	ClickableTextNode* nextButtonButtons;
	ClickableTextNode* nextButtonConnect;
};
