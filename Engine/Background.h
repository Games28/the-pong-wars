#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Stars.h"
#include "ArtBackground.h"
#include "Collision.h"
#include "Colors.h"
#include <random>

class Background
{
public:
	Background() = default;
	Background(Graphics& gfx);
	void Midline(Graphics& gfx);
	void Throne(Graphics& gfx);
	void Thestars(Graphics& gfx);
	void Window(Graphics& gfx);
	void SaberColorChange();
	void EmperorThroneRoom(Graphics& gfx);
	Collision collide[2];
	
	
private:

	ArtBackground art;
	std::mt19937 rng;
	static constexpr int maxRegularStars = 20;
	Stars Regularstars[maxRegularStars] = {};
	static constexpr int maxBrightStars = 15;
	Stars Brightstars[maxBrightStars] = {};
	int BrightStarresetMax = 100;
	int BrightStarCounter = 0;
	static constexpr int height = 4;
	static constexpr int ChairH = 50;
	Graphics& gfx;
	Color c = Colors::White;
	Color R = { 127,0,0 };
	int BR = 255;
	int DR = 128;
	bool colorIncreasing = true;
	int ColorCounter = 0;
	int ColorReset = 100;
	Vec2 loc;
	Stars star;

	//range x - 350 to 550 y - 150 to 250
};