#include "BeatTutorialE.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Events/ObjectEvents.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/DialogueEvents.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Interactables/Doors/MagePortals/MagePortal.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Friendly/Hexus/EndianForest/Gauntlet/TutorialEBehavior.h"

#include "Resources/HexusResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string BeatTutorialE::MapKeyQuest = "beat-tutorial-E";
const std::string BeatTutorialE::WinLossTrackIdentifier = "Tutorial-E";
const std::string BeatTutorialE::QuestPortalTag = "quest-portal";

BeatTutorialE* BeatTutorialE::create(GameObject* owner, QuestLine* questLine)
{
	BeatTutorialE* instance = new BeatTutorialE(owner, questLine);

	instance->autorelease();

	return instance;
}

BeatTutorialE::BeatTutorialE(GameObject* owner, QuestLine* questLine) : super(owner, questLine, BeatTutorialE::MapKeyQuest, false)
{
	this->mage = dynamic_cast<PlatformerEntity*>(owner);
	this->squally = nullptr;
	this->portal = nullptr;
}

BeatTutorialE::~BeatTutorialE()
{
}

void BeatTutorialE::onLoad(QuestState questState)
{
	this->defer([=]()
	{
		TutorialEBehavior* tutorialBehavior = TutorialEBehavior::create(this->mage);

		tutorialBehavior->registerWinCallback([=]()
		{
			this->complete();
		});
		
    	this->mage->attachBehavior(tutorialBehavior);
	});

	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	}, Squally::MapKeySqually);

	ObjectEvents::watchForObject<MagePortal>(this, [=](MagePortal* portal)
	{
		this->portal = portal;
		
		if (questState == QuestState::Complete)
		{
			this->portal->openPortal(true);
		}
		else
		{
			this->portal->closePortal(true);
		}
	}, BeatTutorialE::QuestPortalTag);
}

void BeatTutorialE::onActivate(bool isActiveThroughSkippable)
{
}

void BeatTutorialE::onComplete()
{
	if (this->portal != nullptr)
	{
		this->portal->openPortal(true);
	}
}

void BeatTutorialE::onSkipped()
{
	this->removeAllListeners();
}

