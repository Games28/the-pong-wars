#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "Stars.h"
#include <random>

class Background
{
public:
	Background(Graphics& gfx);
	void Midline(Graphics& gfx) const;
	void Throne(Graphics& gfx) const;
	void Thestars(Graphics& gfx);
	void Window(Graphics& gfx);
	void Theemperor(Graphics& gfx);
private:
	std::mt19937 rng;
	static constexpr int maxRegularStars = 20;
	Stars Regularstars[maxRegularStars];
	static constexpr int maxBrightStars = 15;
	Stars Brightstars[maxBrightStars];
	int BrightStarresetMax = 100;
	int BrightStarCounter = 0;
	static constexpr int height = 4;
	static constexpr int ChairH = 50;
	Graphics& gfx;
	Color c = Colors::White;
	Vec2 loc;
	Stars star;

	//range x - 350 to 550 y - 150 to 250
};