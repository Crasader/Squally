#pragma once

#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"

class ThrowWeapon : public PlatformerAttack
{
public:
	static ThrowWeapon* create(float attackDuration, float recoverDuration);

	LocalizedString* getString() override;
	std::string getAttackAnimation() override;

protected:
	ThrowWeapon(float attackDuration, float recoverDuration);
	~ThrowWeapon();

	void performAttack(PlatformerEntity* owner, PlatformerEntity* target) override;
	void onCleanup() override;

private:
	typedef PlatformerAttack super;
	
	PlatformerAttack* cloneInternal() override;
};
