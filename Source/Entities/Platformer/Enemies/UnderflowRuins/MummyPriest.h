#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class MummyPriest : public PlatformerEnemy
{
public:
	static MummyPriest* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyMummyPriest;

private:
	typedef PlatformerEnemy super;
	MummyPriest(cocos2d::ValueMap& properties);
	~MummyPriest();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
