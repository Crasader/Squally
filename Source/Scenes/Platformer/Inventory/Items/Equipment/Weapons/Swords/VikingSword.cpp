#include "VikingSword.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string VikingSword::SaveKeyVikingSword = "viking-sword";

VikingSword* VikingSword::create()
{
	VikingSword* instance = new VikingSword();

	instance->autorelease();

	return instance;
}

VikingSword::VikingSword() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 2 }}), 3, 6, ItemStats(
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

VikingSword::~VikingSword()
{
}

Item* VikingSword::clone()
{
	return VikingSword::create();
}

std::string VikingSword::getItemName()
{
	return VikingSword::SaveKeyVikingSword;
}

LocalizedString* VikingSword::getString()
{
	return Strings::Items_Equipment_Weapons_Swords_VikingSword::create();
}

std::string VikingSword::getIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Swords_VikingSword;
}

std::string VikingSword::getSerializationKey()
{
	return VikingSword::SaveKeyVikingSword;
}
