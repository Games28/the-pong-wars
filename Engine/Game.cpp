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
	Remote(Vec2{380,280}),
	DOit(gfx),
	mainmenu(gfx)
	
	
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
	if (CharactersSelected && LightsabersSelected)
	{
		CharacterSelect(wnd.kbd.KeyIsPressed(VK_TAB));

		LightSaberSelect();
	}
	else
	{
		GameStarted = true;
	}
	if (!GameStarted)
	{
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

	}
	
	
}

void Game::CharacterSelect(bool iskeypressed)
{
	if (!iskeypressed)
	{
		if (Player1Select)
		{
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				characters[PLAYER1].HS = HeadSelect::ANAKIN1;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				characters[PLAYER1].HS = HeadSelect::MARAJADE1;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				characters[PLAYER1].HS = HeadSelect::EMPEROR1;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				characters[PLAYER1].HS = HeadSelect::LEIA1;
				Player1Select = true;

			}

			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				characters[PLAYER1].HS = HeadSelect::LUKE1;
				Player1Select = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				characters[PLAYER1].HS = HeadSelect::REY1;
				Player1Select = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				characters[PLAYER1].HS = HeadSelect::OBIWAN1;
				Player1Select = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				characters[PLAYER1].HS = HeadSelect::AHSOKA1;
				Player1Select = true;

			}
		}
		else {
			Player1Select = false;
		}

	}
	
	
	if (iskeypressed)
	{
		if (Player2Select)
		{
			//p2
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				Player1Select = true;
				characters[PLAYER2].HS = HeadSelect::ANAKIN2;
				
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				characters[PLAYER2].HS = HeadSelect::MARAJADE2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				characters[PLAYER2].HS = HeadSelect::EMPEROR2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				characters[PLAYER2].HS = HeadSelect::LEIA2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				characters[PLAYER2].HS = HeadSelect::LUKE2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				characters[PLAYER2].HS = HeadSelect::REY2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				characters[PLAYER2].HS = HeadSelect::OBIWAN2;
				Player1Select = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				characters[PLAYER2].HS = HeadSelect::AHSOKA2;
				Player1Select = true;
			}


		}
		else {
			Player2Select = false;
		}
	}
	
	if (!Player1Select && !Player2Select)
	{
		CharactersSelected = true;
	}
}

void Game::LightSaberSelect()
{
	//lightsaber color binding p1
	if (!Lightsaber1select)
	{
		if (wnd.kbd.KeyIsPressed('1'))
		{
			LC = LightsaberColor::BLUE1;
			Lightsaber1select = true;
		}
		if (wnd.kbd.KeyIsPressed('2'))
		{
			LC = LightsaberColor::GREEN1;
			Lightsaber1select = true;
		}
		if (wnd.kbd.KeyIsPressed('3'))
		{
			LC = LightsaberColor::RED1;
			Lightsaber1select = true;
		}
		if (wnd.kbd.KeyIsPressed('4'))
		{
			LC = LightsaberColor::PURPLE1;
			Lightsaber1select = true;
		}
	}
	else {
		Lightsaber1select = false;
	}
	//p2

	if (!Lightsaber2select)
	{


		if (wnd.kbd.KeyIsPressed('5'))
		{
			LC2 = LightsaberColor::BLUE2;
			Lightsaber2select = true;
		}
		if (wnd.kbd.KeyIsPressed('7'))
		{
			LC2 = LightsaberColor::GREEN2;
			Lightsaber2select = true;
		}
		if (wnd.kbd.KeyIsPressed('6'))
		{
			LC2 = LightsaberColor::RED2;
			Lightsaber2select = true;
		}
		if (wnd.kbd.KeyIsPressed('8'))
		{
			LC2 = LightsaberColor::PURPLE2;
			Lightsaber2select = true;
		}
	}
	else {
		Lightsaber2select = false;
	}

	if (!Lightsaber1select && !Lightsaber2select)
	{
		LightsabersSelected = true;
	}
}

void Game::CharacterAnimation()
{
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
}

void Game::CharacterDisplay()
{
	//p1 character select art
	for (int i = 0; i < NUMBER_OF_CHRS; i++)
	{
		
		switch (characters[i].HS)

		{
		case HeadSelect::ANAKIN1:
		{

			characters[i].anakin1head(gfx);
		}break;
		case HeadSelect::MARAJADE1:
		{

			characters[i].Marajade1head(gfx);
		}break;
		case HeadSelect::EMPEROR1:
		{

			characters[i].emperor1head(gfx);
		}break;
		case HeadSelect::LEIA1:
		{

			characters[i].Leia1head(gfx);
		}break;
		case  HeadSelect::LUKE1:
		{

			characters[i].Luke1head(gfx);
		}break;

		case  HeadSelect::REY1:
		{

			characters[i].Rey1head(gfx);
		}break;
		case  HeadSelect::OBIWAN1:
		{

			characters[i].Obiwan1head(gfx);
		}break;
		case  HeadSelect::AHSOKA1:
		{

			characters[i].ahsoka1head(gfx);
		}break;


		//p2
		case HeadSelect::LUKE2:
		{
			characters[i].Luke2head(gfx);
		}break;

		case HeadSelect::REY2:
		{
			characters[i].Rey2head(gfx);
		}break;
		case HeadSelect::OBIWAN2:
		{
			characters[i].Obiwan2head(gfx);
		}break;
		case HeadSelect::AHSOKA2:
		{
			characters[i].ahsoka2head(gfx);
		}break;
		case HeadSelect::ANAKIN2:
		{
			characters[i].anakin2head(gfx);
		}break;
		case HeadSelect::MARAJADE2:
		{
			characters[i].Marajade2head(gfx);
		}break;
		case HeadSelect::EMPEROR2:
		{
			characters[i].emperor2head(gfx);
		}break;
		case HeadSelect::LEIA2:
		{
			characters[i].Leia2head(gfx);
		}break;
		}
	}
}

void Game::LightsaberDisplay()
{
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

	}
}



void Game::ComposeFrame()
{
	back.Midline(gfx);
	back.Window(gfx);
	back.Thestars(gfx);
	back.Theemperor(gfx);
	back.Throne(gfx);
	mainmenu.MainMenu(gfx);
	
	if (CharactersSelected && LightsabersSelected)
	{
       
		CharacterDisplay();
		LightsaberDisplay();
	}
	else if (!GameStarted)
	{


		Bolt.Mainbolt(gfx);
		Bolt.WallCollision(gfx);



		Remote.TrainingRemote(gfx);


		CharacterAnimation();

	}
		
		
	
	}
