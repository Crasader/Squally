#include "ObeliskNpcDeserializer.h"

ObeliskNpcDeserializer::ObeliskNpcDeserializer()
{
}

ObeliskNpcDeserializer::~ObeliskNpcDeserializer()
{
}

void ObeliskNpcDeserializer::onDeserializationRequest(ObjectDeserializationRequestArgs* args)
{
	ValueMap properties = args->properties;
	std::string name = properties.at(SerializableObject::KeyName).asString();
	SerializableObject* newEntity = nullptr;

	if (name == Amelia::MapKeyNpcAmelia)
	{
		newEntity = Amelia::deserialize(&properties);
	}
	else if (name == Azmus::MapKeyNpcAzmus)
	{
		newEntity = Azmus::deserialize(&properties);
	}
	else if (name == Garrick::MapKeyNpcGarrick)
	{
		newEntity = Garrick::deserialize(&properties);
	}
	else if (name == Johann::MapKeyNpcJohann)
	{
		newEntity = Johann::deserialize(&properties);
	}
	else if (name == Necron::MapKeyNpcNecron)
	{
		newEntity = Necron::deserialize(&properties);
	}
	else if (name == PrincessNebea::MapKeyNpcPrincessNebea)
	{
		newEntity = PrincessNebea::deserialize(&properties);
	}
	else if (name == Roger::MapKeyNpcRoger)
	{
		newEntity = Roger::deserialize(&properties);
	}
	else if (name == Thion::MapKeyNpcThion)
	{
		newEntity = Thion::deserialize(&properties);
	}
	else if (name == Ursula::MapKeyNpcUrsula)
	{
		newEntity = Ursula::deserialize(&properties);
	}
	else if (name == Viper::MapKeyNpcViper)
	{
		newEntity = Viper::deserialize(&properties);
	}
	else if (name == Zana::MapKeyNpcZana)
	{
		newEntity = Zana::deserialize(&properties);
	}

	if (newEntity != nullptr)
	{
		// Fire an event indicating successful deserialization
		args->callback(newEntity);
	}
}