#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "HeadSelect.h"
#include "LightSabers.h"
#include "ArtHeads.h"

class Characters
{
public:
	Characters() = default;
	Characters(Vec2& player_loc, Vec2 &saber_loc);

	//movement
	void Move(Vec2 moveAmount);
	//void Player2Collision();
	//void Player1Collision();
	
private:
	static constexpr float width = 38;
	static constexpr float height = 225;
	
public:
	bool isSelected = false;
	Vec2 loc;
	void (ArtHeads::*DrawCharacter)(int, int, Graphics&);
	LightSaber lightSaber;
};
