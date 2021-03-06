#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Weapons/Weapon.h"

class CrystalSword : public Weapon
{
public:
	static CrystalSword* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyCrystalSword;

protected:
	CrystalSword();
	~CrystalSword();

private:
	typedef Weapon super;
};
