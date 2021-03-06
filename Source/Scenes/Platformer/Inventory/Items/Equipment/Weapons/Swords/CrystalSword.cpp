#include "CrystalSword.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string CrystalSword::SaveKeyCrystalSword = "crystal-sword";

CrystalSword* CrystalSword::create()
{
	CrystalSword* instance = new CrystalSword();

	instance->autorelease();

	return instance;
}

CrystalSword::CrystalSword() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 2 }}), 3, 6, ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.05f
))
{
}

CrystalSword::~CrystalSword()
{
}

Item* CrystalSword::clone()
{
	return CrystalSword::create();
}

std::string CrystalSword::getItemName()
{
	return CrystalSword::SaveKeyCrystalSword;
}

LocalizedString* CrystalSword::getString()
{
	return Strings::Items_Equipment_Weapons_Swords_CrystalSword::create();
}

std::string CrystalSword::getIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Swords_CrystalSword;
}

std::string CrystalSword::getSerializationKey()
{
	return CrystalSword::SaveKeyCrystalSword;
}
