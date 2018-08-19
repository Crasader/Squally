#pragma once
#include "cocos2d.h"

#include "Engine/Camera/GameCamera.h"
#include "Engine/Rendering/Components/InfiniteParallaxNode.h"
#include "Resources.h"
#include "Scenes/Maps/Platformer/Backgrounds/BackgroundBase.h"

using namespace cocos2d;

class OceanBackground : public BackgroundBase
{
public:
	static OceanBackground * create(ValueMap* properties, std::string name);

	static const std::string KeyBackgroundOcean;

private:
	OceanBackground(ValueMap* properties, std::string name);
	~OceanBackground();

	void update(float) override;

	Sprite * background;
};
