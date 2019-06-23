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
	if (lightSaber.isSelected1)
	{
		
		if (lightSaber.isdown)
		{
			(gfx.saber1.*(lightSaber.Draw[1]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
			
		}
		else
		{
			(gfx.saber1.*(lightSaber.Draw[0]))((int)lightSaber.loc.x, (int)lightSaber.loc.y, 
												lightSaber.length, lightSaber.color, gfx);
			

		}
		
	}
	if (lightSaber.isSelected2)
	{
		if (lightSaber.isdown)
		{
			(gfx.saber2.*(lightSaber.Draw[3]))((int)lightSaber.loc.x, (int)lightSaber.loc.y,
				lightSaber.length, lightSaber.color, gfx);
		}
		else
		{
			(gfx.saber2.*(lightSaber.Draw[2]))((int)lightSaber.loc.x, (int)lightSaber.loc.y,
				lightSaber.length, lightSaber.color, gfx);

		}
	}
	//SPACE RESPECING DEBUG COLLISION CODE!
	collision.DrawBox(gfx, Colors::Blue);
}

void Character::SaberColorChange()
{
	int Red = lightSaber.color.GetR();
	int Blue = lightSaber.color.GetB();
	int Green = lightSaber.color.GetG();

	

	if (ColorIncreasing)
	{
		
		if (Red && Green && Blue  >= 253)
		{
			ColorIncreasing = false;
		}
		else
		{
			lightSaber.color = Color(Red+1, Green+1, Blue+1 );
		}

	}
	else
	{
		if (Red && Green && Blue <= 127)
		{
			ColorIncreasing = true;
		}
		else
		{
			lightSaber.color = Color(Red-1, Green-1, Blue-1);
		}

	}
}