#include "HexusOpponentScaldor.h"

const std::string HexusOpponentScaldor::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SCALDOR";
HexusOpponentScaldor* HexusOpponentScaldor::instance = nullptr;

HexusOpponentScaldor* HexusOpponentScaldor::getInstance()
{
	if (HexusOpponentScaldor::instance == nullptr)
	{
		HexusOpponentScaldor::instance = new HexusOpponentScaldor();
	}

	return HexusOpponentScaldor::instance;
}

HexusOpponentScaldor::HexusOpponentScaldor() : HexusOpponentData(
	EntityResources::Npcs_Scaldor_Animations,
	UIResources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	1.0f,
	Vec2(-48.0f, -48.0f),
	Vec2(-16.0f, -24.0f),
	HexusOpponentScaldor::OpponentSaveKey,
	HexusOpponentData::Strategy::Random,
	Card::CardStyle::Earth,
	HexusOpponentData::generateReward(0.795f),
	HexusOpponentData::generateDeck(25, 0.795f,
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

HexusOpponentScaldor::~HexusOpponentScaldor()
{
}
