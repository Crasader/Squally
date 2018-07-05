#pragma once
#include "cocos2d.h"

#include "Engine/Maps/IObjectDeserializer.h"
#include "Engine/Utils/GameUtils.h"
#include "Objects/DecorObject.h"
#include "Resources.h"

#include "ObjectDeserializer.h"

using namespace cocos2d;

class DecorDeserializer : public IObjectDeserializer
{
public:
	void onDeserializationRequest(ObjectDeserializationRequestArgs* args) override;

	static const std::string KeyTypeDecor;
};
