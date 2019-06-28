#include "Laser.h"

Laser::Laser(Vec2& loc)
{
	this->loc = loc;
}

Laser::Laser(Vec2 & loc, std::mt19937& rng)
{
	Respawn(loc, rng);
}







void Laser::Respawn(Vec2& in_loc, std::mt19937& rng)
{
	loc += vel;
	std::uniform_real_distribution<float> Xdist(-1.5f, 1.5f);
	std::uniform_real_distribution<float> Ydist(-1.5f, 1.5f);
	Vec2 newVel;
	newVel.x = Xdist(rng);
	newVel.y = Ydist(rng);
	if (newVel.x == 0.0f || newVel.y == 0.0f)
	{ 
		newVel.x = Xdist(rng);
		newVel.y = Ydist(rng);
		
	}
	else {
		vel = newVel;
	}
}

void Laser::DrawLaser(Graphics& gfx)
{
	art.Mainbolt(loc.x, loc.y, gfx);
	
}

void Laser::DrawRemote(Graphics& gfx)
{
	art.TrainingRemote(loc.x, loc.y, gfx);
}

Vec2 Laser::getVel()
{
	return vel;
}

void Laser::ReboundY()
{
	vel.y = -vel.y;
}

float Laser::getboltWidth()
{
	return Boltwidth;
}

float Laser::getboltHeight()
{
	return Boltheight;
}




