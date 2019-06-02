#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int x, int y)
		:
		x(x),
		y(y)
	{}
	int GetLevel()
	{
		return level;
	}
	void IncreaseLevel()
	{
		++level;
	}
	void Draw(Graphics& gfx)
	{
		gfx.DrawRectDim(x, y, level * depth, girth, c);
	}
private:
	static constexpr Color c = Colors::Blue;
	static constexpr int girth = 12;
	static constexpr int depth = 4;
	int level = 0;
	int x;
	int y;
};
