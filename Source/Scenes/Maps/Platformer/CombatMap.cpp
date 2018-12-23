#include "CombatMap.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/Camera/GameCamera.h"
#include "Engine/GlobalDirector.h"
#include "Engine/Maps/SerializableMap.h"
#include "Events/NavigationEvents.h"

using namespace cocos2d;

CombatMap* CombatMap::instance = nullptr;

void CombatMap::registerGlobalScene()
{
	if (CombatMap::instance == nullptr)
	{
		CombatMap::instance = new CombatMap();
		CombatMap::instance->autorelease();
		CombatMap::instance->initializeListeners();
	}

	GlobalDirector::registerGlobalScene(CombatMap::instance);
}

CombatMap::CombatMap()
{
	if (!MapBase::init())
	{
		throw std::uncaught_exception();
	}
}

CombatMap::~CombatMap()
{
}

void CombatMap::onEnter()
{
	MapBase::onEnter();
}

void CombatMap::initializePositions()
{
	MapBase::initializePositions();
}

void CombatMap::initializeListeners()
{
	MapBase::initializeListeners();

	CombatMap::instance->addGlobalEventListener(EventListenerCustom::create(NavigationEvents::EventNavigateCombat, [](EventCustom* args)
	{
		NavigationEvents::NavigateCombatArgs* combatArgs = static_cast<NavigationEvents::NavigateCombatArgs*>(args->getUserData());

		if (combatArgs != nullptr)
		{
			CombatMap::instance->loadMap(SerializableMap::deserialize(combatArgs->levelFile));
			GlobalDirector::loadScene(CombatMap::instance);
		}
	}));
}
