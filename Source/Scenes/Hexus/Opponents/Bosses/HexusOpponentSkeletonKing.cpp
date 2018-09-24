#include "HexusOpponentSkeletonKing.h"

const std::string HexusOpponentSkeletonKing::StringKeyOpponentName = "Squally_Npc_Names_Skeleton_King";
HexusOpponentSkeletonKing* HexusOpponentSkeletonKing::instance = nullptr;

HexusOpponentSkeletonKing* HexusOpponentSkeletonKing::getInstance()
{
	if (HexusOpponentSkeletonKing::instance == nullptr)
	{
		HexusOpponentSkeletonKing::instance = new HexusOpponentSkeletonKing();
	}

	return HexusOpponentSkeletonKing::instance;
}

HexusOpponentSkeletonKing::HexusOpponentSkeletonKing() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Obelisk_Enemies_BossSkeletonKing_Animations,
	1.0f,
	Vec2(-64.0f, -32.0f),
	HexusOpponentSkeletonKing::StringKeyOpponentName, Card::CardStyle::Water,
	{
		CardList::getInstance()->cardListByName->at(CardList::Binary0),
		CardList::getInstance()->cardListByName->at(CardList::Binary1),
		CardList::getInstance()->cardListByName->at(CardList::Binary2),
		CardList::getInstance()->cardListByName->at(CardList::Binary3),
		CardList::getInstance()->cardListByName->at(CardList::Binary4),
		CardList::getInstance()->cardListByName->at(CardList::Binary5),
		CardList::getInstance()->cardListByName->at(CardList::Binary6),
		CardList::getInstance()->cardListByName->at(CardList::Binary7),
		CardList::getInstance()->cardListByName->at(CardList::Binary8),
		CardList::getInstance()->cardListByName->at(CardList::Binary9),
		CardList::getInstance()->cardListByName->at(CardList::Binary10),
		CardList::getInstance()->cardListByName->at(CardList::Binary11),
		CardList::getInstance()->cardListByName->at(CardList::Binary12),
		CardList::getInstance()->cardListByName->at(CardList::Binary13),
		CardList::getInstance()->cardListByName->at(CardList::Binary14),
		CardList::getInstance()->cardListByName->at(CardList::Binary15),
		CardList::getInstance()->cardListByName->at(CardList::Decimal0),
		CardList::getInstance()->cardListByName->at(CardList::Decimal1),
		CardList::getInstance()->cardListByName->at(CardList::Decimal2),
		CardList::getInstance()->cardListByName->at(CardList::Decimal3),
		CardList::getInstance()->cardListByName->at(CardList::Decimal4),
		CardList::getInstance()->cardListByName->at(CardList::Decimal5),
		CardList::getInstance()->cardListByName->at(CardList::Decimal6),
		CardList::getInstance()->cardListByName->at(CardList::Decimal7),
		CardList::getInstance()->cardListByName->at(CardList::Decimal8),
		CardList::getInstance()->cardListByName->at(CardList::Decimal9),
		CardList::getInstance()->cardListByName->at(CardList::Decimal10),
		CardList::getInstance()->cardListByName->at(CardList::Decimal11),
		CardList::getInstance()->cardListByName->at(CardList::Decimal12),
		CardList::getInstance()->cardListByName->at(CardList::Decimal13),
		CardList::getInstance()->cardListByName->at(CardList::Decimal14),
		CardList::getInstance()->cardListByName->at(CardList::Decimal15),
		CardList::getInstance()->cardListByName->at(CardList::Hex0),
		CardList::getInstance()->cardListByName->at(CardList::Hex1),
		CardList::getInstance()->cardListByName->at(CardList::Hex2),
		CardList::getInstance()->cardListByName->at(CardList::Hex3),
		CardList::getInstance()->cardListByName->at(CardList::Hex4),
		CardList::getInstance()->cardListByName->at(CardList::Hex5),
		CardList::getInstance()->cardListByName->at(CardList::Hex6),
		CardList::getInstance()->cardListByName->at(CardList::Hex7),
		CardList::getInstance()->cardListByName->at(CardList::Hex8),
		CardList::getInstance()->cardListByName->at(CardList::Hex9),
		CardList::getInstance()->cardListByName->at(CardList::Hex10),
		CardList::getInstance()->cardListByName->at(CardList::Hex11),
		CardList::getInstance()->cardListByName->at(CardList::Hex12),
		CardList::getInstance()->cardListByName->at(CardList::Hex13),
		CardList::getInstance()->cardListByName->at(CardList::Hex14),
		CardList::getInstance()->cardListByName->at(CardList::Hex15),
		CardList::getInstance()->cardListByName->at(CardList::ShiftLeft),
		CardList::getInstance()->cardListByName->at(CardList::ShiftRight),
		CardList::getInstance()->cardListByName->at(CardList::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardList::LogicalOr),
		CardList::getInstance()->cardListByName->at(CardList::LogicalXor),
		CardList::getInstance()->cardListByName->at(CardList::ShiftLeft),
		CardList::getInstance()->cardListByName->at(CardList::ShiftRight),
		CardList::getInstance()->cardListByName->at(CardList::Flip1),
		CardList::getInstance()->cardListByName->at(CardList::Flip2),
		CardList::getInstance()->cardListByName->at(CardList::Flip3),
		CardList::getInstance()->cardListByName->at(CardList::Flip4),
		CardList::getInstance()->cardListByName->at(CardList::Inverse),
		CardList::getInstance()->cardListByName->at(CardList::Inverse),
		CardList::getInstance()->cardListByName->at(CardList::Inverse),
		CardList::getInstance()->cardListByName->at(CardList::Addition),
		CardList::getInstance()->cardListByName->at(CardList::Subtraction),
	})
{
}

HexusOpponentSkeletonKing::~HexusOpponentSkeletonKing()
{
}