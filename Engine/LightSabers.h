#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"

class LightSaber
{
public:
	LightSaber(Vec2& in_loc);

	//Player 1 Lightsabers up
	void Upblue1(Graphics& gfx);
	void Upgreen1(Graphics& gfx);
	void Uppurple1(Graphics& gfx);
	void Upred1(Graphics& gfx);
	void Upwhite1(Graphics& gfx);
	//player 1 lightsabers down
	void Downblue1(Graphics& gfx);
	void Downgreen1(Graphics& gfx);
	void Downpurple1(Graphics& gfx);
	void Downred1(Graphics& gfx);
	void Downwhite1(Graphics& gfx);
	
	// Player 2 lightsabers up
	void Upblue2(Graphics& gfx);
	void Upgreen2(Graphics& gfx);
	void Uppurple2(Graphics& gfx);
	void Upred2(Graphics& gfx);
	void Upwhite2(Graphics& gfx);
	//Player 2 lightsabers down
	void Downblue2(Graphics& gfx);
	void Downgreen2(Graphics& gfx);
	void Downpurple2(Graphics& gfx);
	void Downred2(Graphics& gfx);
	void Downwhite2(Graphics& gfx);
	
	// movement
	void P1MovementUpdate(Keyboard& kbd);
	void P2MovementUpdate(Keyboard& kbd);
	void P1Collision();
	void P2Collision();

private:
	static constexpr float width = 250.0f;
	static constexpr float height = 200.0f;
	Vec2 loc;
};