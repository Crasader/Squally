#include "SpecialPeek.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"
#include "Scenes/Hexus/CardData/CardKeys.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string SpecialPeek::SaveKeySpecialPeek = "special-peek";

SpecialPeek* SpecialPeek::create()
{
	SpecialPeek* instance = new SpecialPeek();

	instance->autorelease();

	return instance;
}

SpecialPeek::SpecialPeek() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 3 }}), ItemMeta(3))
{
}

SpecialPeek::~SpecialPeek()
{
}

Item* SpecialPeek::clone()
{
	return SpecialPeek::create();
}

std::string SpecialPeek::getItemName()
{
	return SpecialPeek::SaveKeySpecialPeek;
}

LocalizedString* SpecialPeek::getString()
{
	return Strings::Hexus_Cards_Peek::create();
}

std::string SpecialPeek::getIconResource()
{
	return ObjectResources::Collectables_Cards_CardSpecial;
}

std::string SpecialPeek::getSerializationKey()
{
	return SpecialPeek::SaveKeySpecialPeek;
}

std::string SpecialPeek::getCardKey()
{
	return CardKeys::Steal;
}
