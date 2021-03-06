#include "Vesuvius.h"

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

const std::string Vesuvius::MapKeyVesuvius = "vesuvius";
HexusOpponentData* Vesuvius::HexusOpponentDataInstance = nullptr;
const std::string Vesuvius::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_VESUVIUS";

Vesuvius* Vesuvius::deserialize(ValueMap& properties)
{
	Vesuvius* instance = new Vesuvius(properties);

	instance->autorelease();

	return instance;
}

Vesuvius::Vesuvius(ValueMap& properties) : super(properties,
	Vesuvius::MapKeyVesuvius,
	EntityResources::Npcs_LambdaCrypts_Vesuvius_Animations,
	EntityResources::Npcs_LambdaCrypts_Vesuvius_Emblem,
	Size(112.0f, 160.0f),
	1.0f,
	Vec2(0.0f, 0.0f))
{
	this->hexusOpponentData = Vesuvius::getHexusOpponentData();
}

Vesuvius::~Vesuvius()
{
}

Vec2 Vesuvius::getDialogueOffset()
{
	return Vec2(0.0f, 0.0f);
}

LocalizedString* Vesuvius::getEntityName()
{
	return Strings::Platformer_Entities_Names_Npcs_LambdaCrypts_Vesuvius::create();
}

HexusOpponentData* Vesuvius::getHexusOpponentData()
{
	if (Vesuvius::HexusOpponentDataInstance == nullptr)
	{
		Vesuvius::HexusOpponentDataInstance = new HexusOpponentData(
			nullptr,
			HexusResources::Menus_HexusFrameLambdaCrypts,
			Vec2(-32.0f, -112.0f),
			Vesuvius::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateDeck(32, 0.875f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::Subtraction),
				CardList::getInstance()->cardListByName.at(CardKeys::Inverse),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::Greed),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::Addition),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
			}),
			nullptr,
			nullptr
		);
	}

	return Vesuvius::HexusOpponentDataInstance;
}