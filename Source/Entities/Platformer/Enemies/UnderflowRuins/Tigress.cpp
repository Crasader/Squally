//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Tigress.h"

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

using namespace cocos2d;

const std::string Tigress::MapKeyTigress = "tigress";
HexusOpponentData* Tigress::HexusOpponentDataInstance = nullptr;
const std::string Tigress::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_TIGRESS";

Tigress* Tigress::deserialize(ValueMap& initProperties)
{
	Tigress* instance = new Tigress(initProperties);

	instance->autorelease();

	return instance;
}

Tigress::Tigress(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_UnderflowRuins_Tigress_Animations,
	EntityResources::Enemies_UnderflowRuins_Tigress_Emblem,
	PlatformerCollisionType::Enemy,
	Size(128.0f, 256.0f),
	1.0f,
	Vec2(0.0f, 0.0f),
	16,
	8)
{
	this->hexusOpponentData = Tigress::getHexusOpponentData();
}

Tigress::~Tigress()
{
}

Vec2 Tigress::getAvatarFrameOffset()
{
	return Vec2(-16.0f, -160.0f);
}

HexusOpponentData* Tigress::getHexusOpponentData()
{
	if (Tigress::HexusOpponentDataInstance == nullptr)
	{
		Tigress::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_UnderflowRuins_Tigress_Animations,
			HexusResources::Menus_HexusFrameUnderflowRuins,
			1.0f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-16.0f, -160.0f),
			Tigress::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Light,
			0.167f,
			HexusOpponentData::generateDeck(32, 0.167f,
			{

			}),
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
					CardList::getInstance()->cardListByName.at(CardKeys::Flip1),
CardList::getInstance()->cardListByName.at(CardKeys::Flip2),
CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
				},
				// Enemy hand
				std::vector<CardData*>
				{
					
				},
				// Player binary cards
				std::vector<CardData*>
				{
					CardList::getInstance()->cardListByName.at(CardKeys::Binary0),
CardList::getInstance()->cardListByName.at(CardKeys::Binary0),
CardList::getInstance()->cardListByName.at(CardKeys::Binary0),
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
					CardList::getInstance()->cardListByName.at(CardKeys::Binary8),
CardList::getInstance()->cardListByName.at(CardKeys::Binary4),
CardList::getInstance()->cardListByName.at(CardKeys::Binary8),
				},
				// Enemy decimal cards
				std::vector<CardData*>
				{
					
				},
				// Enemy hex cards
				std::vector<CardData*>
				{
					
				},
				StateOverride::TutorialMode::NoTutorial
			)
		);
	}

	return Tigress::HexusOpponentDataInstance;
}