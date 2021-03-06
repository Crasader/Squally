#include "Flail.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string Flail::SaveKeyFlail = "flail";

Flail* Flail::create()
{
	Flail* instance = new Flail();

	instance->autorelease();

	return instance;
}

Flail::Flail() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 2 }}), 3, 6, ItemStats(
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

Flail::~Flail()
{
}

Item* Flail::clone()
{
	return Flail::create();
}

std::string Flail::getItemName()
{
	return Flail::SaveKeyFlail;
}

LocalizedString* Flail::getString()
{
	return Strings::Items_Equipment_Weapons_Maces_Flail::create();
}

std::string Flail::getIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Maces_Flail;
}

std::string Flail::getSerializationKey()
{
	return Flail::SaveKeyFlail;
}

Vec2 Flail::getDisplayOffset()
{
	return Vec2(0.0f, -24.0f);
}
