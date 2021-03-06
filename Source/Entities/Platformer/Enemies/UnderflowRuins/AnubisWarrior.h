#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class AnubisWarrior : public PlatformerEnemy
{
public:
	static AnubisWarrior* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyAnubisWarrior;

private:
	typedef PlatformerEnemy super;
	AnubisWarrior(cocos2d::ValueMap& properties);
	~AnubisWarrior();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
