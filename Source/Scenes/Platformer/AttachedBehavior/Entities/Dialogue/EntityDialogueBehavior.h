#pragma once

#include <queue>

#include "Engine/AttachedBehavior/AttachedBehavior.h"
#include "Events/DialogueEvents.h"

class CollisionObject;
class DialogueSet;
class InteractMenu;
class LocalizedString;
class PlatformerEntity;
class Scrappy;
class SpeechBubble;

class EntityDialogueBehavior : public AttachedBehavior
{
public:
	static EntityDialogueBehavior* create(GameObject* owner);

	void enqueuePretext(DialogueEvents::DialogueOpenArgs pretext);
	void setActiveDialogueSet(DialogueSet* dialogueSet, bool showDialogue = true);
	void addDialogueSet(DialogueSet* dialogueSet);
	void removeDialogueSet(DialogueSet* dialogueSet);
	DialogueSet* getMainDialogueSet();
	SpeechBubble* getSpeechBubble();

	static const std::string MapKeyAttachedBehavior;

protected:
	EntityDialogueBehavior(GameObject* owner);
	~EntityDialogueBehavior();

	void initializePositions() override;
	void onLoad() override;

private:
	typedef AttachedBehavior super;

	void onInteract();
	void progressDialogue();
	void chooseOption(int option);
	void showOptions();
	bool hasDialogueOptions();
	LocalizedString* getOptionString(int index, LocalizedString* optionText);

	PlatformerEntity* entity;
	Scrappy* scrappy;
	SpeechBubble* speechBubble;

	bool canInteract;
	bool optionsVisible;
	
	CollisionObject* dialogueCollision;
	InteractMenu* interactMenu;
	std::queue<DialogueEvents::DialogueOpenArgs> pretextQueue;
	DialogueSet* mainDialogueSet;
	DialogueSet* activeDialogueSet;
	std::vector<DialogueSet*> dialogueSets;
	cocos2d::Node* pretextNode;
	cocos2d::Node* dialogueSetNode;
};
