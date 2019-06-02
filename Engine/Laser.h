#pragma once

#include"Graphics.h"
#include"Vec2.h"

class Laser
{
public:
	Laser(Vec2& in_loc);
	float getboltWidth();
	float getboltHeight();

private:
	static constexpr float Boltwidth = 50;
	static constexpr float Boltheight = 15;
	

	Vec2 loc;
};
