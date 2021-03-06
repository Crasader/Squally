#include "PenguinWarrior.h"

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

const std::string PenguinWarrior::MapKeyPenguinWarrior = "penguin-warrior";
HexusOpponentData* PenguinWarrior::HexusOpponentDataInstance = nullptr;
const std::string PenguinWarrior::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_PENGUIN_WARRIOR";

PenguinWarrior* PenguinWarrior::deserialize(ValueMap& properties)
{
	PenguinWarrior* instance = new PenguinWarrior(properties);

	instance->autorelease();

	return instance;
}

PenguinWarrior::PenguinWarrior(ValueMap& properties) : super(properties,
	PenguinWarrior::MapKeyPenguinWarrior,
	EntityResources::Enemies_BalmerPeaks_PenguinWarrior_Animations,
	EntityResources::Enemies_BalmerPeaks_PenguinWarrior_Emblem,
	Size(212.0f, 296.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = PenguinWarrior::getHexusOpponentData();
}

PenguinWarrior::~PenguinWarrior()
{
}

Vec2 PenguinWarrior::getDialogueOffset()
{
	return Vec2(-32.0f, -128.0f);
}

LocalizedString* PenguinWarrior::getEntityName()
{
	return Strings::Platformer_Entities_Names_Enemies_BalmerPeaks_PenguinWarrior::create();
}

HexusOpponentData* PenguinWarrior::getHexusOpponentData()
{
	if (PenguinWarrior::HexusOpponentDataInstance == nullptr)
	{
		PenguinWarrior::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameBalmerPeaks,
			Vec2(-32.0f, -128.0f),
			PenguinWarrior::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Water,
			HexusOpponentData::generateDeck(32, 0.667f,
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
					CardList::getInstance()->cardListByName.at(CardKeys::Steal),
					CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
					CardList::getInstance()->cardListByName.at(CardKeys::ShiftRightCircular),
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
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal2),
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal2),
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary3),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary3),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal3),
					CardList::getInstance()->cardListByName.at(CardKeys::Decimal6),
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Hex3),
				}
			)
		);
	}

	return PenguinWarrior::HexusOpponentDataInstance;
}