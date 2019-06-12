#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "LightsaberColor.h"

class LightSaber
{
public:
	LightSaber() = default;
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
	
	// collision
	void P1Collision();
	void P2Collision();

private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	Vec2 loc;
public:
	bool isSelected = false;
	LightsaberColor saberColor = LightsaberColor::DEFAULT;
	void LightSaber::Move(Vec2 moveAmount);
	void (LightSaber::*DrawLightSaber)(Graphics&);
};