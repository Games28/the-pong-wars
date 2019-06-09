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
	rng(std::random_device()()),
	xdist(-1.0f,1.0f),
	ydist(-1.0f,1.0f),
	P2Saber(Vec2{ 585,160 }),
	P1Saber(Vec2{210,160}),
	P1Robe(Vec2{100,210}),
	P2Robe(Vec2{600,210}),
	Bolt(Vec2{380,280},Vec2{xdist(rng),ydist(rng)}),
	Remote(Vec2{380,280})
	
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
	
		
	CharacterSelect(wnd.kbd.KeyIsPressed('Z'));

	LightSaberSelect();
	//keyboard update
	P1Saber.P1MovementUpdate(wnd.kbd);
	P1Robe.P1MovementUpdate(wnd.kbd);
	P2Saber.P2MovementUpdate(wnd.kbd);
	P2Robe.P2MovementUpdate(wnd.kbd);

	//collsion 
	P1Saber.P1Collision();
	P1Robe.Player1Collision();
	P2Saber.P2Collision();
	P2Robe.Player2Collision();

	//head selection
	//p1
	
	
	//bolt
	
}

void Game::CharacterSelect(bool iskeypressed)
{
	
	if (!iskeypressed)
	{
		if (wnd.kbd.KeyIsPressed(VK_F1))
		{
			HS1 = HeadSelect::ANAKIN1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F2))
		{
			HS1 = HeadSelect::MARAJADE1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F3))
		{
			HS1 = HeadSelect::EMPEROR1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F4))
		{
			HS1 = HeadSelect::LEIA1;
		}

		if (wnd.kbd.KeyIsPressed(VK_F5))
		{
			HS1 = HeadSelect::LUKE1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F6))
		{
			HS1 = HeadSelect::REY1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F7))
		{
			HS1 = HeadSelect::OBIWAN1;
		}
		if (wnd.kbd.KeyIsPressed(VK_F8))
		{
			HS1 = HeadSelect::AHSOKA1;
		}
	}
	else {
		//p2
		if (wnd.kbd.KeyIsPressed(VK_F1))
		{
			HS2 = HeadSelect::ANAKIN2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F2))
		{
			HS2 = HeadSelect::MARAJADE2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F3))
		{
			HS2 = HeadSelect::EMPEROR2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F4))
		{
			HS2 = HeadSelect::LEIA2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F5))
		{
			HS2 = HeadSelect::LUKE2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F6))
		{
			HS2 = HeadSelect::REY2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F7))
		{
			HS2 = HeadSelect::OBIWAN2;
		}
		if (wnd.kbd.KeyIsPressed(VK_F8))
		{
			HS2 = HeadSelect::AHSOKA2;
		}

	
	}
}

void Game::LightSaberSelect()
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
		LC2 = LightsaberColor::BLUE2;
	}
	if (wnd.kbd.KeyIsPressed('7'))
	{
		LC2 = LightsaberColor::GREEN2;
	}
	if (wnd.kbd.KeyIsPressed('6'))
	{
		LC2 = LightsaberColor::RED2;
	}
	if (wnd.kbd.KeyIsPressed('8'))
	{
		LC2 = LightsaberColor::PURPLE2;
	}
}



void Game::ComposeFrame()
{
	back.Midline(gfx);
	back.Window(gfx);
	back.Thestars(gfx);
	back.Theemperor(gfx);
	back.Throne(gfx);

	//bolt images
	/*if (Bolt.getVel().x -= -1.0f)
	{
		Bolt.Boltleft(gfx);
	}
	if (Bolt += 1.0f)
	{
		Bolt.Boltright(gfx);
	}*/
	Bolt.Mainbolt(gfx);
	Bolt.WallCollision(gfx);
	
		
	
	Remote.TrainingRemote(gfx);
	//player selection
	//player1 animation
	MovementCounter++;
	if (MovementCounter >= MovementReset)
	{
		MovementCounter = 0;
		if (wnd.kbd.KeyIsPressed('W'))
		{
			P1Robe.Robe1moveY(gfx);
		}
		
		if (wnd.kbd.KeyIsPressed('S'))
		{
			P1Robe.Robe1moveY(gfx);
		}
		if (wnd.kbd.KeyIsPressed('A'))
		{
			P1Robe.Robe1moveX(gfx);
		}
		if (wnd.kbd.KeyIsPressed('D'))
		{
			P1Robe.Robe1moveX(gfx);
		}

	}
	else if (MovementCounter < 20)
	{
		
		if (wnd.kbd.KeyIsPressed('W'))
		{
			P1Robe.Robe1Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed('S'))
		{
			P1Robe.Robe1Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed('A'))
		{
			P1Robe.Robe1Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed('D'))
		{
			P1Robe.Robe1Stand(gfx);
		}
	}
	 
	//player2 animation
	if (MovementCounter >= MovementReset)
	{
		MovementCounter = 0;
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			P2Robe.Robe2moveY(gfx);
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			P2Robe.Robe2moveY(gfx);
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			P2Robe.Robe2moveX(gfx);
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			P2Robe.Robe2moveX(gfx);
		}

	}
	else if (MovementCounter < 20)
	{

		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			P2Robe.Robe2Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			P2Robe.Robe2Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			P2Robe.Robe2Stand(gfx);
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			P2Robe.Robe2Stand(gfx);
		}
	}


	//p1 character select art
	switch (HS1)
	{
		case HeadSelect::ANAKIN1:
		{
			
			P1Robe.anakin1head(gfx);


		}break;
		case HeadSelect::MARAJADE1:
		{
			
			P1Robe.Marajade1head(gfx);
		}break;
		case HeadSelect::EMPEROR1:
		{
			
			P1Robe.emperor1head(gfx);
		}break;
		case HeadSelect::LEIA1:
		{
			
			P1Robe.Leia1head(gfx);
		}break;
		case  HeadSelect::LUKE1:
		{
			
			P1Robe.Luke1head(gfx);
		}break;

		case  HeadSelect::REY1:
		{
			
			P1Robe.Rey1head(gfx);
		}break;
		case  HeadSelect::OBIWAN1:
		{
			
			P1Robe.Obiwan1head(gfx);
		}break;
		case  HeadSelect::AHSOKA1:
		{
			
			P1Robe.ahsoka1head(gfx);
		}break;
	}
	//p2
	if (HS2 == HeadSelect::LUKE2)
	{
		P2Robe.Luke2head(gfx);
	}

		if (HS2 == HeadSelect::REY2)
		{
			P2Robe.Rey2head(gfx);
		}
		if (HS2 == HeadSelect::OBIWAN2)
		{
			P2Robe.Obiwan2head(gfx);
		}
		if (HS2 == HeadSelect::AHSOKA2)
		{
			P2Robe.ahsoka2head(gfx);
		}
		if (HS2 == HeadSelect::ANAKIN2)
		{
			P2Robe.anakin2head(gfx);
		}
		if (HS2 == HeadSelect::MARAJADE2)
		{
			P2Robe.Marajade2head(gfx);
		}
		if (HS2 == HeadSelect::EMPEROR2)
		{
			P2Robe.emperor2head(gfx);
		}
		if (HS2 == HeadSelect::LEIA2)
		{
			P2Robe.Leia2head(gfx);
		}

		//lightsaber selection
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
			if (LC2 == LightsaberColor::BLUE2)
			{
				P2Saber.Upblue2(gfx);
			}
			else if (LC2 == LightsaberColor::GREEN2)
			{
				P2Saber.Upgreen2(gfx);
			}
			else if (LC2 == LightsaberColor::RED2)
			{
				P2Saber.Upred2(gfx);
			}
			else if (LC2 == LightsaberColor::PURPLE2)
			{
				P2Saber.Uppurple2(gfx);
			}
			else {
				P2Saber.Upwhite2(gfx);
			}

		}
		else {
			if (LC2 == LightsaberColor::BLUE2)
			{
				P2Saber.Downblue2(gfx);
			}
			else if (LC2 == LightsaberColor::GREEN2)
			{
				P2Saber.Downgreen2(gfx);
			}
			else if (LC2 == LightsaberColor::RED2)
			{
				P2Saber.Downred2(gfx);
			}
			else if (LC2 == LightsaberColor::PURPLE2)
			{
				P2Saber.Downpurple2(gfx);
			}
			else {

				P2Saber.Downwhite2(gfx);

			}
		}

		
	
	}
