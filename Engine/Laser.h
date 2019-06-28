#pragma once

#include"Graphics.h"
#include"Vec2.h"
#include "ArtLaser.h"
#include <random>
#include <math.h>
#include "Collider.h"
using namespace std;
class Laser
{
public:
	Laser(Vec2& loc);
	Laser(Vec2& loc, std::mt19937& rng);
	
	
	//interaction
	void Respawn(Vec2& in_loc, std::mt19937& rng);
	void DrawLaser(Graphics& gfx);
	void DrawRemote(Graphics& gfx);
	void update();
	Vec2 getVel();
	void ReboundY();
	float getboltWidth();
	float getboltHeight();
	
	
public:
	Collider collider;
	void (ArtLaser::* DrawBolt)(int, int, Graphics&);
	float Boltwidth = 50;
	float Boltheight = 15;
	Vec2 loc;
	Vec2 vel;
	bool isVaporized = false;
};
