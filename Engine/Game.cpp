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
	P2Saber(Vec2{ 585,160 }),
	P1Saber(Vec2{210,160}),
	P1Head(Vec2{105,205}),
	P1Robe(Vec2{100,250}),
	P2Head(Vec2{640,205}),
	P2Robe(Vec2{600,250})
	
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
	//keyboard update
	P1Saber.MovementUpdate(wnd.kbd);
	P1Head.MovementUpdate(wnd.kbd);
	P1Robe.MovementUpdate(wnd.kbd);
	P2Saber.MovementUpdate(wnd.kbd);
	P2Head.MovementUpdate(wnd.kbd);
	P2Robe.MovementUpdate(wnd.kbd);

	//collsion for p1 and p2
	P1Saber.Collision();
	P2Saber.Collision();
	
}



void Game::ComposeFrame()
{
	back.Midline(gfx);
	back.Window(gfx);
	back.Thestars(gfx);
	back.Theemperor(gfx);
	back.Throne(gfx);
	P1Head.anakin1head(gfx);
	P1Robe.Robe1(gfx);
	P2Robe.Robe2(gfx);
	P2Head.ahsoka2head(gfx);
	P1Saber.Upblue1(gfx);
	P2Saber.Upgreen2(gfx);

	
		
}
