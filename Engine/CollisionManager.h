#pragma once
#include "Collider.h"
class CollisionManager
{
public:
	CollisionManager() = default;
	bool Contains(Collider& inner, Collider& outer);
	Vec2 GetInnerReflection(Collider& collider, Collider& other);
	bool ReboundTestbool(Collider& object1, Collider& object2);
};

