#include "LightSabers.h"

LightSaber::LightSaber(Vec2& in_loc)
	:
	loc(in_loc),
    color{ { 0,0,0 },{ 0,0,0 } },
	sizeUP(Vec2(20,175)),
	sizeDown(Vec2(20, 175))
	
{
	collider[0] = Collider::Collider(in_loc, sizeUP);
	collider[1] = Collider::Collider(in_loc, sizeUP);
	collider[2] = Collider::Collider(in_loc, sizeDown);
	collider[3] = Collider::Collider(in_loc, sizeDown);
	Draw[0] = &ArtSaber::DrawUpLeft;
	Draw[1] = &ArtSaber::DrawDownLeft;
	Draw[2] = &ArtSaber::DrawUpRight;
	Draw[3] = &ArtSaber::DrawDownRight;

}





void LightSaber::Move(Vec2 moveAmount)
{
	loc += moveAmount;
	for(int i = 0; i < 4; i++)
	{
		collider[i].loc = loc;
	}
}

