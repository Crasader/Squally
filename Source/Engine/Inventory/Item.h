#pragma once

#include "Engine/SmartNode.h"

namespace cocos2d
{
	class Value;
	typedef std::map<std::string, Value> ValueMap;
}

class LocalizedString;

class Item : public SmartNode
{
public:
	virtual Item* clone() = 0;
	virtual LocalizedString* getString() = 0;
	virtual std::string getIconResource() = 0;
	virtual std::string getSerializationKey() = 0;
	virtual cocos2d::ValueMap serialize();

protected:
	Item();
	virtual ~Item();
	void onEnter() override;
	void initializeListeners() override;

private:
	typedef SmartNode super;
};