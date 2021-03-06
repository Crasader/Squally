#include "CombatEvents.h"

#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventDispatcher.h"

using namespace cocos2d;

const std::string CombatEvents::EventSpawn = "EVENT_COMBAT_SPAWN";
const std::string CombatEvents::EventGetAssociatedTimelineEntry = "EVENT_COMBAT_GET_ASSOCIATED_TIMELINE_ENTRY";
const std::string CombatEvents::EventChangeMenuState = "EVENT_COMBAT_CHANGE_MENU_STATE";
const std::string CombatEvents::EventDisableDefend = "EVENT_COMBAT_DISABLE_DEFEND";
const std::string CombatEvents::EventDisableItems = "EVENT_COMBAT_DISABLE_ITEMS";
const std::string CombatEvents::EventSelectCastTarget = "EVENT_COMBAT_SELECT_CAST_TARGET";
const std::string CombatEvents::EventRequestAIAction = "EVENT_COMBAT_REQUEST_AI_ACTION";
const std::string CombatEvents::EventRequestRetargetCorrection = "EVENT_COMBAT_REQUEST_RETARGET_CORRECTION";
const std::string CombatEvents::EventBuffApplied = "EVENT_COMBAT_BUFF_APPLIED";
const std::string CombatEvents::EventEntityBuffsModifyDamageOrHealingTaken = "EVENT_COMBAT_ENTITY_BUFFS_MODIFY_DAMAGE_OR_HEALING_TAKEN";
const std::string CombatEvents::EventEntityBuffsModifyDamageOrHealingDelt = "EVENT_COMBAT_ENTITY_BUFFS_MODIFY_DAMAGE_OR_HEALING_DELT";
const std::string CombatEvents::EventEntityTimelineReset = "EVENT_COMBAT_ENTITY_TIMELINE_RESET";
const std::string CombatEvents::EventPauseTimeline = "EVENT_COMBAT_PAUSE_TIMELINE";
const std::string CombatEvents::EventResumeTimeline = "EVENT_COMBAT_RESUME_TIMELINE";
const std::string CombatEvents::EventInterruptTimeline = "EVENT_COMBAT_INTERRUPT_TIMELINE";
const std::string CombatEvents::EventDamageOrHealingDelt = "EVENT_COMBAT_DAMAGE_OR_HEALING_DELT";
const std::string CombatEvents::EventDamageOrHealing = "EVENT_COMBAT_DAMAGE_OR_HEALING";
const std::string CombatEvents::EventCastBlocked = "EVENT_COMBAT_CAST_BLOCKED";
const std::string CombatEvents::EventCastInterrupt = "EVENT_COMBAT_CAST_INTERRUPT";
const std::string CombatEvents::EventCombatFinished = "EVENT_COMBAT_COMBAT_FINISHED";
const std::string CombatEvents::EventGiveExp = "EVENT_COMBAT_GIVE_EXP";
const std::string CombatEvents::EventGiveRewards = "EVENT_COMBAT_GIVE_REWARDS";
const std::string CombatEvents::EventReturnToMap = "EVENT_COMBAT_RETURN_TO_MAP";
const std::string CombatEvents::EventHackableCombatCue = "EVENT_COMBAT_HACKABLE_COMBAT_CUE";

void CombatEvents::TriggerSpawn(SpawnArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventSpawn,
		&args
	);
}

void CombatEvents::TriggerGetAssociatedTimelineEntry(AssociatedEntryArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventGetAssociatedTimelineEntry,
		&args
	);
}

void CombatEvents::TriggerMenuStateChange(MenuStateArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventChangeMenuState,
		&args
	);
}

void CombatEvents::TriggerDisableDefend()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventDisableDefend
	);
}

void CombatEvents::TriggerDisableItems()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventDisableItems
	);
}

void CombatEvents::TriggerSelectCastTarget(CastTargetArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventSelectCastTarget,
		&args
	);
}

void CombatEvents::TriggerRequestRetargetCorrection(AIRequestArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventRequestRetargetCorrection,
		&args
	);
}

void CombatEvents::TriggerRequestAIAction(AIRequestArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventRequestAIAction,
		&args
	);
}

void CombatEvents::TriggerPauseTimeline()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventPauseTimeline
	);
}

void CombatEvents::TriggerResumeTimeline()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventResumeTimeline
	);
}

void CombatEvents::TriggerInterruptTimeline()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventInterruptTimeline
	);
}

void CombatEvents::TriggerBuffApplied(BuffAppliedArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventBuffApplied,
		&args
	);
}

void CombatEvents::TriggerEntityBuffsModifyDamageOrHealingTaken(BeforeDamageOrHealingTakenArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventEntityBuffsModifyDamageOrHealingTaken,
		&args
	);
}

void CombatEvents::TriggerEntityBuffsModifyDamageOrHealingDelt(BeforeDamageOrHealingDeltArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventEntityBuffsModifyDamageOrHealingDelt,
		&args
	);
}

void CombatEvents::TriggerEntityTimelineReset(TimelineResetArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventEntityTimelineReset,
		&args
	);
}

void CombatEvents::TriggerDamageOrHealingDelt(DamageOrHealingDeltArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventDamageOrHealingDelt,
		&args
	);
}

void CombatEvents::TriggerDamageOrHealing(DamageOrHealingArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventDamageOrHealing,
		&args
	);
}

void CombatEvents::TriggerCastBlocked(CastBlockedArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventCastBlocked,
		&args
	);
}

void CombatEvents::TriggerCastInterrupt(CastInterruptArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventCastInterrupt,
		&args
	);
}

void CombatEvents::TriggerCombatFinished(CombatFinishedArgs args)
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventCombatFinished,
		&args
	);
}

void CombatEvents::TriggerGiveExp()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventGiveExp
	);
}

void CombatEvents::TriggerGiveRewards()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventGiveRewards
	);
}

void CombatEvents::TriggerReturnToMap()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventReturnToMap
	);
}

void CombatEvents::TriggerHackableCombatCue()
{
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(
		CombatEvents::EventHackableCombatCue
	);
}
