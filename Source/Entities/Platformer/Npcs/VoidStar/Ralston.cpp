#include "Ralston.h"

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

const std::string Ralston::MapKeyRalston = "ralston";
HexusOpponentData* Ralston::HexusOpponentDataInstance = nullptr;
const std::string Ralston::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_RALSTON";

Ralston* Ralston::deserialize(ValueMap& properties)
{
	Ralston* instance = new Ralston(properties);

	instance->autorelease();

	return instance;
}

Ralston::Ralston(ValueMap& properties) : super(properties,
	Ralston::MapKeyRalston,
	EntityResources::Npcs_VoidStar_Ralston_Animations,
	EntityResources::Npcs_VoidStar_Ralston_Emblem,
	Size(112.0f, 160.0f),
	0.85f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Ralston::getHexusOpponentData();
}

Ralston::~Ralston()
{
}

Vec2 Ralston::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* Ralston::getEntityName()
{
	return Strings::Platformer_Entities_Names_Npcs_VoidStar_Ralston::create();
}

HexusOpponentData* Ralston::getHexusOpponentData()
{
	if (Ralston::HexusOpponentDataInstance == nullptr)
	{
		Ralston::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameVoidStar,
			Vec2(-32.0f, -112.0f),
			Ralston::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateDeck(32, 0.894f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Addition),
				CardList::getInstance()->cardListByName.at(CardKeys::Inverse),
				CardList::getInstance()->cardListByName.at(CardKeys::ReturnToHand),
				CardList::getInstance()->cardListByName.at(CardKeys::Absorb),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip3),
				CardList::getInstance()->cardListByName.at(CardKeys::Kill),
				CardList::getInstance()->cardListByName.at(CardKeys::Flip4),
				CardList::getInstance()->cardListByName.at(CardKeys::Steal),
			}),
			nullptr,
			nullptr
		);
	}

	return Ralston::HexusOpponentDataInstance;
}