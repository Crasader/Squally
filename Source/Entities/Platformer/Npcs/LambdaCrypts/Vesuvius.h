#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class Vesuvius : public PlatformerFriendly
{
public:
	static Vesuvius* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyVesuvius;

private:
	typedef PlatformerFriendly super;
	Vesuvius(cocos2d::ValueMap& properties);
	~Vesuvius();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
