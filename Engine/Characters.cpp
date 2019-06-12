#include "Characters.h"

Characters::Characters(Vec2 &player_loc, Vec2 &saber_loc)
	:
	loc(player_loc),
	lightSaber(saber_loc)
{
}

void Characters::Move(Vec2 moveAmount)
{
	loc += moveAmount;
	lightSaber.Move(moveAmount);
}



/*void Characters::Player2Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 100))
	{
		loc.y = float(Graphics::ScreenHeight - 100) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 460)
	{
		loc.x = 460;
	}
	else if (right >= float(Graphics::ScreenWidth - 100))
	{
		loc.x = float(Graphics::ScreenWidth - 100) - width;
	}
}

void Characters::Player1Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 100))
	{
		loc.y = float(Graphics::ScreenHeight - 100) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 50)
	{
		loc.x = 50;
	}
	else if (right >= float(Graphics::ScreenWidth - 530))
	{
		loc.x = float(Graphics::ScreenWidth - 530) - width;
	}
}
*/