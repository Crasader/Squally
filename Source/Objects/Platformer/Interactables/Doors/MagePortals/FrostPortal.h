#pragma once
#include <set>

#include "Objects/Platformer/Interactables/Doors/MagePortals/MagePortal.h"

namespace cocos2d
{
	class DrawNode;
	class ParticleSystem;
}

class FrostPortal : public MagePortal
{
public:
	static FrostPortal* create(cocos2d::ValueMap& properties);

	void closePortal(bool instant) override;
	void openPortal(bool instant) override;

	static const std::string MapKeyFrostPortal;

protected:
	FrostPortal(cocos2d::ValueMap& properties);
	virtual ~FrostPortal();
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef MagePortal super;

	cocos2d::ParticleSystem* portalParticles;
	cocos2d::ParticleSystem* edgeParticles;
};
