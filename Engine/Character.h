#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"
#include "HeadSelect.h"
#include "LightSabers.h"
#include "ArtHeads.h"
#include "ArtRobes.h"
#include "ArtSaber.h"
#include "Collision.h"

class Character
{

public:
	Character() = default;
	Character(Vec2& head_loc, Vec2& robe_loc, Vec2& saber_loc);
	//void Collision();
	//movement
	void Move(Vec2 moveAmount);
	
	
private:
	static constexpr float width = 127;
	static constexpr float height = 245;

	struct ArtCoords
	{
		Vec2 head;
		Vec2 robe;
	
	};
	
public:
	Vec2 pos;
	ArtCoords artpos;
	LightSaber lightSaber;
	Collision collision;
	bool isSelected = false;
	
	//Art
	void (ArtHeads::*DrawHead)(int, int, Graphics&);
	void (ArtRobes::*DrawRobe)(int, int, Graphics&);

	void Draw(Graphics& gfx);
};
