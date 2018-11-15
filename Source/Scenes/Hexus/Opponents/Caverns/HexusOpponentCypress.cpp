#include "HexusOpponentCypress.h"

const std::string HexusOpponentCypress::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_CYPRESS";
HexusOpponentCypress* HexusOpponentCypress::instance = nullptr;

HexusOpponentCypress* HexusOpponentCypress::getInstance()
{
	if (HexusOpponentCypress::instance == nullptr)
	{
		HexusOpponentCypress::instance = new HexusOpponentCypress();
	}

	return HexusOpponentCypress::instance;
}

HexusOpponentCypress::HexusOpponentCypress() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Caverns_Npcs_Cypress_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCaverns,
	0.9f,
	Vec2(-32.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentCypress::OpponentSaveKey,
	HexusOpponentData::Strategy::Random,
	Card::CardStyle::Shadow,
	HexusOpponentData::generateReward(0.41f),
	HexusOpponentData::generateDeck(25, 0.41f,
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

HexusOpponentCypress::~HexusOpponentCypress()
{
}
