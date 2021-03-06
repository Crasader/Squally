#include "SkeletalArcher.h"

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

const std::string SkeletalArcher::MapKeySkeletalArcher = "skeletal-archer";
HexusOpponentData* SkeletalArcher::HexusOpponentDataInstance = nullptr;
const std::string SkeletalArcher::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SKELETAL_ARCHER";

SkeletalArcher* SkeletalArcher::deserialize(ValueMap& properties)
{
	SkeletalArcher* instance = new SkeletalArcher(properties);

	instance->autorelease();

	return instance;
}

SkeletalArcher::SkeletalArcher(ValueMap& properties) : super(properties,
	SkeletalArcher::MapKeySkeletalArcher,
	EntityResources::Enemies_SeaSharpCaverns_SkeletalArcher_Animations,
	EntityResources::Enemies_SeaSharpCaverns_SkeletalArcher_Emblem,
	Size(128.0f, 216.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = SkeletalArcher::getHexusOpponentData();
}

SkeletalArcher::~SkeletalArcher()
{
}

Vec2 SkeletalArcher::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* SkeletalArcher::getEntityName()
{
	return Strings::Platformer_Entities_Names_Enemies_SeaSharpCaverns_SkeletalArcher::create();
}

HexusOpponentData* SkeletalArcher::getHexusOpponentData()
{
	if (SkeletalArcher::HexusOpponentDataInstance == nullptr)
	{
		SkeletalArcher::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameSeaSharpCaverns,
			Vec2(-32.0f, -112.0f),
			SkeletalArcher::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Earth,
			HexusOpponentData::generateDeck(32, 0.333f,
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
					CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
					CardList::getInstance()->cardListByName.at(CardKeys::Inverse),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary5),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary5),
				},
				// Player decimal cards
				std::vector<CardData*>
				{
					
				},
				// Player hex cards
				std::vector<CardData*>
				{
					
				},
				// Enemy binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary7),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary7),
					CardList::getInstance()->cardListByName.at(CardKeys::Binary7),
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

	return SkeletalArcher::HexusOpponentDataInstance;
}