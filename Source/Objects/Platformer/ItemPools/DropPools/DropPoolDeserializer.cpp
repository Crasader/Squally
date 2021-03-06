#include "DropPoolDeserializer.h"

#include "cocos/base/CCValue.h"

#include "Engine/Maps/GameObject.h"
#include "Objects/Platformer/ItemPools/DropPools/DropPools.h"

using namespace cocos2d;

const std::string DropPoolDeserializer::MapKeyTypeDropPool = "drop-pool";

DropPoolDeserializer* DropPoolDeserializer::create()
{
	DropPoolDeserializer* instance = new DropPoolDeserializer();

	instance->autorelease();

	return instance;
}

DropPoolDeserializer::DropPoolDeserializer() : super(DropPoolDeserializer::MapKeyTypeDropPool)
{
	this->deserializers = std::map<std::string, std::function<GameObject*(ValueMap)>>();
	
	this->deserializers[EmptyPool::PoolName] = [=](ValueMap properties) { return (GameObject*)EmptyPool::create(); };
	this->deserializers[ErrorPool::PoolName] = [=](ValueMap properties) { return (GameObject*)ErrorPool::create(); };

	// Endian forest drop pools
	this->deserializers[DropPoolEFGeneric::PoolName] = [=](ValueMap properties) { return (GameObject*)DropPoolEFGeneric::create(properties); };
}

DropPoolDeserializer::~DropPoolDeserializer()
{
}
