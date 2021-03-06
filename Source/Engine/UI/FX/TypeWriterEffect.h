#pragma once
#include <functional>
#include <string>

class LocalizedLabel;

class TypeWriterEffect
{
public:
	static void runTypeWriterEffect(LocalizedLabel* label, std::function<void()> onEffectFinishedCallback = nullptr, float delayPerLetter = TypeWriterEffect::DefaultDelayPerLetter);
	static void cancelEffect(LocalizedLabel* label);

private:
	static const float DefaultDelayPerLetter;
};
