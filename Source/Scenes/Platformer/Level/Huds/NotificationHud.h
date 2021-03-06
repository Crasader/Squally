#pragma once
#include <queue>

#include "Engine/UI/HUD/Hud.h"

namespace cocos2d
{
	class LayerColor;
	class Sprite;
}

class ClickableTextNode;
class LocalizedLabel;
class LocalizedString;
class PlatformerEntity;
class Sound;

class NotificationHud : public Hud
{
public:
	static NotificationHud* create();

protected:
	void update(float dt) override;

private:
	typedef Hud super;
	NotificationHud();
	~NotificationHud();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

	void showNotificationTakeover(LocalizedString* title, LocalizedString* description, std::string soundResource);
	void pushNotification(LocalizedString* title, LocalizedString* description, std::string iconResource, std::string soundResource);
	void closeNotificationMenu();

	cocos2d::Node* previousFocus;

	cocos2d::LayerColor* backdrop;
	cocos2d::Sprite* menuBack;
	ClickableTextNode* okButton;
	LocalizedLabel* title;
	LocalizedLabel* description;
	cocos2d::Node* takeoverNode;
	cocos2d::Node* notificationsNode;
	Sound* notificationSound;

	std::queue<cocos2d::Node*> toProcess;
	std::vector<float> slotCooldowns;

	static const int SlotCount;
	static const int SfxCooldown;
};
