#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "Laser.h"
#include "Direction.h"

class P1lightsaber
{
public:
	P1lightsaber() = default;
	P1lightsaber(Vec2& in_loc);
	//up lightsabers
	void Upblue1(Graphics& gfx);
	void Upgreen1(Graphics& gfx);
	void Uppurple1(Graphics& gfx);
	void Upred1(Graphics& gfx);
	void Upwhite1(Graphics& gfx);
	//down lightsabers
	void Downblue1(Graphics& gfx);
	void Downgreen1(Graphics& gfx);
	void Downpurple1(Graphics& gfx);
	void Downred1(Graphics& gfx);
	void Downwhite1(Graphics& gfx);
	//movement
	void MovementUpdate(Keyboard& brd);
	void Collision();
	void BoltCollision(Laser& bolt);
	


private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	Vec2 loc;
	
	
	
};

