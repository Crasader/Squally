#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Leroy : public PlatformerFriendly
{
public:
	static Leroy* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyLeroy;

private:
	typedef PlatformerFriendly super;
	Leroy(cocos2d::ValueMap& properties);
	~Leroy();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
