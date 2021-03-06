#pragma once

#include "Engine/AttachedBehavior/AttachedBehavior.h"

class Squally;

class SquallyNoSavePositionBehavior : public AttachedBehavior
{
public:
	static SquallyNoSavePositionBehavior* create(GameObject* owner);

	static const std::string MapKeyAttachedBehavior;

protected:
	SquallyNoSavePositionBehavior(GameObject* owner);
	~SquallyNoSavePositionBehavior();

	void onEnter() override;
	void onLoad() override;

private:
	typedef AttachedBehavior super;

	Squally* squally;
};
