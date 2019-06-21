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
	//			Head			Robe			Saber
	characters{ {Vec2{110,192}, Vec2{100,240}, Vec2{210,282}},
				{Vec2{634,192}, Vec2{600,240}, Vec2{585,282}} },
	Bolt(Vec2{380,280},Vec2{xdist(rng),ydist(rng)}),
	Remote(Vec2{380,280}),
	DOit(gfx),
	mainmenu(gfx)
	
	
{
	characters[PLAYER1].DrawHead = &ArtHeads::ahsoka1head;
	characters[PLAYER1].DrawRobe = &ArtRobes::Robe1;

	characters[PLAYER2].DrawHead = &ArtHeads::ahsoka2head;
	characters[PLAYER2].DrawRobe = &ArtRobes::Robe2;

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
	back.SaberColorChange();
	//if (!CharactersSelected || !LightsabersSelected)
	{


		CharacterSelect(wnd.kbd.KeyIsPressed(VK_TAB));

		LightSaberSelect();
	}
	//else
	{
		GameStarted = true;
	}
	if (GameStarted)
	{
		
		UpdateCharacters();
		

		//collsion 
		//P1Saber.P1Collision();
		//P1Robe.Player1Collision();
		//P2Saber.P2Collision();
		//P2Robe.Player2Collision();

	}
	
	
}

void Game::UpdateCharacters()
{
	float moveAmount = 2.0f;
	//keyboard update
	if (wnd.kbd.KeyIsPressed('W'))
	{
		characters[PLAYER1].Move(Vec2(0, -moveAmount));
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		characters[PLAYER1].Move(Vec2(0, moveAmount));
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		characters[PLAYER1].Move(Vec2(-moveAmount, 0));
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		characters[PLAYER1].Move(Vec2(moveAmount, 0));
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		characters[PLAYER2].Move(Vec2(0, -moveAmount));
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		characters[PLAYER2].Move(Vec2(0, moveAmount));
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		characters[PLAYER2].Move(Vec2(-moveAmount, 0));
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		characters[PLAYER2].Move(Vec2(moveAmount, 0));
	}
}


void Game::CharacterSelect(bool iskeypressed)
{
	if (!iskeypressed)
	{
		//if (!Player1Select)
		{
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::anakin1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::Marajade1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::emperor1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::Leia1head;
				characters[PLAYER1].isSelected = true;

			}

			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::Luke1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::Rey1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::Obiwan1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				characters[PLAYER1].DrawHead = &ArtHeads::ahsoka1head;
				characters[PLAYER1].isSelected = true;

			}
		}
		//else {
			//Player1Select = false;
		//}

	}
	
	
	if (iskeypressed)
	{
		//if (!Player2Select)
		{
			//p2
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::anakin2head;
				characters[PLAYER2].isSelected = true;
				
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::Marajade2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::emperor2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::Leia2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::Luke2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::Rey2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::Obiwan2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				characters[PLAYER2].DrawHead = &ArtHeads::ahsoka2head;
				characters[PLAYER2].isSelected = true;
			}


		}
		
	}
	
	if (characters[PLAYER1].isSelected && characters[PLAYER2].isSelected)
	{
		CharactersSelected = true;
	}
}

void Game::LightSaberSelect()
{
	
	//lightsaber color binding p1
	//if (!Lightsaber1select)
	{
		if (wnd.kbd.KeyIsPressed('1'))
		{
			characters[PLAYER1].lightSaber.color = Colors::Blue;
			characters[PLAYER1].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('2'))
		{
			characters[PLAYER1].lightSaber.color = Colors::Green;
			characters[PLAYER1].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('3'))
		{
			characters[PLAYER1].lightSaber.color = Colors::Red;
			characters[PLAYER1].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('4'))
		{
			characters[PLAYER1].lightSaber.color = Colors::Magenta;
			characters[PLAYER1].lightSaber.isSelected = true;
		}
	}
	//else {
		//Lightsaber1select = false;
	//}
	//p2

	//if (!Lightsaber2select)
	{


		if (wnd.kbd.KeyIsPressed('5'))
		{
			characters[PLAYER2].lightSaber.color = Colors::Cyan;
			characters[PLAYER2].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('6'))
		{
			characters[PLAYER2].lightSaber.color = Colors::Gray;
			characters[PLAYER2].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('7'))
		{
			characters[PLAYER2].lightSaber.color = Colors::LightGray;
			characters[PLAYER2].lightSaber.isSelected = true;
		}
		if (wnd.kbd.KeyIsPressed('8'))
		{
			characters[PLAYER2 ].lightSaber.color = Colors::MakeRGB(50, 200, 20);
			characters[PLAYER2].lightSaber.isSelected = true;
		}
	}
	//else {
		//Lightsaber2select = false;
	//}

	if (characters[PLAYER1].lightSaber.isSelected && characters[PLAYER2].lightSaber.isSelected)
	{
		LightsabersSelected = true;
		
	}
}


void Game::CharacterDisplay()
{
	// Loop through characters and call selected character 
	// via a function pointer
	for (int i = 0; i < NUMBER_OF_CHRS; i++)
	{
		characters[i].Draw(gfx);
	}
}

void Game::UpdateLightSaber()
{
	//p1
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		characters[PLAYER1].lightSaber.isdown = true;
	}
	else {
		characters[PLAYER1].lightSaber.isdown = false;
	}
	//p2
	if (wnd.kbd.KeyIsPressed(VK_NUMPAD0))
	{
		characters[PLAYER2].lightSaber.isdown = true;
	}
	else {
		characters[PLAYER2].lightSaber.isdown = false;

	}
	for (int i = 0; i < 2; i++)
	{
		if (wnd.kbd.KeyIsPressed('G'))
		{
			characters[i].lightSaber.length++;
		}
		if (wnd.kbd.KeyIsPressed('H'))
		{
			characters[i].lightSaber.length--;
			if (characters[i].lightSaber.length < 0)
				characters[i].lightSaber.length = 0;
		}
	}
}

void Game::ComposeFrame()
{
	
	back.EmperorThroneRoom(gfx);
	

	

	if (!CharactersSelected)
	{
		gfx.PstartPosition(150, 210);
		gfx.PstartPosition(550, 210);
		mainmenu.MainMenu(gfx);
	}
	if (CharactersSelected)
	{
		CharacterDisplay();
	}
	if (LightsabersSelected)
	{
		UpdateLightSaber();

	}
	if (GameStarted)
	{

		Bolt.Mainbolt(gfx);
		Bolt.WallCollision(gfx);

		Remote.TrainingRemote(gfx);

		//CharacterAnimation();

	}
}
