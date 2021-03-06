#include "AnubisWarrior.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/EntityResources.h"
#include "Resources/HexusResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string AnubisWarrior::MapKeyAnubisWarrior = "anubis-warrior";
HexusOpponentData* AnubisWarrior::HexusOpponentDataInstance = nullptr;
const std::string AnubisWarrior::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ANUBIS_WARRIOR";

AnubisWarrior* AnubisWarrior::deserialize(ValueMap& properties)
{
	AnubisWarrior* instance = new AnubisWarrior(properties);

	instance->autorelease();

	return instance;
}

AnubisWarrior::AnubisWarrior(ValueMap& properties) : super(properties,
	AnubisWarrior::MapKeyAnubisWarrior,
	EntityResources::Enemies_UnderflowRuins_AnubisWarrior_Animations,
	EntityResources::Enemies_UnderflowRuins_AnubisWarrior_Emblem,
	Size(256.0f, 292.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = AnubisWarrior::getHexusOpponentData();
}

AnubisWarrior::~AnubisWarrior()
{
}

Vec2 AnubisWarrior::getDialogueOffset()
{
	return Vec2(-32.0f, -196.0f);
}

LocalizedString* AnubisWarrior::getEntityName()
{
	return Strings::Platformer_Entities_Names_Enemies_UnderflowRuins_AnubisWarrior::create();
}

HexusOpponentData* AnubisWarrior::getHexusOpponentData()
{
	if (AnubisWarrior::HexusOpponentDataInstance == nullptr)
	{
		AnubisWarrior::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameUnderflowRuins,
			Vec2(-32.0f, -196.0f),
			AnubisWarrior::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Light,
			HexusOpponentData::generateDeck(32, 0.917f,
			{

			}),
			nullptr,
			StateOverride::create(
				// Player losses
				1,
				// Enemy losses
				1,
				// Player's turn
				true,
				// Player passed
				true,
				// Enemy passed
				true,
				// Player deck
				std::vector<CardData*>
				{
					
				},
				// Enemy deck
				std::vector<CardData*>
				{
					
				},
				// Player hand
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Flip4),
					CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
					CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary15),
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal13),
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal7),
				},
				// Player hex cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Hex11),
					CardList::getInstance()->cardListByName.at(CardKeys::Hex10),
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary15),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary13),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary13),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary12),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary10),
					CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
					CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
					CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					
				}
			)
		);
	}

	return AnubisWarrior::HexusOpponentDataInstance;
}