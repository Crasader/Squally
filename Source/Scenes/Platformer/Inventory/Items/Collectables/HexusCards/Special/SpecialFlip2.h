#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class SpecialFlip2 : public HexusCard
{
public:
	static SpecialFlip2* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;
	std::string getCardKey() override;

	static const std::string SaveKeySpecialFlip2;

protected:
	SpecialFlip2();
	~SpecialFlip2();

private:
	typedef HexusCard super;
};
