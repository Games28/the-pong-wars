#pragma once
class Graphics;
class Color;
class ArtSaber
{
public:
	ArtSaber() = default;
	//Updated Saber Draw length
	void DrawUpLeft(int x, int y, int length, Color c, Graphics& gfx);
	void DrawDownLeft(int x, int y, int length, Color c, Graphics& gfx);
	void DrawUpRight(int x, int y, int length, Color c, Graphics& gfx);
	void DrawDownRight(int x, int y, int length, Color c, Graphics& gfx);
	//Updated Saber parts
	void Bit(int x, int y, Color c, Graphics& gfx);
	void TopUp(int x, int y, Color c, Graphics& gfx);
	void TopDown(int x, int y, Color c, Graphics& gfx);
	void HiltLeftUp(int x, int y, Graphics& gfx);
	void HiltRightUp(int x, int y, Graphics& gfx);
	void HiltLeftDown(int x, int y, Graphics& gfx);
	void HiltRightDown(int x, int y, Graphics& gfx);
	void Saber(int x, int y, Graphics& gfx);

	//Player 1 Lightsabers up
	void Upblue1(int x, int y, Graphics& gfx);
	void Upgreen1(int x, int y, Graphics& gfx);
	void Uppurple1(int x, int y, Graphics& gfx);
	void Upred1(int x, int y, Graphics& gfx);
	void Upwhite1(int x, int y, Graphics& gfx);

	//player 1 lightsabers down
	void Downblue1(int x, int y, Graphics& gfx);
	void Downgreen1(int x, int y, Graphics& gfx);
	void Downpurple1(int x, int y, Graphics& gfx);
	void Downred1(int x, int y, Graphics& gfx);
	void Downwhite1(int x, int y, Graphics& gfx);

	// Player 2 lightsabers up
	void Upblue2(int x, int y, Graphics& gfx);
	void Upgreen2(int x, int y, Graphics& gfx);
	void Uppurple2(int x, int y, Graphics& gfx);
	void Upred2(int x, int y, Graphics& gfx);
	void Upwhite2(int x, int y, Graphics& gfx);

	//Player 2 lightsabers down
	void Downblue2(int x, int y, Graphics& gfx);
	void Downgreen2(int x, int y, Graphics& gfx);
	void Downpurple2(int x, int y, Graphics& gfx);
	void Downred2(int x, int y, Graphics& gfx);
	void Downwhite2(int x, int y, Graphics& gfx);

	
};

