#pragma once

#include"Graphics.h"
#include"Vec2.h"

class Laser
{
public:
	Laser(Vec2& in_loc,Vec2& in_vel);
	Laser(Vec2& in_loc);
	void TrainingRemote(Graphics& gfx);
	void Mainbolt(Graphics& gfx);
	void Boltleft(Graphics& gfx);
	void Boltright(Graphics& gfx);
	//sparks
	void SparksLeft(Graphics& gfx);
	void SparksRight(Graphics& gfx);
	void SparksTop(Graphics& gfx);
	void SparksBottom(Graphics& gfx);
	//interaction
	void WallCollision(Graphics& gfx);
	Vec2 getVel();
	void ReboundY();
	float getboltWidth();
	float getboltHeight();
	
	
private:
	static constexpr float Boltwidth = 50;
	static constexpr float Boltheight = 15;
	Vec2 loc;
	Vec2 vel;
	bool isVaporized = false;
};
