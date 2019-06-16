#pragma once
#include "Vec2.h"
class Graphics;

class ArtRobes
{
public:
	ArtRobes() = default;
	//player 1 robe
	void Robe1( int x,  int y, Graphics &gfx);
	void Robe1falling( int x,  int y, Graphics &gfx);
	void Robe1fallen( int x,  int y, Graphics &gfx);
	void Robe1Stand( int x,  int y, Graphics &gfx);
	void Robe1moveX( int x,  int y, Graphics &gfx);
	void Robe1moveY( int x,  int y, Graphics &gfx);

	//player 2 robe
	void Robe2( int x,  int y, Graphics &gfx);
	void Robe2falling( int x,  int y, Graphics &gfx);
	void Robe2fallen( int x,  int y, Graphics &gfx);
	void Robe2Stand( int x,  int y, Graphics &gfx);
	void Robe2moveX( int x,  int y, Graphics &gfx);
	void Robe2moveY( int x,  int y, Graphics &gfx);
};
