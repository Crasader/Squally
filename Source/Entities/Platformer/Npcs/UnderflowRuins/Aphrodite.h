#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Aphrodite : public PlatformerFriendly
{
public:
	static Aphrodite* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyAphrodite;

private:
	typedef PlatformerFriendly super;
	Aphrodite(cocos2d::ValueMap& properties);
	~Aphrodite();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
