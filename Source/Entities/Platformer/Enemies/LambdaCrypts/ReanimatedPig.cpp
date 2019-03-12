//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ReanimatedPig.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////A////A////A////A////A////A////A////A////A////A/

////B////B////B////B////B////B////B////B////B////B/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

using namespace cocos2d;

const std::string ReanimatedPig::MapKeyReanimatedPig = "reanimated-pig";
HexusOpponentData* ReanimatedPig::HexusOpponentDataInstance = nullptr;
const std::string ReanimatedPig::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_REANIMATED_PIG";

ReanimatedPig* ReanimatedPig::deserialize(ValueMap& initProperties)
{
	ReanimatedPig* instance = new ReanimatedPig(initProperties);

	instance->autorelease();

	return instance;
}

ReanimatedPig::ReanimatedPig(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_LambdaCrypts_ReanimatedPig_Animations,
	EntityResources::Enemies_LambdaCrypts_ReanimatedPig_Emblem,
	PlatformerCollisionType::Enemy,
	Size(256.0f, 240.0f),
	0.8f,
	Vec2(0.0f, 0.0f),
	10,
	10)
{
	this->hexusOpponentData = ReanimatedPig::getHexusOpponentData();

	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

ReanimatedPig::~ReanimatedPig()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

Vec2 ReanimatedPig::getAvatarFrameOffset()
{
	return Vec2(0.0f, 0.0f);
}

HexusOpponentData* ReanimatedPig::getHexusOpponentData()
{
	if (ReanimatedPig::HexusOpponentDataInstance == nullptr)
	{
		ReanimatedPig::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_LambdaCrypts_ReanimatedPig_Animations,
			UIResources::Menus_Hexus_HexusFrameLambdaCrypts,
			0.8f,
			Vec2(0.0f, 0.0f),
			Vec2(0.0f, 0.0f),
			ReanimatedPig::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateReward(0.615f),
			HexusOpponentData::generateDeck(25, 0.615f,
			{

			}),
			nullptr
		);
	}

	return ReanimatedPig::HexusOpponentDataInstance;
}