#include "CollisionManager.h"

bool CollisionManager::Contains(Collider& outer, Collider& inner)
{

	bool IsInside = false;
	if (inner.loc.x					> outer.loc.x && 
		inner.loc.x + inner.size.x	< outer.loc.x + outer.size.x && 
		inner.loc.y					> outer.loc.y && 
		inner.loc.y + inner.size.y	< outer.loc.y + outer.size.y)
	{
		

		IsInside = true;
				
	}
	return IsInside;
}
