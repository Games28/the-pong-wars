#include "Character.h"

Character::Character(Vec2 &head_loc, Vec2 & robe_loc, Vec2& saber_loc)
	:
	lightSaber(saber_loc)
{
	loc.head = head_loc;
	loc.robe = robe_loc;
	lightSaber.loc = saber_loc;
	lightSaber.DrawSaber[0] = 0;
	lightSaber.DrawSaber[1] = 0;

	
}

void Character::Move(Vec2 moveAmount)
{
	loc.head += moveAmount;
	loc.robe += moveAmount;
	lightSaber.Move(moveAmount);
}

void Character::Draw(Graphics& gfx)
{
	(gfx.robes.*(DrawRobe))((int)loc.robe.x, (int)loc.robe.y, gfx);
	(gfx.heads.*(DrawHead))((int)loc.head.x, (int)loc.head.y, gfx);
	if (lightSaber.isSelected)
	{
		if (lightSaber.isdown)
		{
			(gfx.saber.*(lightSaber.Draw[1]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
		}
		else
		{
			(gfx.saber.*(lightSaber.Draw[0]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
		}
	}
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