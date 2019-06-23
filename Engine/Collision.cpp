#include "Collision.h"

Collision::Collision(const Vec2& loc, const Vec2& size)
{
	this->loc = loc;
	this->size = size;
}
void Collision::DrawBox(Graphics& gfx, Color c)
{
	
	gfx.DrawBox(loc, size, c);

}

void Collision::Move(Vec2& Amount)
{
	loc += Amount;
}

void Collision::Box()
{
	Vec2 Rightbottom = loc + size;

	if (loc.x - 10 < 500)
	{
		loc.x = 500;
	}
	else if (Rightbottom.x >= int(Graphics::ScreenWidth - 100))
	{
		loc.x = int(Graphics::ScreenWidth - 100) - size.x;
	}
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (Rightbottom.y >= int(Graphics::ScreenHeight - 50))
	{
		loc.y = int(Graphics::ScreenWidth - 50) - size.y;
	}
}