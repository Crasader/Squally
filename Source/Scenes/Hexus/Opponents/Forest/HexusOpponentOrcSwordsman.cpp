#include "HexusOpponentOrcSwordsman.h"

const std::string HexusOpponentOrcSwordsman::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ORC_SWORDSMAN";
HexusOpponentOrcSwordsman* HexusOpponentOrcSwordsman::instance = nullptr;

HexusOpponentOrcSwordsman* HexusOpponentOrcSwordsman::getInstance()
{
	if (HexusOpponentOrcSwordsman::instance == nullptr)
	{
		HexusOpponentOrcSwordsman::instance = new HexusOpponentOrcSwordsman();
	}

	return HexusOpponentOrcSwordsman::instance;
}

HexusOpponentOrcSwordsman::HexusOpponentOrcSwordsman() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Forest_Enemies_OrcSwordsman_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameForest,
	1.0f,
	Vec2(-48.0f, -48.0f),
	Vec2(-32.0f, -40.0f),
	HexusOpponentOrcSwordsman::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.325f,
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

HexusOpponentOrcSwordsman::~HexusOpponentOrcSwordsman()
{
}