#pragma once

#include"Graphics.h"
#include"Vec2.h"
#include "ArtLaser.h"
#include <random>

class Laser
{
public:
	Laser(Vec2& loc);
	Laser(Vec2& loc, std::mt19937& rng);
	
	
	//interaction
	void Respawn(Vec2& in_loc, std::mt19937& rng);
	void DrawLaser(Graphics& gfx);
	void DrawRemote(Graphics& gfx);
	Vec2 getVel();
	void ReboundY();
	float getboltWidth();
	float getboltHeight();
	
	
public:
	
	static constexpr float Boltwidth = 50;
	static constexpr float Boltheight = 15;
	Vec2 loc;
	Vec2 vel;
	ArtLaser art;
	bool isVaporized = false;
};
