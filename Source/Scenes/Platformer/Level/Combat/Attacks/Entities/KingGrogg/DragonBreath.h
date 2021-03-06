#pragma once

#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"

class DragonBreath : public PlatformerAttack
{
public:
	static DragonBreath* create(float attackDuration, float recoverDuration);

	LocalizedString* getString() override;
	std::string getAttackAnimation() override;

protected:
	DragonBreath(float attackDuration, float recoverDuration);
	~DragonBreath();

	void performAttack(PlatformerEntity* owner, PlatformerEntity* target) override;
	void onCleanup() override;

private:
	typedef PlatformerAttack super;
	
	PlatformerAttack* cloneInternal() override;
};
