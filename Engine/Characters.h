#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Vec2.h"

class Characters
{
public:
	Characters(Vec2& in_loc);
	//player 1 characters
	void Leia1head(Graphics& gfx);
	void Luke1head(Graphics& gfx);
	void ahsoka1head(Graphics& gfx);
	void emperor1head(Graphics& gfx);
	void anakin1head(Graphics& gfx);
	void Marajade1head(Graphics& gfx);
	void Rey1head(Graphics& gfx);
	void Obiwan1head(Graphics& gfx);
	//player 1 robe
	void Robe1(Graphics& gfx);
	void Robe1falling(Graphics& gfx);
	void Robe1fallen(Graphics& gfx);

	//player 2 characters
	void Leia2head(Graphics& gfx);
	void Luke2head(Graphics& gfx);
	void ahsoka2head(Graphics& gfx);
	void emperor2head(Graphics& gfx);
	void anakin2head(Graphics& gfx);
	void Marajade2head(Graphics& gfx);
	void Rey2head(Graphics& gfx);
	void Obiwan2head(Graphics& gfx);
	//player 2 robe
	void Robe2(Graphics& gfx);
	void Robe2falling(Graphics& gfx);
	void Robe2fallen(Graphics& gfx);


	//movement
	void P1MovementUpdate(Keyboard& kbd);
	void P2MovementUpdate(Keyboard& kbd);
	void Player2Collision();
	void Player1Collision();
	
private:
	static constexpr float width = 38;
	static constexpr float height = 225;
	Vec2 loc;

};
