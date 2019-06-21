#pragma once
#include "Vec2.h"
#include "Graphics.h"

class Collision
{
public:
	Collision() = default;
	Collision(const Vec2& in_loc, const Vec2& in_size);
	void Box();
	void DrawBox(Graphics& gfx, Color c);
	void Move(Vec2& Amount);
private:
	Vec2 loc;
	Vec2 size;
};


