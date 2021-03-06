#include "ReturnToQueen.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Events/ObjectEvents.h"
#include "Entities/Platformer/Helpers/EndianForest/Guano.h"
#include "Entities/Platformer/Helpers/EndianForest/Scrappy.h"
#include "Entities/Platformer/Npcs/EndianForest/Elriel.h"
#include "Entities/Platformer/Npcs/EndianForest/QueenLiana.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Dialogue/EntityDialogueBehavior.h"

#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string ReturnToQueen::MapKeyQuest = "return-to-queen";

ReturnToQueen* ReturnToQueen::create(GameObject* owner, QuestLine* questLine)
{
	ReturnToQueen* instance = new ReturnToQueen(owner, questLine);

	instance->autorelease();

	return instance;
}

ReturnToQueen::ReturnToQueen(GameObject* owner, QuestLine* questLine) : super(owner, questLine, ReturnToQueen::MapKeyQuest, false)
{
	this->elriel = nullptr;
	this->guano = nullptr;
	this->queenLiana = nullptr;
	this->scrappy = nullptr;
	this->squally = nullptr;
}

ReturnToQueen::~ReturnToQueen()
{
}

void ReturnToQueen::onLoad(QuestState questState)
{
	ObjectEvents::watchForObject<Guano>(this, [=](Guano* guano)
	{
		this->guano = guano;
	}, Guano::MapKeyGuano);

	ObjectEvents::watchForObject<Scrappy>(this, [=](Scrappy* scrappy)
	{
		this->scrappy = scrappy;
	}, Scrappy::MapKeyScrappy);

	ObjectEvents::watchForObject<QueenLiana>(this, [=](QueenLiana* queenLiana)
	{
		this->queenLiana = queenLiana;
	}, QueenLiana::MapKeyQueenLiana);

	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	}, Squally::MapKeySqually);

	ObjectEvents::watchForObject<Elriel>(this, [=](Elriel* elriel)
	{
		this->elriel = elriel;

		if (questState == QuestState::None)
		{
			this->elriel->despawn();
		}
	}, Elriel::MapKeyElriel);

	if (questState == QuestState::Complete)
	{
		this->setPostText();
	}
}

void ReturnToQueen::onActivate(bool isActiveThroughSkippable)
{
	this->runCinematicSequence();
}

void ReturnToQueen::onComplete()
{
}

void ReturnToQueen::onSkipped()
{
	this->removeAllListeners();
}

void ReturnToQueen::runCinematicSequence()
{
	if (this->queenLiana == nullptr)
	{
		return;
	}
	
	this->queenLiana->watchForAttachedBehavior<EntityDialogueBehavior>([=](EntityDialogueBehavior* interactionBehavior)
	{
		// Pre-text chain
		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_L_WhereIsOurReward::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Right,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->guano, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterQuestion1,
			false
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_M_ThankYou::create()
				->setStringReplacementVariables(Strings::Platformer_Entities_Names_Npcs_EndianForest_Elriel::create()),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterShort2,
			false
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_N_However::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterLong1,
			false
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_O_WhatDoYouMean::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Right,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->guano, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterQuestion1,
			false
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_P_MoreOrcs::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->elriel, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium3,
			false
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_Q_OrcKingDead::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->elriel, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium4,
			true
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_R_WindowOfOpportunity::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->elriel, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium1,
			true
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_S_NoChoice::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->elriel, false),
				DialogueEvents::BuildPreviewNode(&this->guano, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium3,
			true
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_T_Ships::create(),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->guano, true)
			),
			[=]()
			{
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium2,
			true
		));

		interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
			Strings::Platformer_Quests_EndianForest_FindElriel_Lianna_U_VisitShops::create()
				->setStringReplacementVariables(Strings::Platformer_Entities_Names_Npcs_EndianForest_Marcel::create()),
			DialogueEvents::DialogueVisualArgs(
				DialogueBox::DialogueDock::Bottom,
				DialogueBox::DialogueAlignment::Left,
				DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
				DialogueEvents::BuildPreviewNode(&this->squally, true)
			),
			[=]()
			{
				this->setPostText();
				this->complete();
			},
			SoundResources::Platformer_Entities_Generic_ChatterMedium4,
			true
		));
	});
}

void ReturnToQueen::setPostText()
{
	this->defer([=]()
	{
		this->queenLiana->watchForAttachedBehavior<EntityDialogueBehavior>([=](EntityDialogueBehavior* interactionBehavior)
		{
			interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
				Strings::Platformer_Entities_Names_Npcs_EndianForest_Marcel::create()
					->setStringReplacementVariables(Strings::Platformer_Entities_Names_Npcs_EndianForest_Elriel::create()),
				DialogueEvents::DialogueVisualArgs(
					DialogueBox::DialogueDock::Bottom,
					DialogueBox::DialogueAlignment::Left,
					DialogueEvents::BuildPreviewNode(&this->queenLiana, false),
					DialogueEvents::BuildPreviewNode(&this->squally, true)
				),
				[=]()
				{
					this->setPostText();
				},
				SoundResources::Platformer_Entities_Generic_ChatterMedium2,
				true
			));
		});
	});
}
