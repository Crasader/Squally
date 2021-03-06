#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class PrincessPepper : public PlatformerFriendly
{
public:
	static PrincessPepper* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyPrincessPepper;

private:
	typedef PlatformerFriendly super;
	PrincessPepper(cocos2d::ValueMap& properties);
	~PrincessPepper();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
