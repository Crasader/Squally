////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>

#include "Entities/Platformer/PlatformerEnemy.h"

class VoidDemon : public PlatformerEnemy
{
public:
	static VoidDemon* deserialize(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyVoidDemon;

private:
	VoidDemon(cocos2d::ValueMap* initProperties);
	~VoidDemon();
};
