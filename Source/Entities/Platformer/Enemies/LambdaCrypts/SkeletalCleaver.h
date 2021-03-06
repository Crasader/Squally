#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class SkeletalCleaver : public PlatformerEnemy
{
public:
	static SkeletalCleaver* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeySkeletalCleaver;

private:
	typedef PlatformerEnemy super;
	SkeletalCleaver(cocos2d::ValueMap& properties);
	~SkeletalCleaver();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
