#include "GoblinGruntBoarCombatBehavior.h"

#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/Item.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Items/EntityInventoryBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityAttackBehavior.h"
#include "Scenes/Platformer/Level/Combat/Attacks/Weapons/Slash.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestorePotion.h"

#include "Resources/UIResources.h"

using namespace cocos2d;
	
const std::string GoblinGruntBoarCombatBehavior::MapKeyAttachedBehavior = "goblin-grunt-boar-combat";

GoblinGruntBoarCombatBehavior* GoblinGruntBoarCombatBehavior::create(GameObject* owner)
{
	GoblinGruntBoarCombatBehavior* instance = new GoblinGruntBoarCombatBehavior(owner);

	instance->autorelease();

	return instance;
}

GoblinGruntBoarCombatBehavior::GoblinGruntBoarCombatBehavior(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
}

GoblinGruntBoarCombatBehavior::~GoblinGruntBoarCombatBehavior()
{
}

void GoblinGruntBoarCombatBehavior::initializePositions()
{
}

void GoblinGruntBoarCombatBehavior::onLoad()
{
	this->entity->watchForAttachedBehavior<EntityAttackBehavior>([=](EntityAttackBehavior* attackBehavior)
	{
		attackBehavior->registerAttack(Slash::create(0.7f, EntityAttackBehavior::DefaultRecoverSpeed));
	});
	
	this->entity->watchForAttachedBehavior<EntityInventoryBehavior>([=](EntityInventoryBehavior* entityInventoryBehavior)
	{
		Inventory* inventory = entityInventoryBehavior->getInventory();

		if (inventory != nullptr)
		{
			inventory->forceInsert(RestorePotion::create());
		}
	});
}
