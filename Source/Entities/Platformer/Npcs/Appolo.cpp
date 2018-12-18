////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////
#include "Appolo.h"

#include "Resources/EntityResources.h"

const std::string Appolo::MapKeyAppolo = "appolo";

Appolo* Appolo::deserialize(cocos2d::ValueMap* initProperties)
{
	Appolo* instance = new Appolo(initProperties);

	instance->autorelease();

	return instance;
}

Appolo::Appolo(cocos2d::ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_Appolo_Animations,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(472.0f, 780.0f),
	0.3f,
	cocos2d::Vec2(-24.0f, -390.0f))
{
}

Appolo::~Appolo()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////
