#include "LightSabers.h"

LightSaber::LightSaber(Vec2& in_loc)
	:
	loc(in_loc)
{
	Draw[0] = &ArtSaber::DrawUp;
	Draw[1] = &ArtSaber::DrawDown;
}

void LightSaber::Move(Vec2 moveAmount)
{
	loc += moveAmount;
}

void LightSaber::P1Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 60)
	{
		loc.y = 60;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 165))
	{
		loc.y = float(Graphics::ScreenHeight - 165) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 155)
	{
		loc.x = 155;
	}
	else if (right >= float(Graphics::ScreenWidth - 420))
	{
		loc.x = float(Graphics::ScreenWidth - 420) - width;
	}
}

void LightSaber::P2Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 60)
	{
		loc.y = 60;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 165))
	{
		loc.y = float(Graphics::ScreenHeight - 165) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 450)
	{
		loc.x = 450;
	}
	else if (right >= float(Graphics::ScreenWidth - 110))
	{
		loc.x = float(Graphics::ScreenWidth - 110) - width;
	}
}
