#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Menus
{
public:
	Menus(Graphics& in_gfx);
	void EmporerHand(Graphics& gfx);
	void EmporerDoit(Graphics& gfx);
	void EmporerSelect(Graphics& gfx);
	void Player1menu(Graphics& gfx);
	void Player2menu(Graphics& gfx);
	void MainMenu(Graphics& gfx);
	
private:
	Graphics& gfx;
	Vec2 loc;
};
