#pragma once

#include "Engine/Hackables/HackableObject.h"

namespace cocos2d
{
	class Sprite;
}

class AnimationPart;
class HackableData;
class SmartAnimationNode;

class DartGun : public HackableObject
{
public:
	static DartGun* create(cocos2d::ValueMap& properties);

	static const std::string MapKeyDartGun;

protected:
	DartGun(cocos2d::ValueMap& properties);
	~DartGun();

	void onEnter() override;
	void initializePositions() override;
	void update(float) override;
	cocos2d::Vec2 getButtonOffset() override;
	void registerHackables() override;

private:
	typedef HackableObject super;
	void shoot(float dt);

	float timeSinceLastShot;
	cocos2d::Node* dartNode;
	SmartAnimationNode* dartGunAnimations;
	AnimationPart* cannon;

	static const std::string PivotBone;
};
