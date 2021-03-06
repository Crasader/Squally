#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class BoneFiend : public PlatformerEnemy
{
public:
	static BoneFiend* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyBoneFiend;

private:
	typedef PlatformerEnemy super;
	BoneFiend(cocos2d::ValueMap& properties);
	~BoneFiend();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
