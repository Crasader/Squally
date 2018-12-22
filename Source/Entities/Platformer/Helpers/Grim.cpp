////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "Grim.h"

#include "Resources/EntityResources.h"

const std::string Grim::MapKeyGrim = "grim";

Grim* Grim::deserialize(cocos2d::ValueMap* initProperties)
{
	Grim* instance = new Grim(initProperties);

	instance->autorelease();

	return instance;
}

Grim::Grim(cocos2d::ValueMap* initProperties) : PlatformerEntity(initProperties,
	EntityResources::Helpers_Grim_Animations,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(224.0f, 440.0f),
	0.3f,
	cocos2d::Vec2(0.0f, -220.0f))
{
}

Grim::~Grim()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////
