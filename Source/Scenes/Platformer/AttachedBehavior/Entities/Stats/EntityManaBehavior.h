#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class PlatformerEntity;

class EntityManaBehavior : public AttachedBehavior
{
public:
	static EntityManaBehavior* create(GameObject* owner);

	int getMana();
	void addMana(int manaDelta);
	void setMana(int mana);
	int getMaxMana();

protected:
	EntityManaBehavior(GameObject* owner);
	~EntityManaBehavior();

	void onLoad() override;

	PlatformerEntity* entity;

private:
	typedef AttachedBehavior super;

	void onRevive();
};
