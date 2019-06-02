#include "Laser.h"

Laser::Laser(Vec2 & in_loc)
	:
	loc(in_loc)
{
}

float Laser::getboltWidth()
{
	return Boltwidth;
}

float Laser::getboltHeight()
{
	return Boltheight;
}
