/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Background.h"

#include "Direction.h"

#include "Characters.h"
#include "LightSabers.h"
#include "LightsaberColor.h"
#include "Menus.h"
#include "HeadSelect.h"

#include "Laser.h"
#include <random>
//#define NUMBER_OF_CHRS 2

/*current objects 1. get Laser object collision working with lightsaber for player1 and player2.
                  2. get laser collision detection with window border to display sparks images when 
				     it by laser.
			       3. a getting method of doing character selection for all characters instead of 
				     just current 4. 
			       4. code clean up. 

				   main objective of game will be to make menus with character and saber color selection.
				   with gameplay being to deflect the laser from your character with saber and no get hit.
				   if hit will have a health bar the will go down when the player it hit. also it the laser
				   hits the walls it will respawn in the middle again.
				 
*/
class Game
{
	enum
	{
		PLAYER1,
		PLAYER2,
		NUMBER_OF_CHRS
	};
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void CharacterSelect(bool iskeypressed);
	void LightSaberSelect();
	void CharacterAnimation();
	void CharacterDisplay();
	void LightsaberDisplay();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xdist;
	std::uniform_real_distribution<float> ydist;
	Background back;
	LightSaber P1Saber;
	LightSaber P2Saber;
	Direction dirP1;
	Direction dirP2;
	LightsaberColor LC;
	LightsaberColor LC2;
	//Characters P1Robe;
	//Characters P2Robe;

	Characters characters[NUMBER_OF_CHRS];

	
	//HeadSelect HS1;
	//HeadSelect HS2;
	Laser Bolt;
	Laser Remote;
	Menus DOit;
	Menus mainmenu;
	bool GameOver = false;
	bool Player1Select = true;
	bool Player2Select = true;
	bool CharactersSelected = false;
	bool LightsabersSelected = false;
	bool Lightsaber1select =false;
	bool Lightsaber2select = false;
	bool GameStarted = false;
	int MovementCounter = 0;
	int MovementReset = 40;
	/********************************/
	/*  User Variables              */
	/********************************/
};