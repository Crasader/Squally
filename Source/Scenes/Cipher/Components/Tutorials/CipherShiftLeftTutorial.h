#pragma once

#include "Scenes/Cipher/Components/Tutorials/CipherTutorialBase.h"

class FocusTakeOver;
class HelpArrow;
class LocalizedLabel;
class ClickableTextNode;

class CipherShiftLeftTutorial : public CipherTutorialBase
{
public:
	static CipherShiftLeftTutorial* create();

	static const std::string MapKeyTutorial;

protected:
	void onBeforeStateChange(CipherState* cipherState) override;
	void onAnyStateChange(CipherState* cipherState) override;

private:
	typedef CipherTutorialBase super;
	CipherShiftLeftTutorial();
	virtual ~CipherShiftLeftTutorial();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void initializeCallbacks(CipherState* cipherState);
	bool tryHijackState(CipherState* cipherState) override;
	void unHijackState(CipherState* cipherState) override;

	void runTutorialPartA(CipherState* cipherState);
	void runTutorialPartB(CipherState* cipherState);

	FocusTakeOver* focusTakeOver;
	LocalizedLabel* introLabel;
	LocalizedLabel* connectLabel;
	ClickableTextNode* nextButtonIntro;
	ClickableTextNode* nextButtonConnect;
};
