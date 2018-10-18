#include "HexusOpponentSkeletalArcher.h"

const std::string HexusOpponentSkeletalArcher::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SKELETAL_ARCHER";
HexusOpponentSkeletalArcher* HexusOpponentSkeletalArcher::instance = nullptr;

HexusOpponentSkeletalArcher* HexusOpponentSkeletalArcher::getInstance()
{
	if (HexusOpponentSkeletalArcher::instance == nullptr)
	{
		HexusOpponentSkeletalArcher::instance = new HexusOpponentSkeletalArcher();
	}

	return HexusOpponentSkeletalArcher::instance;
}

HexusOpponentSkeletalArcher::HexusOpponentSkeletalArcher() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Caverns_Enemies_SkeletalArcher_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCaverns,
	1.0f,
	Vec2(-32.0f, -48.0f),
	Vec2(-32.0f, -32.0f),
	HexusOpponentSkeletalArcher::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Shadow,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal3),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal2),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal1),
	},
	HexusOpponentData::generateDeck(25, 0.445f,
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

HexusOpponentSkeletalArcher::~HexusOpponentSkeletalArcher()
{
}