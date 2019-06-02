#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class P1Head
{
public:
	P1Head(Vec2& in_loc);
	//character heads
	void Leia1head(Graphics& gfx);
	void Luke1head(Graphics& gfx);
	void ahsoka1head(Graphics& gfx);
	void emperor1head(Graphics& gfx);
	void anakin1head(Graphics& gfx);
	void Marajade1head(Graphics& gfx);
	void Rey1head(Graphics& gfx);
	void Obiwan1head(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& kbd);
	void Collision();

private:
	static constexpr float width = 70;
	static constexpr float height = 50;
	Vec2 loc;
};
