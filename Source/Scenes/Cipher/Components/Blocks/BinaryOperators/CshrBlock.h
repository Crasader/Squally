#pragma once

#include "Scenes/Cipher/Components/Blocks/BlockBase.h"

class CshrBlock : public BlockBase
{
public:
	static CshrBlock* create(BlockType blockType = BlockType::Normal);
	
protected:
	unsigned char compute() override;

private:
	typedef BlockBase super;
	CshrBlock(BlockType blockType);
	~CshrBlock();

	void onEnter() override;
	void initializePositions() override;
};
