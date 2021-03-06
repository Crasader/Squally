#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class SkeletalPirate : public PlatformerEnemy
{
public:
	static SkeletalPirate* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeySkeletalPirate;

private:
	typedef PlatformerEnemy super;
	SkeletalPirate(cocos2d::ValueMap& properties);
	~SkeletalPirate();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
