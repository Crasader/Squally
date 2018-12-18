////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////
#include "Tyracius.h"

#include "Resources/EntityResources.h"

const std::string Tyracius::MapKeyTyracius = "tyracius";

Tyracius* Tyracius::deserialize(cocos2d::ValueMap* initProperties)
{
	Tyracius* instance = new Tyracius(initProperties);

	instance->autorelease();

	return instance;
}

Tyracius::Tyracius(cocos2d::ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_Tyracius_Animations,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(472.0f, 780.0f),
	0.3f,
	cocos2d::Vec2(-24.0f, -390.0f))
{
}

Tyracius::~Tyracius()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////
