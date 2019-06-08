#pragma once
#include "Keyboard.h"
#include "Vec2.h"
#include "Graphics.h"

class Player2
{
public:
	Player2(Vec2& in_loc);
	//character heads
	void Leia2head(Graphics& gfx);
	void Luke2head(Graphics& gfx);
	void ahsoka2head(Graphics& gfx);
	void emperor2head(Graphics& gfx);
	void anakin2head(Graphics& gfx);
	void Marajade2head(Graphics& gfx);
	void Rey2head(Graphics& gfx);
	void Obiwan2head(Graphics& gfx);
	//robe
	void Robe2(Graphics& gfx);
	void Robe2falling(Graphics& gfx);
	void Robe2fallen(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& kbd);
	void collsion();
	

private:
	static constexpr float width = 38;
	static constexpr float height = 225;
	static constexpr float HeadWidth = 12;
	static constexpr float HeadHeight = 25;
	Vec2 loc;
};
