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
#include "P1lightsaber.h"
#include "P2lightsaber.h"
#include "Direction.h"
#include "Player1.h"
#include "Player2.h"
#include "LightsaberColor.h"
#include "LightsaberColor2.h"
#include "HeadSelect1.h"
#include "HeadSelect2.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	Background back;
	P1lightsaber P1Saber;
	P2lightsaber P2Saber;
	Direction dirP1;
	Direction dirP2;
	LightsaberColor LC;
	LightsaberColor2 LC2;
	Player1 P1Robe;
	Player2 P2Robe;
	HeadSelect1 HS1;
	HeadSelect2 HS2;
	/********************************/
	/*  User Variables              */
	/********************************/
};