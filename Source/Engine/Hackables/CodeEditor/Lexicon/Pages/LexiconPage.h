#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class DrawNode;
}

class ClickableNode;
class ClickableTextNode;
class LocalizedLabel;
class LocalizedString;

class LexiconPage : public SmartNode
{
public:
	enum class PageType
	{
		Left,
		Right,
		Full
	};

	PageType getPageType();

	static const cocos2d::Size TotalPageSize;
	static const cocos2d::Size PageMargin;
	static const cocos2d::Size PageSize;
	static const cocos2d::Vec2 PageOffset;
	static const cocos2d::Vec2 FullPageSecondOffset;
	static const cocos2d::Vec2 ChapterMarkerLocation;
	static const cocos2d::Vec2 ChapterLocation;
	static const cocos2d::Vec2 IntroLocation;
	static const cocos2d::Vec2 BackButtonLocation;
	static const cocos2d::Color4B TextColor;
	static const cocos2d::Color4B TextColorChanged;

protected:
	LexiconPage(std::string pageIdentifier, PageType pageType);
	~LexiconPage();
	
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void onDeveloperModeEnable(int debugLevel) override;
	void onDeveloperModeDisable() override;
	void enableBack(std::string backPage, bool closeExisting = true);
	void enableBack(std::string backPageLeft, std::string backPageRight);
	ClickableTextNode* buildInstructionLabel(LocalizedString* instructionStr, std::string instructionIdentifier);
	ClickableTextNode* buildInstructionLabel(LocalizedString* instructionStr, std::string instructionIdentifierA, std::string instructionIdentifierB);
	ClickableTextNode* buildExecuteButton();
	ClickableTextNode* buildResetButton();
	LocalizedString* pointerizeString(LocalizedString* memRegString);
	LocalizedString* offsetString(LocalizedString* memRegString, int offset);
	LocalizedLabel* createInstructionLabelSingle(LocalizedString* instructionString, LocalizedString* memRegString);
	LocalizedLabel* createInstructionLabelDouble(LocalizedString* instructionString, LocalizedString* memRegStringA, LocalizedString* memRegStringB);

private:
	typedef SmartNode super;

	ClickableNode* backButton;
	cocos2d::DrawNode* debugDrawNode;

	std::string pageIdentifier;
	PageType pageType;
};
