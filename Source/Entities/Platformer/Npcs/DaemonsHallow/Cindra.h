////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

#include "Entities/Platformer/NpcBase.h"

class Cindra : public NpcBase
{
public:
	static Cindra* deserialize(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyCindra;

private:
	Cindra(cocos2d::ValueMap* initProperties);
	~Cindra();
};