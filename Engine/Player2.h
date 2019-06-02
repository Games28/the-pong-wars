#pragma once
#include "Keyboard.h"
#include "Vec2.h"
#include "Graphics.h"

class Player2
{
public:
	Player2(Vec2& in_loc);
	
	//robe
	void Robe2(Graphics& gfx);
	void Robe2falling(Graphics& gfx);
	void Robe2fallen(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& kbd);
	void collsion();
	

private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	static constexpr float HeadWidth = 12;
	static constexpr float HeadHeight = 25;
	Vec2 loc;
};
