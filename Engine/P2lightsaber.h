#pragma once
#include "Graphics.h"

class P2lightsaber
{
public:
	P2lightsaber(Vec2& in_loc);
	//up lightsabers
	void Upblue2(Graphics& gfx);
	void Upgreen2(Graphics& gfx);
	void Uppurple2(Graphics& gfx);
	void Upred2(Graphics& gfx);
	void Upwhite2(Graphics& gfx);
	//down lightsabers
	void Downblue2(Graphics& gfx);
	void Downgreen2(Graphics& gfx);
	void Downpurple2(Graphics& gfx);
	void Downred2(Graphics& gfx);
	void Downwhite2(Graphics& gfx);


private:
	static constexpr float width = 25;
	static constexpr float height = 200;
	Vec2 loc;
};
