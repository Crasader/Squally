#pragma once

enum class PlatformerCollisionType
{
	None				= 0,
	Physics				= 1 << 0,
	Solid				= 1 << 1,
	PassThrough			= 1 << 2,
	Entity				= 1 << 3,
	Player				= 1 << 4,
	PlayerHover			= 1 << 5,
	FriendlyNpc			= 1 << 6,
	Enemy				= 1 << 7,
	EnemyFlying			= 1 << 8,
	Force				= 1 << 9,
	SolidNpcOnly		= 1 << 10,
	SolidFlyingNpcOnly	= 1 << 11,
	Water				= 1 << 12,
	GroundDetector		= 1 << 13,
	WallDetector		= 1 << 14,
	PlayerWeapon		= 1 << 15,
	EnemyWeapon			= 1 << 16,
	Breakable			= 1 << 17,
	Damage				= 1 << 18,
	Collectable			= 1 << 19,
	Trigger				= 1 << 20,
};