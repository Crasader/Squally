#include "CompositeBow.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string CompositeBow::SaveKeyCompositeBow = "composite-bow";

CompositeBow* CompositeBow::create()
{
	CompositeBow* instance = new CompositeBow();

	instance->autorelease();

	return instance;
}

CompositeBow::CompositeBow() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 7 }}), 3, 6, ItemStats(
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

CompositeBow::~CompositeBow()
{
}

Item* CompositeBow::clone()
{
	return CompositeBow::create();
}

std::string CompositeBow::getItemName()
{
	return CompositeBow::SaveKeyCompositeBow;
}

LocalizedString* CompositeBow::getString()
{
	return Strings::Items_Equipment_Weapons_Bows_CompositeBow::create();
}

std::string CompositeBow::getIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Bows_CompositeBow;
}

std::string CompositeBow::getSerializationKey()
{
	return CompositeBow::SaveKeyCompositeBow;
}

Vec2 CompositeBow::getDisplayOffset()
{
	return Vec2(0.0f, -24.0f);
}
