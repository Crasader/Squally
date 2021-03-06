#pragma once
#include "Engine/SmartNode.h"

// forward declarations
namespace Spriter2dX
{
	class AnimationNode;
}

namespace SpriterEngine
{
	class EntityInstance;
}

class AnimationPart;

class SmartAnimationNode : public SmartNode
{
public:
	static SmartAnimationNode* create(std::string animationResource);
	static SmartAnimationNode* create(std::string animationResource, std::string entityName);

	enum class AnimationPlayMode
	{
		ReturnToIdle,
		Repeat,
		PauseOnAnimationComplete,
		Callback,
	};

	SmartAnimationNode* clone();
	void playAnimation(AnimationPlayMode animationPlayMode = AnimationPlayMode::ReturnToIdle, float priority = 0.5f, float blendTime = 0.25f, std::function<void()> callback = nullptr);
	void playAnimation(const char* animationName, AnimationPlayMode animationPlayMode = AnimationPlayMode::ReturnToIdle, float priority = 0.5f, float blendTime = 0.25f, std::function<void()> callback = nullptr);
	void playAnimation(std::string animationName, AnimationPlayMode animationPlayMode = AnimationPlayMode::ReturnToIdle, float priority = 0.5f, float blendTime = 0.25f, std::function<void()> callback = nullptr);
	void clearAnimationPriority();
	AnimationPart* getAnimationPart(std::string partName);
	void restoreAnimationPart(std::string partName);
	void setFlippedX(bool flippedX);
	void setFlippedY(bool flippedY);
	bool getFlippedX();
	bool getFlippedY();
	std::string getCurrentAnimation();
	std::string getAnimationResource();
	void disableRender();
	void enableRender();

	static const std::string DefaultAnimationEntityName;
	static const std::string DefaultAnimationName;

protected:
	Spriter2dX::AnimationNode* animationNode;
	SpriterEngine::EntityInstance* entity;

private:
	typedef SmartNode super;
	SmartAnimationNode(std::string animationResource, std::string entityName);
	virtual ~SmartAnimationNode();

	bool initialized;
	float currentAnimationPriority;
	std::map<std::string, AnimationPart*> animationParts;
	std::string currentAnimation;
	std::string animationResource;
	std::string entityName;
};
