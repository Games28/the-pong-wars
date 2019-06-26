#include "LightSabers.h"

LightSaber::LightSaber(Vec2& in_loc)
	:
	loc(in_loc),
    color{ { 0,0,0 },{ 0,0,0 } }
{
	Draw[0] = &ArtSaber::DrawUpLeft;
	Draw[1] = &ArtSaber::DrawDownLeft;
	Draw[2] = &ArtSaber::DrawUpRight;
	Draw[3] = &ArtSaber::DrawDownRight;
}





void LightSaber::Move(Vec2 moveAmount)
{
	loc += moveAmount;
}

