#include "Monitor.h"

Monitor* Monitor::create(std::string dialogFile)
{
	Monitor* monitor = new Monitor(dialogFile);

	monitor->autorelease();

	return monitor;
}

Monitor::Monitor(std::string dialogFile)
{
	this->monitorDialog = DialogMenu::loadDialogFromFile(dialogFile);
	this->monitorDialog->retain();

	this->monitorSpriteFloating = FloatingSprite::create(Resources::Ingame_Objects_Monitor, Vec2(2.0f, 24.0f), Vec2(7.0f, 7.0f));
	this->monitorSprite = MenuSprite::create(this->monitorSpriteFloating, Resources::Ingame_Objects_MonitorSelected, Resources::Ingame_Objects_MonitorSelected);
	this->monitorParticles = ParticleSystemQuad::create(Resources::Particles_Spark);
	this->monitorParticlesBack = ParticleSystemQuad::create(Resources::Particles_Spark);
	this->monitorSparkles = ParticleSystemQuad::create(Resources::Particles_Sparkles);

	this->monitorParticles->setPositionType(ParticleSystem::PositionType::GROUPED);
	this->monitorParticlesBack->setPositionType(ParticleSystem::PositionType::GROUPED);
	this->monitorSparkles->setPositionType(ParticleSystem::PositionType::GROUPED);

	this->monitorSprite->setClickCallback(CC_CALLBACK_1(Monitor::onMonitorClick, this));

	FloatingSprite* sprite = this->monitorSpriteFloating;
	ParticleSystem* particles = this->monitorParticles;
	ParticleSystem* particlesBack = this->monitorParticlesBack;

	CallFunc* triggerParticles = CallFunc::create([sprite, particles]()
	{
		particles->setSourcePosition(sprite->getPosition() + Vec2(-96.0f, -72.0f));
		particles->start();
	});

	CallFunc* triggerParticlesBack = CallFunc::create([sprite, particlesBack]()
	{
		particlesBack->setSourcePosition(sprite->getPosition() + Vec2(64.0f, 64.0f));
		particlesBack->start();
	});

	this->monitorParticles->setScale(0.25f);
	this->monitorParticles->runAction(RepeatForever::create(Sequence::create(triggerParticles, DelayTime::create(8.14f), nullptr)));

	this->monitorParticlesBack->setScale(0.7f);
	this->monitorParticlesBack->runAction(RepeatForever::create(Sequence::create(triggerParticlesBack, DelayTime::create(6.77f), nullptr)));

	this->addChild(this->monitorSparkles);
	this->addChild(this->monitorParticlesBack);
	this->addChild(this->monitorSprite);
	this->addChild(this->monitorParticles);
}

Monitor::~Monitor()
{
}

void Monitor::onMonitorClick(MenuSprite* menuSprite)
{
	this->getEventDispatcher()->dispatchCustomEvent(DialogMenu::DialogOpenEvent, &DialogMenu::DialogOpenArgs(this->monitorDialog));
}