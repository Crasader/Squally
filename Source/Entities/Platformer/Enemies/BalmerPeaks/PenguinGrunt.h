#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class PenguinGrunt : public PlatformerEnemy
{
public:
	static PenguinGrunt* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyPenguinGrunt;

private:
	typedef PlatformerEnemy super;
	PenguinGrunt(cocos2d::ValueMap& properties);
	~PenguinGrunt();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
