#include "FocusTakeOver.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCLayer.h"
#include "cocos/2d/CCNode.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/Events/SceneEvents.h"
#include "Engine/Utils/GameUtils.h"

using namespace cocos2d;

FocusTakeOver * FocusTakeOver::create()
{
	FocusTakeOver* instance = new FocusTakeOver();

	instance->autorelease();

	return instance;
}

FocusTakeOver::FocusTakeOver()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->hijackedNodes = std::map<Node*, std::tuple<Node*, int>>();
	this->focusBackground = LayerColor::create(Color4B::BLACK, visibleSize.width, visibleSize.height);

	this->addChild(this->focusBackground);
}

FocusTakeOver::~FocusTakeOver()
{
}

void FocusTakeOver::onEnter()
{
	super::onEnter();

	this->focusBackground->setOpacity(0);
}

void FocusTakeOver::initializeListeners()
{
	super::initializeListeners();

	EventListenerCustom* beforeSceneChangeListener = EventListenerCustom::create(
		SceneEvents::EventBeforeSceneChange,
		[=](EventCustom* EventCustom)
		{
			// Important to restore any hijacked nodes before scene changes
			this->unfocus();
		}
	);

	this->addEventListenerIgnorePause(beforeSceneChangeListener);
}

void FocusTakeOver::focus(std::vector<Node*> nodes)
{
	this->unfocus(false);

	for (auto it = nodes.begin(); it != nodes.end(); it++)
	{
		Node* parent = (*it)->getParent();
		
		cocos2d::Vector<Node*> children = parent->getChildren();
		int childIndex = 0;
		auto search = std::find(children.begin(), children.end(), *it);

		if (search != children.end())
		{
			childIndex = std::distance(children.begin(), search);
		}

		this->hijackedNodes[*it] = std::tuple<Node*, int>(parent, childIndex);

		GameUtils::changeParent(*it, this, true);
	}

	this->focusBackground->runAction(FadeTo::create(0.25f, 196));
}

void FocusTakeOver::unfocus(bool fadeOut)
{
	for (auto it = this->hijackedNodes.begin(); it != this->hijackedNodes.end(); it++)
	{
		Node* node = (*it).first;
		Node* parent = std::get<0>((*it).second);
		int childIndex = std::get<1>((*it).second);

		GameUtils::changeParent(node, parent, true, true, childIndex);
	}

	this->hijackedNodes.clear();

	if (fadeOut)
	{
		this->focusBackground->runAction(FadeTo::create(0.25f, 0));
	}
}
