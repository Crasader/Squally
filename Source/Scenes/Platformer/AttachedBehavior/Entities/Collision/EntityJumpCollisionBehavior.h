#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class CollisionObject;
class PlatformerEntity;

class EntityJumpCollisionBehavior : public AttachedBehavior
{
public:
	static EntityJumpCollisionBehavior* create(GameObject* owner);

	bool canJump();
	
	CollisionObject* jumpCollision;

	static const std::string MapKeyAttachedBehavior;

protected:
	EntityJumpCollisionBehavior(GameObject* owner);
	~EntityJumpCollisionBehavior();

	void onLoad() override;

private:
	typedef AttachedBehavior super;

	PlatformerEntity* entity;

	static const float JumpCollisionPadding;
	static const float JumpCollisionOffset;
	static const float JumpCollisionHeight;
	static const float JumpCollisionRadius;
};
