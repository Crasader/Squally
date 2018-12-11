#include "Olive.h"

const std::string Olive::MapKeyNpcOlive = "olive";

Olive* Olive::deserialize(ValueMap* initProperties)
{
	Olive* instance = new Olive(initProperties);

	instance->autorelease();

	return instance;
}

Olive::Olive(ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Environment_Caverns_Npcs_Olive_Animations,
	PlatformerCollisionType::Enemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Olive::~Olive()
{
}
