/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	back(gfx),
	P2Saber(Vec2{ 100,100 }),
	P1Saber(Vec2{200,100})
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//p1
	if (wnd.kbd.KeyIsPressed('W'))
	{
		dirP1 = Direction::TOP;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		dirP1 = Direction::DOWN;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		dirP1 = Direction::LEFT;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		dirP1 = Direction::RIGHT;
	}
	//p2
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		dirP2 = Direction::TOP;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		dirP2 = Direction::DOWN;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		dirP2 = Direction::LEFT;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		dirP2 = Direction::RIGHT;
	}

	P1Saber.MovementUpdate(wnd.kbd);
}



void Game::ComposeFrame()
{
	back.Midline(gfx);
	back.Window(gfx);
	back.Thestars(gfx);
	back.Theemperor(gfx);
	back.Throne(gfx);
	P1Saber.Upblue1(gfx);
}
