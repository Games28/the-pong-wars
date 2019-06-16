#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "HeadSelect.h"
#include "LightSabers.h"
#include "ArtHeads.h"
#include "ArtRobes.h"
#include "ArtSaber.h"

class Characters
{

public:
	Characters() = default;
	Characters(Vec2& head_loc, Vec2& robe_loc, Vec2& saber_loc);

	//movement
	void Move(Vec2 moveAmount);
	//void Player2Collision();
	//void Player1Collision();
	
private:
	static constexpr float width = 38;
	static constexpr float height = 225;

	struct ArtCoords
	{
		Vec2 head;
		Vec2 robe;
	};
	
public:
	
	ArtCoords loc;
	LightSaber lightSaber;

	bool isSelected = false;
	
	//Art
	void (ArtHeads::*DrawHead)(int, int, Graphics&);
	void (ArtRobes::*DrawRobe)(int, int, Graphics&);

	void Draw(Graphics& gfx, ArtHeads &artHead, ArtRobes & artRobe, ArtSaber &artSaber);
};
