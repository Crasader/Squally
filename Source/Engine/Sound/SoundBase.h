#pragma once

#include "Engine/GlobalNode.h"

class SoundBase : public GlobalNode
{
public:
	virtual void play(bool repeat = false, float startDelay = 0.0f);
	virtual void unpause();
	virtual void stop();
	virtual void stopAndFadeOut(std::function<void()> onFadeOutCallback = nullptr);

	void setCustomMultiplier(float customMultiplier);
	void toggleCameraDistanceFade(bool enableCameraDistanceFade);
	void setSoundResource(std::string soundResource);

protected:
	SoundBase(std::string soundResource);
	virtual ~SoundBase();

	void onEnter() override;
	void update(float dt) override;
	virtual float getConfigVolume() = 0;
	void updateVolume();
	float getVolume();

	int activeTrackId;

private:
	typedef GlobalNode super;

	void updateDistanceFade();

	std::string soundResource;
	float fadeMultiplier;
	float distanceMultiplier;
	float customMultiplier;
	int fadeOutTick;
	bool enableCameraDistanceFade;
	bool isFading;
	std::function<void()> onFadeOutCallback;
	cocos2d::Vec2 cachedCoords;

	static const std::string KeyScheduleFadeOutAudio;
	static const int INVALID_ID;
};
