#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "LightsaberColor.h"
#include "ArtSaber.h"
#include "Collider.h"
#include "Colors.h"

class LightSaber
{
public:
	LightSaber() = default;
	LightSaber(Vec2& in_loc);


	// collision
	
	//void P1Collision();
	//void P2Collision();

public:
	static constexpr float width = 25;
	static constexpr float height = 200;
	Vec2 sizeUP;
	Vec2 sizeDown;
	
public:
	//int operator++(int x);
	int length = 0;
	bool isSelected1 = false;
	bool isSelected2 = false;
	bool isdown = false;
	Vec2 loc;
	Collider collider[4];
	Color color[2];
	LightsaberColor saberColor = LightsaberColor::DEFAULT;

	void LightSaber::Move(Vec2 moveAmount);

	void (ArtSaber::* Draw[4])(int, int, int, Color*, Graphics&);
	void (ArtSaber::* DrawSaber[2])(int, int, Graphics&);
};