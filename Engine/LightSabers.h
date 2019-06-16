#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "LightsaberColor.h"
#include "ArtSaber.h"

class LightSaber
{
public:
	LightSaber() = default;
	LightSaber(Vec2& in_loc);


	
	// collision
	void P1Collision();
	void P2Collision();

private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	
public:
	bool isSelected = false;
	bool isdown = false;
	Vec2 loc;
	LightsaberColor saberColor = LightsaberColor::DEFAULT;
	void LightSaber::Move(Vec2 moveAmount);
	void (ArtSaber::* DrawSaber[2])(int, int, Graphics&);
};