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
	
	//lightsaber color binding p1
	if (wnd.kbd.KeyIsPressed('1'))
	{
		LC = LightsaberColor::BLUE1;
	}
	if (wnd.kbd.KeyIsPressed('2'))
	{
		LC = LightsaberColor::GREEN1;
	}
	if (wnd.kbd.KeyIsPressed('3'))
	{
		LC = LightsaberColor::RED1;
	}
	if (wnd.kbd.KeyIsPressed('4'))
	{
		LC = LightsaberColor::PURPLE1;
	}
	//p2
	if (wnd.kbd.KeyIsPressed('5'))
	{
		LC2 = LightsaberColor2::BLUE2;
	}
	if (wnd.kbd.KeyIsPressed('7'))
	{
		LC2 = LightsaberColor2::GREEN2;
	}
	if (wnd.kbd.KeyIsPressed('6'))
	{
		LC2 = LightsaberColor2::RED2;
	}
	if (wnd.kbd.KeyIsPressed('8'))
	{
		LC2 = LightsaberColor2::PURPLE2;
	}
	//keyboard update
	P1Saber.MovementUpdate(wnd.kbd);
	P1Head.MovementUpdate(wnd.kbd);
	P1Robe.MovementUpdate(wnd.kbd);
	P2Saber.MovementUpdate(wnd.kbd);
	P2Head.MovementUpdate(wnd.kbd);
	P2Robe.MovementUpdate(wnd.kbd);

	//collsion 
	P1Saber.Collision();
	P1Robe.Collision();
	P2Saber.Collision();
    P2Robe.collsion();
	P1Head.Collision();
	P2Head.Collision();
	
	
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
	//p1
	if (!wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		if (LC == LightsaberColor::BLUE1)
		{
			P1Saber.Upblue1(gfx);
		}
		else if (LC == LightsaberColor::GREEN1)
		{
			P1Saber.Upgreen1(gfx);
		}
		else if (LC == LightsaberColor::RED1)
		{
			P1Saber.Upred1(gfx);
		}
		else if (LC == LightsaberColor::PURPLE1)
		{
			P1Saber.Uppurple1(gfx);
		}
		else {
			P1Saber.Upwhite1(gfx);
		}
		
	}
	else {
		if (LC == LightsaberColor::BLUE1)
		{
			P1Saber.Downblue1(gfx);
		}
		else if (LC == LightsaberColor::GREEN1)
		{
			P1Saber.Downgreen1(gfx);
		}
		else if (LC == LightsaberColor::RED1)
		{
			P1Saber.Downred1(gfx);
		}
		else if (LC == LightsaberColor::PURPLE1)
		{
			P1Saber.Downpurple1(gfx);
		}
		else {
			
			P1Saber.Downwhite1(gfx);
		
		}
	}
	//p2
	if (!wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		if (LC2 == LightsaberColor2::BLUE2)
		{
			P2Saber.Upblue2(gfx);
		}
		else if (LC2 == LightsaberColor2::GREEN2)
		{
			P2Saber.Upgreen2(gfx);
		}
		else if (LC2 == LightsaberColor2::RED2)
		{
			P2Saber.Upred2(gfx);
		}
		else if (LC2 == LightsaberColor2::PURPLE2)
		{
			P2Saber.Uppurple2(gfx);
		}
		else {
			P2Saber.Upwhite2(gfx);
		}

	}
	else {
		if (LC2 == LightsaberColor2::BLUE2)
		{
			P2Saber.Downblue2(gfx);
		}
		else if (LC2 == LightsaberColor2::GREEN2)
		{
			P2Saber.Downgreen2(gfx);
		}
		else if (LC2 == LightsaberColor2::RED2)
		{
			P2Saber.Downred2(gfx);
		}
		else if (LC2 == LightsaberColor2::PURPLE2)
		{
			P2Saber.Downpurple2(gfx);
		}
		else {

			P2Saber.Downwhite2(gfx);

		}
	}
	
		
}
