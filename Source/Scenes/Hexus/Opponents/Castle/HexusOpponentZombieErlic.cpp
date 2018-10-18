#include "HexusOpponentZombieErlic.h"

const std::string HexusOpponentZombieErlic::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ZOMBIE_ERLIC";
HexusOpponentZombieErlic* HexusOpponentZombieErlic::instance = nullptr;

HexusOpponentZombieErlic* HexusOpponentZombieErlic::getInstance()
{
	if (HexusOpponentZombieErlic::instance == nullptr)
	{
		HexusOpponentZombieErlic::instance = new HexusOpponentZombieErlic();
	}

	return HexusOpponentZombieErlic::instance;
}

HexusOpponentZombieErlic::HexusOpponentZombieErlic() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Castle_Enemies_ZombieErlic_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCastle,
	1.0f,
	Vec2(-32.0f, -64.0f),
	Vec2(-16.0f, -40.0f),
	HexusOpponentZombieErlic::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Shadow,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal3),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal2),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal1),
	},
	HexusOpponentData::generateDeck(25, 0.575f,
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

HexusOpponentZombieErlic::~HexusOpponentZombieErlic()
{
}