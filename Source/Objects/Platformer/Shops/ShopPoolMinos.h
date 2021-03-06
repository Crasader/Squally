#pragma once

#include "Objects/Platformer/Shops/ShopPool.h"

class ShopPoolMinos : public ShopPool
{
public:
	static ShopPoolMinos* create(cocos2d::ValueMap& properties);

	static const std::string MapKeyShopPoolMinos;
	static const std::string PoolName;

protected:
	ShopPoolMinos(cocos2d::ValueMap& properties);
	virtual ~ShopPoolMinos();
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef ShopPool super;
};
