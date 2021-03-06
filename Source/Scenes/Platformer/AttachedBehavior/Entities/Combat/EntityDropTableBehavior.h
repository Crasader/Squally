#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class DropPoolDeserializer;
class PlatformerEntity;
class MinMaxPool;

class EntityDropTableBehavior : public AttachedBehavior
{
public:
	static EntityDropTableBehavior* create(GameObject* owner);

	void setDropTable(std::string dropTable);
	MinMaxPool* getDropPool();

	static const std::string MapKeyAttachedBehavior;

protected:
	EntityDropTableBehavior(GameObject* owner);
	~EntityDropTableBehavior();

	void onLoad() override;

private:
	typedef AttachedBehavior super;

	PlatformerEntity* entity;
	DropPoolDeserializer* dropPoolDeserializer;
	MinMaxPool* dropPool;
};
