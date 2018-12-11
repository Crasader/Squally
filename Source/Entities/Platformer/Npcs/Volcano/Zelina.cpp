#include "Zelina.h"

const std::string Zelina::MapKeyNpcZelina = "zelina";

Zelina* Zelina::deserialize(ValueMap* initProperties)
{
	Zelina* instance = new Zelina(initProperties);

	instance->autorelease();

	return instance;
}

Zelina::Zelina(ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Environment_Volcano_Npcs_Zelina_Animations,
	PlatformerCollisionType::Enemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Zelina::~Zelina()
{
}
