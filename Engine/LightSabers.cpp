#include "LightSabers.h"

LightSaber::LightSaber(Vec2& in_loc)
	:
	loc(in_loc),
    color{ { 0,0,0 },{ 0,0,0 } },
	sizeUP(Vec2(20,175)),
	sizeDown(Vec2(20, 175))
	
{
	//draws hilt and saber
	Draw[0] = &ArtSaber::DrawUpLeft;
	Draw[1] = &ArtSaber::DrawDownLeft;
	Draw[2] = &ArtSaber::DrawUpRight;
	Draw[3] = &ArtSaber::DrawDownRight;
	//draws collider box
	//colliders[0] = Collider(Vec2())


}





void LightSaber::Move(Vec2 moveAmount)
{
	loc += moveAmount;
	
}

