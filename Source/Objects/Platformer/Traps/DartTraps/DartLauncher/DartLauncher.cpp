#include "DartLauncher.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"
#include "cocos/base/CCValue.h"

#include "Engine/Hackables/HackableCode.h"
#include "Engine/Hackables/HackableData.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/MathUtils.h"
#include "Objects/Platformer/Traps/DartTraps/DartLauncher/DartLauncherGenericPreview.h"
#include "Objects/Platformer/Traps/DartTraps/DartLauncher/DartLauncherUpdateTimerPreview.h"
#include "Objects/Platformer/Traps/DartTraps/DartLauncher/DartNopClippy.h"
#include "Objects/Platformer/Traps/DartTraps/DartPool.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"

#include "Resources/ObjectResources.h"
#include "Resources/UIResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

#define LOCAL_FUNC_ID_SHOOT 1

const std::string DartLauncher::MapKeyDartLauncher = "dart-launcher";
const std::string DartLauncher::PropertyLaunchSpeed = "speed";
const float DartLauncher::DefaultLaunchSpeed = 320.0f;
const float DartLauncher::LaunchCooldownMin = 2.0f;
const float DartLauncher::LaunchCooldownMax = 4.0f;

DartLauncher* DartLauncher::create(ValueMap& properties)
{
	DartLauncher* instance = new DartLauncher(properties);

	instance->autorelease();

	return instance;
}

DartLauncher::DartLauncher(ValueMap& properties) : super(properties)
{
	this->dartNopClippy = DartNopClippy::create();
	this->launcherContainer = Node::create();
	this->launcherSprite = Sprite::create(ObjectResources::Traps_DartLauncher_DartLauncher);
	this->launchRotation = GameUtils::getKeyOrDefault(this->properties, GameObject::MapKeyRotation, Value(0.0f)).asFloat();
	this->launchSpeed = GameUtils::getKeyOrDefault(this->properties, DartLauncher::PropertyLaunchSpeed, Value(DartLauncher::DefaultLaunchSpeed)).asFloat();
	this->launchTimer = 0.0f;
	this->dartPool = DartPool::create(2, this->launchRotation + 90.0f, this->launchSpeed);

	this->launcherSprite->setAnchorPoint(Vec2(0.0f, 1.0f));
	this->dartPool->setPositionY(GameUtils::getKeyOrDefault(this->properties, GameObject::MapKeyHeight, Value(0.0f)).asFloat() / 2.0f);
	this->launcherContainer->setPositionY(GameUtils::getKeyOrDefault(this->properties, GameObject::MapKeyHeight, Value(0.0f)).asFloat() / 2.0f);

	this->launcherContainer->setRotation(this->launchRotation);
	
	this->registerClippy(this->dartNopClippy);
	this->launcherContainer->addChild(this->dartPool);
	this->launcherContainer->addChild(this->launcherSprite);
	this->addChild(this->launcherContainer);
}

DartLauncher::~DartLauncher()
{
}

void DartLauncher::onEnter()
{
	super::onEnter();

	this->rebindUIElementsTo(this->dartPool);

	this->scheduleUpdate();
}

void DartLauncher::initializePositions()
{
	super::initializePositions();

	this->dartPool->setPosition(Vec2(42.0f, -24.0f));
}

void DartLauncher::update(float dt)
{
	super::update(dt);

	this->shoot(dt);
}

Vec2 DartLauncher::getButtonOffset()
{
	float width = 24.0f;
	float height = -124.0f;
	float angle = float(M_PI) * this->launchRotation / 180.0f;

	return Vec2(std::sin(angle) * width, std::cos(angle) * height);
}

void DartLauncher::registerHackables()
{
	super::registerHackables();

	HackableCode::CodeInfoMap codeInfoMap =
	{
		{
			LOCAL_FUNC_ID_SHOOT,
			HackableCode::HackableCodeInfo(
				DartLauncher::MapKeyDartLauncher,
				Strings::Menus_Hacking_Objects_DartLauncher_UpdateLaunchTimer_UpdateLaunchTimer::create(),
				UIResources::Menus_Icons_CrossHair,
				DartLauncherUpdateTimerPreview::create(),
				{
					{ HackableCode::Register::zax, Strings::Menus_Hacking_Objects_DartLauncher_UpdateLaunchTimer_RegisterEax::create() },
					{ HackableCode::Register::xmm0, Strings::Menus_Hacking_Objects_DartLauncher_UpdateLaunchTimer_RegisterXmm0::create() },
					{ HackableCode::Register::xmm1, Strings::Menus_Hacking_Objects_DartLauncher_UpdateLaunchTimer_RegisterXmm1::create() },
				},
				int(HackFlags::None),
				12.0f,
				this->dartNopClippy
			)
		},
	};

	auto swingFunc = &DartLauncher::shoot;
	std::vector<HackableCode*> hackables = HackableCode::create((void*&)swingFunc, codeInfoMap);

	for (auto it = hackables.begin(); it != hackables.end(); it++)
	{
		this->registerCode(*it);
	}
}

HackablePreview* DartLauncher::createDefaultPreview()
{
	return DartLauncherGenericPreview::create();
}

NO_OPTIMIZE void DartLauncher::shoot(float dt)
{
	if (this->launchTimer <= 0.0f)
	{
		this->launchTimer = RandomHelper::random_real(DartLauncher::LaunchCooldownMin, DartLauncher::LaunchCooldownMax);

		this->dartPool->getNextDart();
	}

	volatile float* timePtr = &this->launchTimer;
	volatile float* dtPtr = &dt;

	ASM(push ZAX);
	ASM(push ZBX);
	ASM_MOV_REG_VAR(ZAX, timePtr);
	ASM_MOV_REG_VAR(ZBX, dtPtr);
	ASM(movss xmm0, [ZAX])
	ASM(movss xmm1, [ZBX])

	HACKABLE_CODE_BEGIN(LOCAL_FUNC_ID_SHOOT);
	ASM(subps xmm0, xmm1);
	ASM(movss [ZAX], xmm0);
	ASM_NOP10();
	HACKABLE_CODE_END();

	ASM(pop ZBX);
	ASM(pop ZAX);

	HACKABLES_STOP_SEARCH();
}
END_NO_OPTIMIZE
