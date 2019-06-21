#include "Character.h"

Character::Character(Vec2 &head_loc, Vec2 & robe_loc, Vec2& saber_loc)
	:
	lightSaber(saber_loc),
	collision(head_loc,Vec2(100,227))
{
	artpos.head = head_loc;
	artpos.robe = robe_loc;
	lightSaber.loc = saber_loc;
	lightSaber.DrawSaber[0] = 0;
	lightSaber.DrawSaber[1] = 0;
	
	
}



void Character::Move(Vec2 moveAmount)
{
	artpos.head += moveAmount;
	artpos.robe += moveAmount;
	lightSaber.Move(moveAmount);
	//SPACE RESPECING DEBUG COLLISION CODE!
	 collision.Move(moveAmount);}

void Character::Draw(Graphics& gfx)
{
	(gfx.robes.*(DrawRobe))((int)artpos.robe.x, (int)artpos.robe.y, gfx);
	(gfx.heads.*(DrawHead))((int)artpos.head.x, (int)artpos.head.y, gfx);
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
	//SPACE RESPECING DEBUG COLLISION CODE!
	collision.DrawBox(gfx, Colors::Blue);
}


