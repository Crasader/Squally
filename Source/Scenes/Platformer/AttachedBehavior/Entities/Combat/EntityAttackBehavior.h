#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class PlatformerAttack;
class PlatformerEntity;

class EntityAttackBehavior : public AttachedBehavior
{
public:
	static EntityAttackBehavior* create(GameObject* owner);

	std::vector<PlatformerAttack*> getAttacks();
	std::vector<PlatformerAttack*> getAvailableAttacks();
	std::vector<PlatformerAttack*> getNoCostAttacks();
	std::vector<PlatformerAttack*> getAvailableConsumables();
	void registerAttack(PlatformerAttack* attack);

	static const float DefaultRecoverSpeed;
	static const float DefaultRecoverSpeedSlow;
	static const float DefaultRecoverSpeedVerySlow;
	static const std::string MapKeyAttachedBehavior;

protected:
	EntityAttackBehavior(GameObject* owner);
	~EntityAttackBehavior();

	void initializePositions() override;
	void onLoad() override;

private:
	typedef AttachedBehavior super;

	void buildEquipmentAttacks();
	void rebuildConsumables();

	PlatformerEntity* entity;
	cocos2d::Node* attacksNode;
	cocos2d::Node* consumablessNode;

	bool consumablesStale;

	std::vector<PlatformerAttack*> registeredAttacks;
	std::vector<PlatformerAttack*> registeredConsumables;
};
