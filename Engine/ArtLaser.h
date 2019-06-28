#pragma once
#include "Graphics.h"
class ArtLaser
{
public:
	ArtLaser() = default;
	void TrainingRemote( int x, int y, Graphics& gfx);
	void Mainbolt( int x, int y, Graphics& gfx);
	void Boltleft( int x, int y, Graphics& gfx);
	void Boltright( int x, int y, Graphics& gfx);
	//sparks
	void SparksLeft( int x, int y, Graphics& gfx);
	void SparksRight( int x, int y, Graphics& gfx);
	void SparksTop( int x, int y, Graphics& gfx);
	void SparksBottom( int x, int y, Graphics& gfx);
};

