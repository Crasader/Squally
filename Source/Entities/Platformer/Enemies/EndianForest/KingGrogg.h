////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class KingGrogg : public PlatformerEnemy
{
public:
	static KingGrogg* deserialize(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyKingGrogg;

private:
	KingGrogg(cocos2d::ValueMap* initProperties);
	~KingGrogg();
};