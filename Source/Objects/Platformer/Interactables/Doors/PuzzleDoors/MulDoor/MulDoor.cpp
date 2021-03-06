#include "MulDoor.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCValue.h"

#include "Engine/Hackables/HackableCode.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/MathUtils.h"
#include "Objects/Platformer/Interactables/Doors/PuzzleDoors/MulDoor/MulDoorPreview.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"

#include "Resources/ObjectResources.h"
#include "Resources/ParticleResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

#define LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME 1

const std::string MulDoor::MapKeyMulDoor = "mul-door";

MulDoor* MulDoor::create(ValueMap& properties)
{
	MulDoor* instance = new MulDoor(properties);

	instance->autorelease();

	return instance;
}

MulDoor::MulDoor(ValueMap& properties) : super(properties)
{
}

MulDoor::~MulDoor()
{
}

void MulDoor::registerHackables()
{
	super::registerHackables();

	HackableCode::CodeInfoMap codeInfoMap =
	{
		{
			LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME,
			HackableCode::HackableCodeInfo(
				MulDoor::MapKeyMulDoor,
				Strings::Menus_Hacking_Objects_PuzzleDoor_Multiply_Multiply::create(),
				UIResources::Menus_Icons_Pearls,
				MulDoorPreview::create(),
				{
					{ HackableCode::Register::zcx, Strings::Menus_Hacking_Objects_PuzzleDoor_Multiply_RegisterEcx::create() },
				},
				int(HackFlags::None),
				14.0f,
				nullptr,
				{
					// The disassembler produces the equivalent imul 'rcx, rcx, 1', which is confusing to noobs, so we override that
					HackableCode::ReadOnlyScript(nullptr, "imul ecx, 1", "imul rcx, 1"),
				},
				true
			)
		},
	};

	auto incrementAnimationFunc = &MulDoor::mulDoorTransform;
	std::vector<HackableCode*> hackables = HackableCode::create((void*&)incrementAnimationFunc, codeInfoMap);

	for (auto it = hackables.begin(); it != hackables.end(); it++)
	{
		this->registerCode(*it);
	}
}

void MulDoor::runOperation(int puzzleIndex)
{
	this->setRealValue(puzzleIndex * 2);

	this->mulDoorTransform(puzzleIndex);
}

NO_OPTIMIZE void MulDoor::mulDoorTransform(int puzzleIndex)
{
	int transform = puzzleIndex;

	ASM(push ZCX)
	ASM_MOV_REG_VAR(ZCX, transform);

	HACKABLE_CODE_BEGIN(LOCAL_FUNC_ID_INCREMENT_ANIMATION_FRAME);
	ASM(imul ZCX, 1)
	ASM_NOP6();
	HACKABLE_CODE_END();

	ASM_MOV_VAR_REG(transform, ZCX);
	ASM(pop ZCX);

	this->setHackValue(transform);

	HACKABLES_STOP_SEARCH();
}
END_NO_OPTIMIZE
