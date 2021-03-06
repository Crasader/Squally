#include "PenguinGrunt.h"

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

const std::string PenguinGrunt::MapKeyPenguinGrunt = "penguin-grunt";
HexusOpponentData* PenguinGrunt::HexusOpponentDataInstance = nullptr;
const std::string PenguinGrunt::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_PENGUIN_GRUNT";

PenguinGrunt* PenguinGrunt::deserialize(ValueMap& properties)
{
	PenguinGrunt* instance = new PenguinGrunt(properties);

	instance->autorelease();

	return instance;
}

PenguinGrunt::PenguinGrunt(ValueMap& properties) : super(properties,
	PenguinGrunt::MapKeyPenguinGrunt,
	EntityResources::Enemies_BalmerPeaks_PenguinGrunt_Animations,
	EntityResources::Enemies_BalmerPeaks_PenguinGrunt_Emblem,
	Size(212.0f, 296.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = PenguinGrunt::getHexusOpponentData();
}

PenguinGrunt::~PenguinGrunt()
{
}

Vec2 PenguinGrunt::getDialogueOffset()
{
	return Vec2(-32.0f, -128.0f);
}

LocalizedString* PenguinGrunt::getEntityName()
{
	return Strings::Platformer_Entities_Names_Enemies_BalmerPeaks_PenguinGrunt::create();
}

HexusOpponentData* PenguinGrunt::getHexusOpponentData()
{
	if (PenguinGrunt::HexusOpponentDataInstance == nullptr)
	{
		PenguinGrunt::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameBalmerPeaks,
			Vec2(-32.0f, -128.0f),
			PenguinGrunt::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Water,
			HexusOpponentData::generateDeck(32, 0.583f,
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
					CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
					CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal7),
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal6),
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary0),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal15),
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal8),
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Hex0),
					CardList::getInstance()->cardListByName.at(CardKeys::Hex13),
					CardList::getInstance()->cardListByName.at(CardKeys::Hex0),
				}
			)
		);
	}

	return PenguinGrunt::HexusOpponentDataInstance;
}