#pragma once

#include "Objects/Platformer/Breakables/CagedAnimals/CagedAnimal.h"

namespace cocos2d
{
	class Sprite;
};

class CagedWhale : public CagedAnimal
{
public:
	static CagedWhale* create(cocos2d::ValueMap& initProperties);

	static const std::string MapKeyCagedWhale;

protected:
	CagedWhale(cocos2d::ValueMap& initProperties);
	~CagedWhale();

	void initializePositions() override;

	LocalizedString* getAnimalName() override;
	std::string getSpriteResource() override;

private:
	typedef CagedAnimal super;

	cocos2d::Sprite* animalSprite;
};
