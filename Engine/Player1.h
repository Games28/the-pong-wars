#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"


class Player1
{
public:
	Player1(Vec2& in_loc);
	
	//robe
	void Robe1(Graphics& gfx);
	void Robe1falling(Graphics& gfx);
	void Robe1fallen(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& kbd);
	void Collision();
	

private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	Vec2 loc;
};
