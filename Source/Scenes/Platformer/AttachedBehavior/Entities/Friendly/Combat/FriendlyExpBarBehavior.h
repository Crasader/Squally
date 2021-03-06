#pragma once

#include "Scenes/Platformer/AttachedBehavior/Entities/Collision/EntityCollisionBehaviorBase.h"

class LocalizedLabel;
class LocalizedString;
class PlatformerEntity;
class ProgressBar;

class FriendlyExpBarBehavior : public EntityCollisionBehaviorBase
{
public:
	static FriendlyExpBarBehavior* create(GameObject* owner);

	static const std::string MapKeyAttachedBehavior;

protected:
	FriendlyExpBarBehavior(GameObject* owner);
	~FriendlyExpBarBehavior();

	void onLoad() override;

private:
	typedef EntityCollisionBehaviorBase super;

	void giveExp();
	void fillBar(float startProgress, float endProgress, float fillDuration, float startDelay, std::function<void()> onComplete = nullptr);
	void runLevelUpEffect();

	PlatformerEntity* owner;
	
	int tickCounter;
	ProgressBar* expProgressBar;
	LocalizedString* deltaString;
	LocalizedLabel* deltaLabel;
};
