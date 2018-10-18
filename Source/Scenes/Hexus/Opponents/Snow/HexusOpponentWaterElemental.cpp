#include "HexusOpponentWaterElemental.h"

const std::string HexusOpponentWaterElemental::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_WATER_ELEMENTAL";
HexusOpponentWaterElemental* HexusOpponentWaterElemental::instance = nullptr;

HexusOpponentWaterElemental* HexusOpponentWaterElemental::getInstance()
{
	if (HexusOpponentWaterElemental::instance == nullptr)
	{
		HexusOpponentWaterElemental::instance = new HexusOpponentWaterElemental();
	}

	return HexusOpponentWaterElemental::instance;
}

HexusOpponentWaterElemental::HexusOpponentWaterElemental() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Snow_Enemies_WaterElemental_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameIceCaps,
	1.0f,
	Vec2(-32.0f, -48.0f),
	Vec2(-32.0f, -72.0f),
	HexusOpponentWaterElemental::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.68f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalOr),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalXor),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentWaterElemental::~HexusOpponentWaterElemental()
{
}