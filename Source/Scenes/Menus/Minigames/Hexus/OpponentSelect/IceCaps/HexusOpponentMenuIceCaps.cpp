#include "HexusOpponentMenuIceCaps.h"

HexusOpponentMenuIceCaps * HexusOpponentMenuIceCaps::create()
{
	HexusOpponentMenuIceCaps* instance = new HexusOpponentMenuIceCaps();

	instance->autorelease();

	return instance;
}

HexusOpponentMenuIceCaps::HexusOpponentMenuIceCaps() : HexusOpponentMenuBase(HexusChapterPreviewIceCaps::stringKeyChapterName)
{
	auto callback = CC_CALLBACK_1(HexusOpponentMenuIceCaps::onGameEndCallback, this);

	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));
	this->opponents.push_back(HexusOpponentPreview::create(HexusOpponentCentaur::getInstance(), callback));

	for (std::vector<HexusOpponentPreview*>::iterator it = this->opponents.begin(); it != this->opponents.end(); ++it)
	{
		this->scrollPane->addChild(*it);
	}
}

HexusOpponentMenuIceCaps::~HexusOpponentMenuIceCaps()
{
}