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
#include "TheSelector.h"
#include "Character.h"
#include "CollisionManager.h"
#include "LightSabers.h"
#include "LightsaberColor.h"
#include "Menus.h"
#include "HeadSelect.h"
#include "Collider.h"
#include "Laser.h"
#include <random>
//#define NUMBER_OF_CHRS 2


class Game
{
public:
	enum
	{
		// Note: keep the following settings
		// as it's for array access and size declaration 
		PLAYER1 = 0,
		PLAYER2 = 1,
		NUMBER_OF_CHRS = 2
	};
	enum GameState
	{
		TITLE,
		SELECTION,
		GAMESTART,
		GAMEEND
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
	Vec2 GetMoveDirection_P1(float moveAmount);
	Vec2 GetMoveDirection_P2(float moveAmount);
	void MoveCharacters();
	void CharacterDisplay();
	void UpdateLightSaber();
	void StateChange(GameState state);
		/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xdist;
	std::uniform_real_distribution<float> ydist;
	Vec2 (Game::* GetMoveDirection[2])(float moveAmount);
	Background back;
	CollisionManager collideManager;
	Character characters[NUMBER_OF_CHRS];
	int ColorCounter = 0;
	int ColorReset = 100;
	TheSelector selecting;
	Laser Bolt;
	Laser Remote;
	Menus DOit;
	Menus mainmenu;
	GameState stateofgame;
	bool GameOver = false;
	bool CharactersSelected = false;
	bool LightsabersSelected = false;
	bool GameStarted = false;
	int MovementCounter = 0;
	int MovementReset = 40;
	/********************************/
	/*  User Variables              */
	/********************************/
};