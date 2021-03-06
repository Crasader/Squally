#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Atreus : public PlatformerFriendly
{
public:
	static Atreus* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyAtreus;

private:
	typedef PlatformerFriendly super;
	Atreus(cocos2d::ValueMap& properties);
	~Atreus();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
