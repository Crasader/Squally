#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class HexusOpponentData;
class LocalizedString;

class VoidDemon : public PlatformerEnemy
{
public:
	static VoidDemon* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKeyVoidDemon;

private:
	typedef PlatformerEnemy super;
	VoidDemon(cocos2d::ValueMap& properties);
	~VoidDemon();

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
