#pragma once

#include "Scenes/MapBase.h"

class Cipher;
class ClickableTextNode;
class CollectablesMenu;
class GameHud;
class Hexus;
class InventoryMenu;
class MapMenu;
class NotificationHud;
class PartyMenu;
class PlatformerEnemy;

class PlatformerMap : public MapBase
{
public:
	static PlatformerMap* create(std::string mapResource, std::string transition = "");

	bool loadMap(std::string mapResource) override;

protected:
	PlatformerMap(std::string transition = "");
	~PlatformerMap();

private:
	typedef MapBase super;
	void initializePositions() override;
	void initializeListeners() override;
	void onEnter() override;
	void onEnterTransitionDidFinish() override;
	void onExit() override;
	void update(float dt) override;
	void disableMap();
	void enableMap();

	GameHud* gameHud;
	NotificationHud* notificationHud;
	Cipher* cipher;
	Hexus* hexus;
	CollectablesMenu* collectablesMenu;
	MapMenu* mapMenu;
	PartyMenu* partyMenu;
	InventoryMenu* inventoryMenu;
	cocos2d::Node* combatFadeInNode;

	std::string transition;
};
