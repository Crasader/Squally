#include "HexusOpponentSkeletalNecromancer.h"

const std::string HexusOpponentSkeletalNecromancer::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SKELETAL_NECROMANCER";
HexusOpponentSkeletalNecromancer* HexusOpponentSkeletalNecromancer::instance = nullptr;

HexusOpponentSkeletalNecromancer* HexusOpponentSkeletalNecromancer::getInstance()
{
	if (HexusOpponentSkeletalNecromancer::instance == nullptr)
	{
		HexusOpponentSkeletalNecromancer::instance = new HexusOpponentSkeletalNecromancer();
	}

	return HexusOpponentSkeletalNecromancer::instance;
}

HexusOpponentSkeletalNecromancer::HexusOpponentSkeletalNecromancer() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Caverns_Enemies_SkeletalNecromancer_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCaverns,
	1.0f,
	Vec2(-32.0f, -48.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentSkeletalNecromancer::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Shadow,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal3),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal2),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal1),
	},
	HexusOpponentData::generateDeck(25, 0.475f,
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

HexusOpponentSkeletalNecromancer::~HexusOpponentSkeletalNecromancer()
{
}