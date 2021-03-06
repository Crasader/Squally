#include "CardEffects.h"

#include "cocos/2d/CCParticleSystemQuad.h"
#include "cocos/base/CCDirector.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"

#include "Scenes/Hexus/Config.h"

#include "Resources/ParticleResources.h"

using namespace cocos2d;

CardEffects* CardEffects::create()
{
	CardEffects* instance = new CardEffects();

	instance->autorelease();

	return instance;
}

CardEffects::CardEffects()
{
	this->bite = nullptr;
	this->dustPoof = nullptr;
	this->dustStorm = nullptr;
	this->fireBlast = nullptr;
	this->flow = nullptr;
	this->focusRing = nullptr;
	this->frostCircle = nullptr;
	this->gush = nullptr;
	this->lightning = nullptr;
	this->magicBurst = nullptr;
	this->meteorAlt = nullptr;
	this->meteorBlue = nullptr;
	this->meteorPurple = nullptr;
	this->nether = nullptr;
	this->poison = nullptr;
	this->radialAura = nullptr;
	this->radialFire = nullptr;
	this->radialGalaxy = nullptr;
	this->radialStorm = nullptr;
	this->selectionPulse = nullptr;
	this->spinningMagic = nullptr;
	this->splash = nullptr;
	this->starBurst = nullptr;
	this->starHit = nullptr;
	this->targetPulse = nullptr;
}

CardEffects::~CardEffects()
{
}

void CardEffects::onEnter()
{
	super::onEnter();

	this->clearEffects();
}

void CardEffects::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}

void CardEffects::initializeListeners()
{
	super::initializeListeners();
}

void CardEffects::runEffect(CardEffect effect)
{
	this->clearEffects();

	switch (effect)
	{
		case CardEffect::Bite:
		{
			this->getBite()->resumeEmissions();
			this->getBite()->start();
			break;
		}
		case CardEffect::DustPoof:
		{
			this->getDustPoof()->resumeEmissions();
			this->getDustPoof()->start();
			break;
		}
		case CardEffect::DustStorm:
		{
			this->getDustStorm()->resumeEmissions();
			this->getDustStorm()->start();
			break;
		}
		case CardEffect::FireBlast:
		{
			this->getFireBlast()->resumeEmissions();
			this->getFireBlast()->start();
			break;
		}
		case CardEffect::Flow:
		{
			this->getFlow()->resumeEmissions();
			this->getFlow()->start();
			break;
		}
		case CardEffect::FocusRing:
		{
			this->getFocusRing()->setVisible(true);
			this->getFocusRing()->resumeEmissions();
			this->getFocusRing()->start();
			break;
		}
		case CardEffect::FrostCirlce:
		{
			this->getFrostCircle()->resumeEmissions();
			this->getFrostCircle()->start();
			break;
		}
		case CardEffect::Gush:
		{
			this->getGush()->resumeEmissions();
			this->getGush()->start();
			break;
		}
		case CardEffect::Lightning:
		{
			this->getLightning()->resumeEmissions();
			this->getLightning()->start();
			break;
		}
		case CardEffect::MagicBurst:
		{
			this->getMagicBurst()->resumeEmissions();
			this->getMagicBurst()->start();
			break;
		}
		case CardEffect::MeteorAlt:
		{
			this->getMeteorAlt()->resumeEmissions();
			this->getMeteorAlt()->start();
			break;
		}
		case CardEffect::MeteorBlue:
		{
			this->getMeteorBlue()->resumeEmissions();
			this->getMeteorBlue()->start();
			break;
		}
		case CardEffect::MeteorPurple:
		{
			this->getMeteorPurple()->resumeEmissions();
			this->getMeteorPurple()->start();
			break;
		}
		case CardEffect::Nether:
		{
			this->getNether()->resumeEmissions();
			this->getNether()->start();
			break;
		}
		case CardEffect::Poison:
		{
			this->getPoison()->resumeEmissions();
			this->getPoison()->start();
			break;
		}
		case CardEffect::RadialAura:
		{
			this->getRadialAura()->resumeEmissions();
			this->getRadialAura()->start();
			break;
		}
		case CardEffect::RadialFire:
		{
			this->getRadialFire()->resumeEmissions();
			this->getRadialFire()->start();
			break;
		}
		case CardEffect::RadialGalaxy:
		{
			this->getRadialGalaxy()->resumeEmissions();
			this->getRadialGalaxy()->start();
			break;
		}
		case CardEffect::RadialStorm:
		{
			this->getRadialStorm()->resumeEmissions();
			this->getRadialStorm()->start();
			break;
		}
		case CardEffect::SelectionPulse:
		{
			this->getSelectionPulse()->setVisible(true);
			this->getSelectionPulse()->runAction(RepeatForever::create(Sequence::create(
				CallFunc::create([=]()
				{
					this->getSelectionPulse()->resumeEmissions();
					this->getSelectionPulse()->start();
				}),
				DelayTime::create(1.5f),
				nullptr
			)));

			break;
		}
		case CardEffect::SpinningMagic:
		{
			this->getSpinningMagic()->resumeEmissions();
			this->getSpinningMagic()->start();
			break;
		}
		case CardEffect::Splash:
		{
			this->getSplash()->resumeEmissions();
			this->getSplash()->start();
			break;
		}
		case CardEffect::StarBurst:
		{
			this->getStarBurst()->resumeEmissions();
			this->getStarBurst()->start();
			break;
		}
		case CardEffect::StarHit:
		{
			this->getStarHit()->resumeEmissions();
			this->getStarHit()->start();
			break;
		}
		case CardEffect::TargetPulse:
		{
			this->getTargetPulse()->setVisible(true);
			this->getTargetPulse()->resumeEmissions();
			this->getTargetPulse()->start();

			break;
		}
		default:
		{
			break;
		}
	}
}

void CardEffects::clearEffects()
{
	if (this->focusRing != nullptr)
	{
		this->getFocusRing()->setVisible(false);
		this->getFocusRing()->stopAllActions();
		this->getFocusRing()->stopSystem();
	}

	if (this->selectionPulse != nullptr)
	{
		this->getSelectionPulse()->setVisible(false);
		this->getSelectionPulse()->stopAllActions();
		this->getSelectionPulse()->stopSystem();
	}

	if (this->targetPulse != nullptr)
	{
		this->getTargetPulse()->setVisible(false);
		this->getTargetPulse()->stopAllActions();
		this->getTargetPulse()->stopSystem();
	}
}

ParticleSystemQuad* CardEffects::getBite()
{
	if (this->bite == nullptr)
	{
		this->bite = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Bite);

		this->bite->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->bite->stopSystem();

		this->addChild(this->bite);
	}

	return this->bite;
}

ParticleSystemQuad* CardEffects::getDustPoof()
{
	if (this->dustPoof == nullptr)
	{
		this->dustPoof = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_DustPoof);

		this->dustPoof->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->dustPoof->stopSystem();

		this->addChild(this->dustPoof);
	}

	return this->dustPoof;
}

ParticleSystemQuad* CardEffects::getDustStorm()
{
	if (this->dustStorm == nullptr)
	{
		this->dustStorm = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_DustStorm);

		this->dustStorm->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->dustStorm->stopSystem();

		this->addChild(this->dustStorm);
	}

	return this->dustStorm;
}

ParticleSystemQuad* CardEffects::getFireBlast()
{
	if (this->fireBlast == nullptr)
	{
		this->fireBlast = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_FireBlast);

		this->fireBlast->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->fireBlast->stopSystem();

		this->addChild(this->fireBlast);
	}

	return this->fireBlast;
}

ParticleSystemQuad* CardEffects::getFlow()
{
	if (this->flow == nullptr)
	{
		this->flow = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Flow);

		this->flow->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->flow->stopSystem();

		this->addChild(this->flow);
	}

	return this->flow;
}

ParticleSystemQuad* CardEffects::getFocusRing()
{
	if (this->focusRing == nullptr)
	{
		this->focusRing = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_FocusRing);

		this->focusRing->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->focusRing->stopSystem();

		// This is an infinite particle effect, needs to be hidden
		this->focusRing->setVisible(false);

		this->addChild(this->focusRing);
	}

	return this->focusRing;
}

ParticleSystemQuad* CardEffects::getFrostCircle()
{
	if (this->frostCircle == nullptr)
	{
		this->frostCircle = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_FrostCircle);

		this->frostCircle->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->frostCircle->stopSystem();

		this->addChild(this->frostCircle);
	}

	return this->frostCircle;
}

ParticleSystemQuad* CardEffects::getGush()
{
	if (this->gush == nullptr)
	{
		this->gush = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Gush);

		this->gush->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->gush->stopSystem();

		this->addChild(this->gush);
	}

	return this->gush;
}

ParticleSystemQuad* CardEffects::getLightning()
{
	if (this->lightning == nullptr)
	{
		this->lightning = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Lightning);

		this->lightning->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->lightning->stopSystem();

		this->addChild(this->lightning);
	}

	return this->lightning;
}

ParticleSystemQuad* CardEffects::getMagicBurst()
{
	if (this->magicBurst == nullptr)
	{
		this->magicBurst = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_MagicBurst);

		this->magicBurst->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->magicBurst->stopSystem();

		this->addChild(this->magicBurst);
	}

	return this->magicBurst;
}

ParticleSystemQuad* CardEffects::getMeteorAlt()
{
	if (this->meteorAlt == nullptr)
	{
		this->meteorAlt = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_MeteorAlt);

		this->meteorAlt->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->meteorAlt->stopSystem();

		this->addChild(this->meteorAlt);
	}

	return this->meteorAlt;
}

ParticleSystemQuad* CardEffects::getMeteorBlue()
{
	if (this->meteorBlue == nullptr)
	{
		this->meteorBlue = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_MeteorBlue);

		this->meteorBlue->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->meteorBlue->stopSystem();

		this->addChild(this->meteorBlue);
	}

	return this->meteorBlue;
}

ParticleSystemQuad* CardEffects::getMeteorPurple()
{
	if (this->meteorPurple == nullptr)
	{
		this->meteorPurple = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_MeteorPurple);

		this->meteorPurple->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->meteorPurple->stopSystem();

		this->addChild(this->meteorPurple);
	}

	return this->meteorPurple;
}

ParticleSystemQuad* CardEffects::getNether()
{
	if (this->nether == nullptr)
	{
		this->nether = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Nether);

		this->nether->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->nether->stopSystem();

		this->addChild(this->nether);
	}

	return this->nether;
}

ParticleSystemQuad* CardEffects::getPoison()
{
	if (this->poison == nullptr)
	{
		this->poison = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Poison);

		this->poison->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->poison->stopSystem();

		this->addChild(this->poison);
	}

	return this->poison;
}

ParticleSystemQuad* CardEffects::getRadialAura()
{
	if (this->radialAura == nullptr)
	{
		this->radialAura = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_RadialAura);

		this->radialAura->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->radialAura->stopSystem();

		this->addChild(this->radialAura);
	}

	return this->radialAura;
}

ParticleSystemQuad* CardEffects::getRadialFire()
{
	if (this->radialFire == nullptr)
	{
		this->radialFire = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_RadialFire);

		this->radialFire->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->radialFire->stopSystem();

		this->addChild(this->radialFire);
	}

	return this->radialFire;
}

ParticleSystemQuad* CardEffects::getRadialGalaxy()
{
	if (this->radialGalaxy == nullptr)
	{
		this->radialGalaxy = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_RadialGalaxy);

		this->radialGalaxy->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->radialGalaxy->stopSystem();

		this->addChild(this->radialGalaxy);
	}

	return this->radialGalaxy;
}

ParticleSystemQuad* CardEffects::getRadialStorm()
{
	if (this->radialStorm == nullptr)
	{
		this->radialStorm = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_RadialStorm);

		this->radialStorm->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->radialStorm->stopSystem();

		this->addChild(this->radialStorm);
	}

	return this->radialStorm;
}

ParticleSystemQuad* CardEffects::getSelectionPulse()
{
	if (this->selectionPulse == nullptr)
	{
		this->selectionPulse = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_SelectionPulse);

		this->selectionPulse->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->selectionPulse->stopSystem();

		this->addChild(this->selectionPulse);
	}

	return this->selectionPulse;
}

ParticleSystemQuad* CardEffects::getSpinningMagic()
{
	if (this->spinningMagic == nullptr)
	{
		this->spinningMagic = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_SpinningMagic);

		this->spinningMagic->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->spinningMagic->stopSystem();

		this->addChild(this->spinningMagic);
	}

	return this->spinningMagic;
}

ParticleSystemQuad* CardEffects::getSplash()
{
	if (this->splash == nullptr)
	{
		this->splash = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_Splash);

		this->splash->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->splash->stopSystem();

		this->addChild(this->splash);
	}

	return this->splash;
}

ParticleSystemQuad* CardEffects::getStarBurst()
{
	if (this->starBurst == nullptr)
	{
		this->starBurst = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_StarBurst);

		this->starBurst->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->starBurst->stopSystem();

		this->addChild(this->starBurst);
	}

	return this->starBurst;
}

ParticleSystemQuad* CardEffects::getStarHit()
{
	if (this->starHit == nullptr)
	{
		this->starHit = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_StarHit);

		this->starHit->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->starHit->stopSystem();

		this->addChild(this->starHit);
	}

	return this->starHit;
}

ParticleSystemQuad* CardEffects::getTargetPulse()
{
	if (this->targetPulse == nullptr)
	{
		this->targetPulse = ParticleSystemQuad::create(ParticleResources::Hexus_CardEffects_TargetPulse);

		this->targetPulse->setPositionType(ParticleSystem::PositionType::GROUPED);
		this->targetPulse->stopSystem();

		this->addChild(this->targetPulse);
	}

	return this->targetPulse;
}
