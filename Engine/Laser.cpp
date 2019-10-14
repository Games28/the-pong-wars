#include "Laser.h"

Laser::Laser(Vec2& loc)
{
	this->loc = loc;

}

Laser::Laser(Vec2 & loc, std::mt19937& rng)
	:
	collider(loc,Vec2(50,15))
{
	Respawn(loc, rng);
	//DrawSpark = 0;
	DrawBolt = &ArtLaser::Boltleft;
}







void Laser::Respawn(Vec2& in_loc, std::mt19937& rng)
{
	float Pi = 3.14159;
	float LeftUp = Pi * 3.0f * 0.25f;
	float LeftDown = Pi * 5.0f * 0.25f;
	float RightUp = Pi * 0.25f;
	float RightUpMiddle = 0.0f;
	float RightDownMiddle = Pi * 7.0f * 0.25f;
	float RightDown = Pi * 6.0f * 0.25f;
	
	loc = in_loc;
	float cosUp = cos(LeftUp);
	float cosDown = cos(LeftDown);
	float sinUp = sin(LeftUp);
	float sinDown = sin(LeftDown);
	

std::uniform_real_distribution<float> Angle;
	std::uniform_int_distribution<int> selection(1, 2);
	
	Angle = std::uniform_real_distribution<float>(LeftUp, LeftDown);
	float angle = Angle(rng);
	Vec2 newVel;

	newVel.x = cos(angle);
	newVel.y = sin(angle);
	
	
	if (selection(rng) == 1)
	{
		newVel *= -1.0f;
	}
	
	
    
	//if (newVel.x == 0.0f || newVel.y == 0.0f)
	//{ 
	//	newVel.x = Xdist(rng);
	//	newVel.y = Ydist(rng);
	//	
	//}
	//else {
		vel = newVel;
	//}
	loc += vel;
}

void Laser::DrawLaser(Graphics& gfx)
{
	
	(gfx.laser.*(DrawBolt))((int)loc.x, (int)loc.y, gfx);
	collider.DrawBox(gfx, Colors::Green);
	
}

void Laser::DrawRemote(Graphics& gfx)
{
	gfx.laser.TrainingRemote((int)loc.x, (int)loc.y, gfx);
}

void Laser::update()
{
	loc += vel * 10.0f;
	if (vel.x < 0.0f)
	{
		DrawBolt = &ArtLaser::Boltleft;
	}
	else {
		DrawBolt = &ArtLaser::Boltright;
	}
	collider.loc = loc;
}

Vec2 Laser::getVel()
{
	return vel;
}

void Laser::Rebound()
{
	//if (&Bolt.boltSparks)
	//{
	//	Bolt.boltSparks(gfx);
	//}
	if (loc.x <= 0)
	{
		
		//DrawSpark = &ArtLaser::SparksLeft;
		vel.x = -vel.x;
	}
	if (loc.x + Boltwidth >= (int)Graphics::ScreenWidth - 1)
	{
		
		//DrawSpark = &ArtLaser::SparksRight;
		vel.x = -vel.x;
	}
	if (loc.y <= 0)
	{
		
		//DrawSpark = &ArtLaser::SparksTop;
		vel.y = -vel.y;
	}
	 if (loc.y + Boltheight >= (int)Graphics::ScreenHeight - 1)
	{
		
		//DrawSpark = &ArtLaser::SparksBottom;
		vel.y = -vel.y;
	}
}

void Laser::boltSparks(Graphics& gfx)
{

	(gfx.laser.*(DrawSpark))((int)loc.x, (int)loc.y, gfx);
}






