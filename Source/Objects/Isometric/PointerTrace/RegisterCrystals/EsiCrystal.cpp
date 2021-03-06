#include "EsiCrystal.h"

#include "cocos/2d/CCAction.h"
#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Scenes/PointerTrace/RegisterState.h"

#include "Resources/IsometricObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string EsiCrystal::MapKeyEsiCrystal = "esi-crystal";

EsiCrystal* EsiCrystal::create(ValueMap& properties)
{
	EsiCrystal* instance = new EsiCrystal(properties);

	instance->autorelease();

	return instance;
}

EsiCrystal::EsiCrystal(ValueMap& properties) : super(properties)
{
	this->crystal = Sprite::create(IsometricObjectResources::PointerTrace_Crystals_EsiCrystal);
	
	LocalizedString* registerString = (sizeof(void*) == 4)
		? (LocalizedString*)Strings::PointerTrace_Assembly_RegisterEsi::create()
		: (LocalizedString*)Strings::PointerTrace_Assembly_RegisterRsi::create();

	this->buildString(registerString);

	this->crystalNode->addChild(this->crystal);
}

EsiCrystal::~EsiCrystal()
{
}

void EsiCrystal::onEnter()
{
	super::onEnter();
}

void EsiCrystal::initializePositions()
{
	super::initializePositions();
}

void EsiCrystal::updateRegister(int value)
{
	RegisterState::setRegisterEsi(value);
}

int EsiCrystal::getRegisterValue()
{
	return RegisterState::getRegisterEsi();
}
