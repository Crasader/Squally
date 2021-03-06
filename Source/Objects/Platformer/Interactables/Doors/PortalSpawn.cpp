#include "PortalSpawn.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Events/ObjectEvents.h"
#include "Engine/UI/MapTitleBanner.h"
#include "Engine/Utils/GameUtils.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/PlatformerEvents.h"
#include "Deserializers/Platformer/PlatformerBannerDeserializer.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string PortalSpawn::MapKeyPortalSpawn = "spawn";
const std::string PortalSpawn::MapKeyPortalSpawnTransition = "transition";
const std::string PortalSpawn::MapKeyMapBanner = "map-banner";

PortalSpawn* PortalSpawn::create(ValueMap& properties)
{
	PortalSpawn* instance = new PortalSpawn(properties);

	instance->autorelease();

	return instance;
}

PortalSpawn::PortalSpawn(ValueMap& properties) : super(properties)
{
	this->transition = GameUtils::getKeyOrDefault(this->properties, PortalSpawn::MapKeyPortalSpawnTransition, Value("")).asString();
	this->bannerName = GameUtils::getKeyOrDefault(this->properties, PortalSpawn::MapKeyMapBanner, Value("")).asString();
}

PortalSpawn::~PortalSpawn()
{
}

void PortalSpawn::onEnter()
{
	super::onEnter();
}

void PortalSpawn::initializePositions()
{
	super::initializePositions();
}

void PortalSpawn::initializeListeners()
{
	super::initializeListeners();

	this->addEventListener(EventListenerCustom::create(PlatformerEvents::EventSpawnToTransitionLocation, [=](EventCustom* eventCustom)
	{
		PlatformerEvents::TransitionArgs* args = static_cast<PlatformerEvents::TransitionArgs*>(eventCustom->getUserData());
		
		if (args != nullptr && args->transition == this->transition)
		{
			ObjectEvents::QueryObjects(QueryObjectsArgs<Squally>([=](Squally* squally)
			{
				PlatformerEvents::TriggerWarpToLocation(PlatformerEvents::WarpArgs(squally, GameUtils::getWorldCoords(this)));
				this->tryShowBanner();

			}), Squally::MapKeySqually);
		}
	}));
}

void PortalSpawn::tryShowBanner()
{
	if (this->bannerName.empty())
	{
		return;
	}

	PlatformerBannerDeserializer* deserializer = PlatformerBannerDeserializer::create();

	ValueMap properties = ValueMap();

	properties[BannerDeserializer::MapKeyBanner] = this->bannerName ;

	MapTitleBanner* banner = deserializer->deserializeProperties(properties);

	this->addChild(banner);
}
