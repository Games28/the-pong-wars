#pragma once
class Graphics;
class Color;
class ArtSaber
{
public:
	ArtSaber() = default;
	//Updated Saber Draw length
	void DrawUpLeft(int x, int y, int length, Color *c, Graphics& gfx);
	void DrawDownLeft(int x, int y, int length, Color *c, Graphics& gfx);
	void DrawUpRight(int x, int y, int length, Color *c, Graphics& gfx);
	void DrawDownRight(int x, int y, int length, Color *c, Graphics& gfx);
	//Updated Saber parts
	void Bit(int x, int y, Color *c, Graphics& gfx);
	void TopUp(int x, int y, Color c, Graphics& gfx);
	void TopDown(int x, int y, Color c, Graphics& gfx);
	void HiltLeftUp(int x, int y, Graphics& gfx);
	void HiltRightUp(int x, int y, Graphics& gfx);
	void HiltLeftDown(int x, int y, Graphics& gfx);
	void HiltRightDown(int x, int y, Graphics& gfx);
	void Saber(int x, int y, Graphics& gfx);

	//Player 1 Lightsabers up
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
	
	
	
	
	

	
};

