#include "LessThanBlock.h"

#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCDirector.h"

#include "Engine/Input/ClickableNode.h"
#include "Scenes/Cipher/Config.h"

#include "Resources/CipherResources.h"

#include "Strings/Cipher/Operations/SHR.h"

using namespace cocos2d;

LessThanBlock* LessThanBlock::create(BlockType blockType)
{
	LessThanBlock* instance = new LessThanBlock(blockType);

	instance->autorelease();

	return instance;
}

LessThanBlock::LessThanBlock(BlockType blockType) : super(blockType, ConnectionType::Double, ConnectionType::Double, ClickableNode::create(CipherResources::Blocks_BlockDec, CipherResources::Blocks_BlockDec), CipherResources::Icons_LessThan, Strings::Cipher_Operations_SHR::create())
{
}

LessThanBlock::~LessThanBlock()
{
}

void LessThanBlock::onEnter()
{
	super::onEnter();
}

void LessThanBlock::initializePositions()
{
	super::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}

char LessThanBlock::compute()
{
	if (this->currentInputs.size() < 1)
	{
		return char(0);
	}

	return this->currentInputs[0];
}

BlockBase* LessThanBlock::spawn()
{
	return LessThanBlock::create();
}
