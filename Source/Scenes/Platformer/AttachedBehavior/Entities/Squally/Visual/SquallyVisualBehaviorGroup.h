#pragma once

#include "Engine/AttachedBehavior/AttachedBehaviorGroup.h"

class Squally;

class SquallyVisualBehaviorGroup : public AttachedBehaviorGroup
{
public:
	static SquallyVisualBehaviorGroup* create(GameObject* owner);

	static const std::string MapKeyAttachedBehavior;

protected:
	SquallyVisualBehaviorGroup(GameObject* owner);
	~SquallyVisualBehaviorGroup();

	void onLoad() override;

private:
	typedef AttachedBehaviorGroup super;
};
