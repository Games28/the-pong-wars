#pragma once
#include "Collider.h"
class CollisionManager
{
public:
	CollisionManager() = default;
	bool Contains(Collider& outer, Collider& inner);
};

