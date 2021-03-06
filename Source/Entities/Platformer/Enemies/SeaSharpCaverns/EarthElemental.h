#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class EarthElemental : public PlatformerEnemy
{
public:
	static EarthElemental* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyEarthElemental;

private:
	typedef PlatformerEnemy super;
	EarthElemental(cocos2d::ValueMap& properties);
	~EarthElemental();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
