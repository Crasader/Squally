#include "EntityGroundCollisionBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/EntityResources.h"

using namespace cocos2d;

const std::string EntityGroundCollisionBehavior::MapKeyAttachedBehavior = "entity-ground-collisions";
const float EntityGroundCollisionBehavior::GroundCollisionPadding = 16.0f;
const float EntityGroundCollisionBehavior::GroundCollisionOffset = -4.0f;
const float EntityGroundCollisionBehavior::GroundCollisionHeight = 64.0f;
const float EntityGroundCollisionBehavior::GroundCollisionRadius = 8.0f;

EntityGroundCollisionBehavior* EntityGroundCollisionBehavior::create(GameObject* owner)
{
	EntityGroundCollisionBehavior* instance = new EntityGroundCollisionBehavior(owner);

	instance->autorelease();

	return instance;
}

EntityGroundCollisionBehavior::EntityGroundCollisionBehavior(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
	else
	{
		this->groundCollision = CollisionObject::create(
			CollisionObject::createCapsulePolygon(
				Size(std::max((this->entity->getEntitySize()).width + EntityGroundCollisionBehavior::GroundCollisionPadding * 2.0f, 8.0f), EntityGroundCollisionBehavior::GroundCollisionHeight),
				1.0f,
				EntityGroundCollisionBehavior::GroundCollisionRadius,
				0.0f
			),
			(int)PlatformerCollisionType::GroundDetector,
			false,
			false
		);

		Vec2 collisionOffset = this->entity->getCollisionOffset();

		if (this->entity->isFlippedY())
		{
			Vec2 offset = Vec2(collisionOffset.x, -collisionOffset.y) - Vec2(0.0f, -this->entity->getHoverHeight() / 2.0f - EntityGroundCollisionBehavior::GroundCollisionOffset);
			this->groundCollision->inverseGravity();
			this->groundCollision->getPhysicsBody()->setPositionOffset(offset);
		}
		else
		{
			Vec2 offset = collisionOffset + Vec2(0.0f, -this->entity->getHoverHeight() / 2.0f + EntityGroundCollisionBehavior::GroundCollisionOffset);
			this->groundCollision->getPhysicsBody()->setPositionOffset(offset);
		}
		
		this->addChild(this->groundCollision);
	}
}

EntityGroundCollisionBehavior::~EntityGroundCollisionBehavior()
{
}

void EntityGroundCollisionBehavior::onLoad()
{
	this->groundCollision->whenCollidesWith({ (int)PlatformerCollisionType::Solid, (int)PlatformerCollisionType::SolidRoof, (int)PlatformerCollisionType::PassThrough, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{
		this->onCollideWithGround();
		
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->groundCollision->whenStopsCollidingWith({ (int)EngineCollisionTypes::Intersection }, [=](CollisionObject::CollisionData collisionData)
	{
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->groundCollision->whenStopsCollidingWith({ (int)PlatformerCollisionType::Solid, (int)PlatformerCollisionType::SolidRoof, (int)PlatformerCollisionType::PassThrough, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{
		return CollisionObject::CollisionResult::DoNothing;
	});
}

void EntityGroundCollisionBehavior::onCollideWithGround()
{
	// Clear current animation
	if (this->entity->getStateOrDefaultBool(StateKeys::IsAlive, true) && this->entity->getStateOrDefaultFloat(StateKeys::VelocityY, 0.0f) <= 0.0f)
	{
		if (this->entity->getAnimations()->getCurrentAnimation() == "Jump")
		{
			this->entity->getAnimations()->clearAnimationPriority();
		}

		this->entity->getAnimations()->playAnimation();
	}
}

bool EntityGroundCollisionBehavior::isOnGround()
{
	return !this->groundCollision->getCurrentCollisions().empty();
}

bool EntityGroundCollisionBehavior::isStandingOn(CollisionObject* collisonObject)
{
	Node* currentCollisionGroup = collisonObject->getParent();

	// Special case for intersection points -- just return false
	for (auto next : this->groundCollision->getCurrentCollisions())
	{
		switch(next->getCollisionType())
		{
			case (int)EngineCollisionTypes::Intersection:
			{
				return false;
			}
			default:
			{
				break;
			}
		}
	}

	for (auto next : this->groundCollision->getCurrentCollisions())
	{
		switch(next->getCollisionType())
		{
			case (int)PlatformerCollisionType::Solid:
			case (int)PlatformerCollisionType::PassThrough:
			{
				// Do a parent check because multiple collison objects can be nested under the same macro-object (ie terrain segments)
				if (next->getParent() == currentCollisionGroup)
				{
					return true;
				}
			}
			default:
			{
				break;
			}
		}
	}

	return false;
}

bool EntityGroundCollisionBehavior::isStandingOnSomethingOtherThan(CollisionObject* collisonObject)
{
	Node* currentCollisionGroup = collisonObject->getParent();

	// Special case when standing on an intersection -- always collide with the non-owner of that intersection point (the lower platform)
	for (auto next : this->groundCollision->getCurrentCollisions())
	{
		switch(next->getCollisionType())
		{
			case (int)EngineCollisionTypes::Intersection:
			{
				return currentCollisionGroup == next->getParent();
			}
			default:
			{
				break;
			}
		}
	}

	// Greedy search for the oldest collision. This works out as being the object that is the true "ground".
	for (auto next : this->groundCollision->getCurrentCollisions())
	{
		switch(next->getCollisionType())
		{
			case (int)PlatformerCollisionType::Solid:
			case (int)PlatformerCollisionType::PassThrough:
			{
				// Do a parent check because multiple collison objects can be nested under the same macro-object (ie terrain segments)
				if (next->getParent() != currentCollisionGroup)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			default:
			{
				break;
			}
		}
	}

	return false;
}
