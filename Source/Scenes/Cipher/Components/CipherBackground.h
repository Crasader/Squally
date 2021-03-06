#pragma once

#include "Scenes/Cipher/Components/CipherComponentBase.h"

namespace cocos2d
{
	class Sprite;
}

class CipherBackground : public CipherComponentBase
{
public:
	static CipherBackground* create();

protected:
	void onAnyStateChange(CipherState* cipherState) override;

private:
	typedef CipherComponentBase super;
	CipherBackground();
	~CipherBackground();

	void onEnter() override;
	void initializePositions() override;

	cocos2d::Sprite* cipherBackground;
};
