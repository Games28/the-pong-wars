#pragma once
#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"

class P2Head
{
public:
	P2Head(Vec2& in_loc);
	//character heads
	void Leia2head(Graphics& gfx);
	void Luke2head(Graphics& gfx);
	void ahsoka2head(Graphics& gfx);
	void emperor2head(Graphics& gfx);
	void anakin2head(Graphics& gfx);
	void Marajade2head(Graphics& gfx);
	void Rey2head(Graphics& gfx);
	void Obiwan2head(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& kbd);
	void Collision();

private:
	static constexpr float width = 70;
	static constexpr float height = 50;
	Vec2 loc;
};
