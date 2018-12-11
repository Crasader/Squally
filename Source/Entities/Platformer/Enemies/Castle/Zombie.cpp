#include "Zombie.h"

const std::string Zombie::MapKeyEnemyZombie = "zombie";

Zombie* Zombie::deserialize(ValueMap* initProperties)
{
	Zombie* instance = new Zombie(initProperties);

	instance->autorelease();

	return instance;
}

Zombie::Zombie(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Environment_Castle_Enemies_Zombie_Animations,
	PlatformerCollisionType::Enemy,
	Size(114.0f, 208.0f),
	0.9f,
	Vec2(0.0f, 0.0f))
{
}

Zombie::~Zombie()
{
}
