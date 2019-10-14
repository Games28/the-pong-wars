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
#include "LightSabers.h"


Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	back(gfx),
	rng(std::random_device()()),
	xdist(-1.0f, 1.0f),
	ydist(-1.0f, 1.0f),
	//			Head			Robe			Saber
	characters{ {Vec2{110,192}, Vec2{100,240}, Vec2{210,282}},
				{Vec2{637,195}, Vec2{600,240}, Vec2{580,282}} },
	Bolt(Vec2{ 380,280 }, rng),
	Remote(Vec2{ 380,280 }),
	DOit(gfx),
	mainmenu(gfx)
	
	
	
{
	GetMoveDirection[PLAYER1] = &Game::GetPlayer1Movement;
	GetMoveDirection[PLAYER2] = &Game::GetPlayer2Movement;
	characters[PLAYER1].DrawHead = &ArtHeads::ahsoka1head;
	characters[PLAYER1].DrawRobe = &ArtRobes::Robe1;
	

	characters[PLAYER2].DrawHead = &ArtHeads::ahsoka2head;
	characters[PLAYER2].DrawRobe = &ArtRobes::Robe2;
	for (int i = 0; i < NUMBER_OF_CHRS; i++)
	{
		Vec2 Playerboxpos = characters[i].artpos.head;
		Vec2 Playerboxsize = characters[i].CharacterSize;

		characters[i].collider.Init(Playerboxpos, Playerboxsize);
		
	}
	stateofgame = GameState::TITLE;
	theselecter = Selector::DEFAULT;
	player1Head = HeadSelect::DEFAULT;
	player1Color = LightsaberColor::DEFAULT;
	player2Head = HeadSelect::DEFAULT;
	player2Color = LightsaberColor::DEFAULT;

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

Vec2 Game::GetPlayer1Movement(float moveAmount)
{
	Vec2 finalMoveAmount = Vec2(0.0f, 0.0f);

	//keyboard update
	if (wnd.kbd.KeyIsPressed('W'))
	{
		finalMoveAmount += Vec2(0, -moveAmount);
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		finalMoveAmount += Vec2(0, moveAmount);
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		finalMoveAmount += Vec2(-moveAmount, 0);
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		finalMoveAmount += Vec2(moveAmount, 0);
	}
	return finalMoveAmount;
}
Vec2 Game::GetPlayer2Movement(float moveAmount)
{
	Vec2 finalMoveAmount = Vec2(0.0f, 0.0f);

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		finalMoveAmount += Vec2(0, -moveAmount);
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		finalMoveAmount += Vec2(0, moveAmount);
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		finalMoveAmount += Vec2(-moveAmount, 0);
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		finalMoveAmount += Vec2(moveAmount, 0);
	}
	return finalMoveAmount;
}

//movement update
void Game::MoveCharacters()
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

//character selecting
void Game::PlayerCharacter(bool iskeypressed)
{
	if (!iskeypressed)
	{
		
		
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				selecting.CharacterSelector1(20, 350, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::anakin1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				selecting.CharacterSelector1(20, 370, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::Marajade1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				selecting.CharacterSelector1(20, 400, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::emperor1head;
				characters[PLAYER1].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				selecting.CharacterSelector1(20, 430, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::Leia1head;
				characters[PLAYER1].isSelected = true;

			}

			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				selecting.CharacterSelector1(20, 460, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::Luke1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				selecting.CharacterSelector1(20, 490, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::Rey1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				selecting.CharacterSelector1(20, 520, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::Obiwan1head;
				characters[PLAYER1].isSelected = true;

			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				selecting.CharacterSelector1(20, 545, gfx);
				characters[PLAYER1].DrawHead = &ArtHeads::ahsoka1head;
				characters[PLAYER1].isSelected = true;

			}
		}
		//else {
			//Player1Select = false;
		//}

	
	
	
	if (iskeypressed)
	{
		//if (!Player2Select)
		
			//p2
			if (wnd.kbd.KeyIsPressed(VK_F1))
			{
				selecting.CharacterSelector2(420, 350, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::anakin2head;
				characters[PLAYER2].isSelected = true;
				
			}
			if (wnd.kbd.KeyIsPressed(VK_F2))
			{
				selecting.CharacterSelector2(420, 370, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::Marajade2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F3))
			{
				selecting.CharacterSelector2(420, 400, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::emperor2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F4))
			{
				selecting.CharacterSelector2(420, 430, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::Leia2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F5))
			{
				selecting.CharacterSelector2(420, 460, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::Luke2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F6))
			{
				selecting.CharacterSelector2(420, 490, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::Rey2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F7))
			{
				selecting.CharacterSelector2(420, 520, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::Obiwan2head;
				characters[PLAYER2].isSelected = true;
			}
			if (wnd.kbd.KeyIsPressed(VK_F8))
			{
				selecting.CharacterSelector2(420, 545, gfx);
				characters[PLAYER2].DrawHead = &ArtHeads::ahsoka2head;
				characters[PLAYER2].isSelected = true;
			}


		
		
	}
	
	if (characters[PLAYER1].isSelected && characters[PLAYER2].isSelected)
	{
		CharactersSelected = true;
	}
}
void Game::TestPlayerchar()
{
	switch (player1Head)
	{
	case HeadSelect::ANAKIN1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::anakin1head;
		break;
	}
	case HeadSelect::MARAJADE1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::Marajade1head;
		break;
	}
	case HeadSelect::EMPEROR1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::emperor1head;
		break;
	}
	case HeadSelect::LEIA1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::Leia1head;
		break;
	}
	case HeadSelect::LUKE1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::Luke1head;
		break;
	}
	case HeadSelect::REY1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::Rey1head;
		break;
	}
	case HeadSelect::OBIWAN1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::Obiwan1head;
		break;
	}
	case HeadSelect::AHSOKA1:
	{
		characters[PLAYER1].DrawHead = &ArtHeads::anakin1head;
		break;
	}
	}

	switch (player2Head)
	{
	case HeadSelect::ANAKIN2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::anakin2head;
		break;
	}
	case HeadSelect::MARAJADE2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::Marajade2head;
		break;
	}
	case HeadSelect::EMPEROR2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::emperor2head;
		break;
	}
	case HeadSelect::LEIA2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::Leia2head;
		break;
	}
	case HeadSelect::LUKE2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::Luke2head;
		break;
	}
	case HeadSelect::REY2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::Rey2head;
		break;
	}
	case HeadSelect::OBIWAN2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::Obiwan2head;
		break;
	}
	case HeadSelect::AHSOKA2:
	{
		characters[PLAYER2].DrawHead = &ArtHeads::ahsoka2head;
		break;
	}
	}
}
void Game::Testchosesaber()
{
	unsigned char ColorValue = 127;
	switch (player1Color)
	{
	case LightsaberColor::BLUE1:
	{
		characters[PLAYER1].lightSaber.color[0] = Color{ 0,0,ColorValue };
		characters[PLAYER1].lightSaber.isSelected1 = true;
		break;
	}
	case LightsaberColor::GREEN1:
	{
		characters[PLAYER1].lightSaber.color[0] = Color{ 0,ColorValue,0 };
		characters[PLAYER1].lightSaber.isSelected1 = true;
		break;
	}
	case LightsaberColor::RED1:
	{
		characters[PLAYER1].lightSaber.color[0] = Color{ ColorValue,0,0 };
		characters[PLAYER1].lightSaber.isSelected1 = true;
		break;
	}
	case LightsaberColor::PURPLE1:
	{
		characters[PLAYER1].lightSaber.color[0] = Color{ ColorValue,0,ColorValue };
		characters[PLAYER1].lightSaber.isSelected1 = true;
		break;
	}
	}

	switch (player2Color)
	{
	case LightsaberColor::BLUE2:
	{
		characters[PLAYER2].lightSaber.color[1] = Color{ 0,0,ColorValue };
		characters[PLAYER2].lightSaber.isSelected2 = true;
		break;
	}
	case LightsaberColor::GREEN2:
	{
		characters[PLAYER2].lightSaber.color[1] = Color{ 0,ColorValue,0 };
		characters[PLAYER2].lightSaber.isSelected2 = true;
		break;
	}
	case LightsaberColor::RED2:
	{
		characters[PLAYER2].lightSaber.color[1] = Color{ ColorValue,0,0 };
		characters[PLAYER2].lightSaber.isSelected2 = true;
		break;
	}
	case LightsaberColor::PURPLE2:
	{
		characters[PLAYER2].lightSaber.color[1] = Color{ ColorValue,0,ColorValue };
		characters[PLAYER2].lightSaber.isSelected2 = true;
		break;
	}
	}
	
}
void Game::TheMenuSelector(Keyboard::Event* E)  // currently function working on
{
	char P1 = E->GetCode();
	if (!wnd.kbd.KeyIsPressed(VK_TAB))
	{
		if (E->IsPress())
		{// player 1 heads
			switch (P1)
			{
			case VK_F1:
			{

				selecting.CharacterSelector1(20, 350, gfx);
				player1Head = HeadSelect::ANAKIN1;
				break;
			}
			case VK_F2:
			{
				selecting.CharacterSelector1(20, 370, gfx);
				player1Head = HeadSelect::MARAJADE1;
				break;
			}
			case VK_F3:
			{
				selecting.CharacterSelector1(20, 400, gfx);
				player1Head = HeadSelect::EMPEROR1;
				break;
			}
			case VK_F4:
			{
				selecting.CharacterSelector1(20, 430, gfx);
				player1Head = HeadSelect::LEIA1;
				break;
			}
			case VK_F5:
			{
				selecting.CharacterSelector1(20, 460, gfx);
				player1Head = HeadSelect::LUKE1;
				break;
			}
			case VK_F6:
			{
				selecting.CharacterSelector1(20, 490, gfx);
				player1Head = HeadSelect::REY1;
				break;
			}
			case VK_F7:
			{
				selecting.CharacterSelector1(20, 520, gfx);
				player1Head = HeadSelect::OBIWAN1;
				break;
			}
			case VK_F8:
			{
				selecting.CharacterSelector1(20, 545, gfx);
				player1Head = HeadSelect::AHSOKA1;
				break;
			}
			case '1':
			{
				selecting.SaberSelector1(210, 350, gfx);
				player1Color = LightsaberColor::BLUE1;
				break;
			}
			case '2':
			{
				selecting.SaberSelector1(210, 370, gfx);
				player1Color = LightsaberColor::GREEN1;
				break;
			}
			case '3':
			{
				selecting.SaberSelector1(210, 400, gfx);
				player1Color = LightsaberColor::RED1;
				break;
			}
			case '4':
			{
				selecting.SaberSelector1(210, 430, gfx);
				player1Color = LightsaberColor::PURPLE1;
				break;
			}

			}
		}
	}
	
	if (wnd.kbd.KeyIsPressed(VK_TAB))
	{
		char P2 = E->GetCode();
		if (E->IsPress())
		{// player 2 heads
			switch (P2)
			{
			case VK_F1:
			{
				selecting.CharacterSelector2(420, 350, gfx);
				player2Head = HeadSelect::ANAKIN2;
				break;
			}
			case VK_F2:
			{
				selecting.CharacterSelector2(420, 370, gfx);
				player2Head = HeadSelect::MARAJADE2;
				break;
			}
			case VK_F3:
			{
				selecting.CharacterSelector2(420, 400, gfx);
				player2Head = HeadSelect::EMPEROR2;
				break;
			}
			case VK_F4:
			{
				selecting.CharacterSelector2(420, 430, gfx);
				player2Head = HeadSelect::LEIA2;
				break;
			}
			case VK_F5:
			{
				selecting.CharacterSelector2(420, 460, gfx);
				player2Head = HeadSelect::LUKE2;
				break;
			}
			case VK_F6:
			{
				selecting.CharacterSelector2(420, 490, gfx);
				player2Head = HeadSelect::REY2;
				break;
			}
			case VK_F7:
			{
				selecting.CharacterSelector2(420, 520, gfx);
				player2Head = HeadSelect::OBIWAN2;
				break;
			}
			case VK_F8:
			{
				selecting.CharacterSelector2(420, 545, gfx);
				player2Head = HeadSelect::AHSOKA2;
				break;
			}
			case '1':
			{
				selecting.SaberSelector2(610, 350, gfx);
				player2Color = LightsaberColor::BLUE2;
				break;
			}
			case '2':
			{
				selecting.SaberSelector2(610, 370, gfx);
				player2Color = LightsaberColor::GREEN2;
				break;
			}
			case '3':
			{
				selecting.SaberSelector2(610, 400, gfx);
				player2Color = LightsaberColor::RED2;
				break;
			}
			case '4':
			{
				selecting.SaberSelector2(610, 430, gfx);
				player2Color = LightsaberColor::PURPLE2;
				break;
			}

			
			}
			
		}

	}

	
} // current 
void Game::DrawSelectingSaber()
{
	//player characters
	switch (player1Head)
	{
	case HeadSelect::ANAKIN1:
	{
		selecting.CharacterSelector1(20, 350, gfx);
		break;
	}
	case HeadSelect::MARAJADE1:
	{
		selecting.CharacterSelector1(20, 370, gfx);
		break;
	}
	case HeadSelect::EMPEROR1:
	{
		selecting.CharacterSelector1(20, 400, gfx);
		break;
	}
	case HeadSelect::LEIA1:
	{
		selecting.CharacterSelector1(20, 430, gfx);
		break;
	}
	case HeadSelect::LUKE1:
	{
		selecting.CharacterSelector1(20, 460, gfx);
		break;
	}
	case HeadSelect::REY1:
	{
		selecting.CharacterSelector1(20, 490, gfx);
		break;
	}
	case HeadSelect::OBIWAN1:
	{
		selecting.CharacterSelector1(20, 520, gfx);
		break;
	}
	case HeadSelect::AHSOKA1:
	{
		selecting.CharacterSelector1(20, 545, gfx);
		break;
	}
	}

	switch (player2Head)
	{
	case HeadSelect::ANAKIN2:
	{
		selecting.CharacterSelector2(420, 350, gfx);
		break;
	}
	case HeadSelect::MARAJADE2:
	{
		selecting.CharacterSelector2(420, 370, gfx);
		break;
	}
	case HeadSelect::EMPEROR2:
	{
		selecting.CharacterSelector2(420, 400, gfx);
		break;
	}
	case HeadSelect::LEIA2:
	{
		selecting.CharacterSelector2(420, 430, gfx);
		break;
	}
	case HeadSelect::LUKE2:
	{
		selecting.CharacterSelector2(420, 460, gfx);
		break;
	}
	case HeadSelect::REY2:
	{
		selecting.CharacterSelector2(420, 490, gfx);
		break;
	}
	case HeadSelect::OBIWAN2:
	{
		selecting.CharacterSelector2(420, 520, gfx);
		break;
	}
	case HeadSelect::AHSOKA2:
	{
		selecting.CharacterSelector2(420, 545, gfx);
		break;
	}
	}

	//lightsabers
	switch (player1Color)
	{
	case LightsaberColor::BLUE1:
	{
		selecting.SaberSelector1(210, 350, gfx);
		break;
	}
	case LightsaberColor::GREEN1:
	{
		selecting.SaberSelector1(210, 370, gfx);
		break;
	}
	case LightsaberColor::RED1:
	{
		selecting.SaberSelector1(210, 400, gfx);
		break;
	}
	case LightsaberColor::PURPLE1:
	{
		selecting.SaberSelector1(210, 430, gfx);
		break;
	}
	}

	switch (player2Color)
	{
	case LightsaberColor::BLUE2:
	{
		selecting.SaberSelector2(610, 350, gfx);
		break;
	}
	case LightsaberColor::GREEN2:
	{
		selecting.SaberSelector2(610, 370, gfx);
		break;
	}
	case LightsaberColor::RED2:
	{
		selecting.SaberSelector2(610, 400, gfx);
		break;
	}
	case LightsaberColor::PURPLE2:
	{
		selecting.SaberSelector2(610, 430, gfx);
		break;
	}
	}
}
//lightsaber selecting
void Game::ChosenLightSaber()
{
	unsigned char ColorValue = 127;
	    if (wnd.kbd.KeyIsPressed('1'))
		{
			selecting.SaberSelector1(210, 350, gfx);
			characters[PLAYER1].lightSaber.color[0] = Color{ 0,0,ColorValue };
			characters[PLAYER1].lightSaber.isSelected1 = true;
			
		}
		 if (wnd.kbd.KeyIsPressed('2'))
		{
			 selecting.SaberSelector1(210, 370, gfx);
			characters[PLAYER1].lightSaber.color[0] = Color{ 0,ColorValue,0 };
			characters[PLAYER1].lightSaber.isSelected1 = true;
		}
		 if (wnd.kbd.KeyIsPressed('3'))
		{
			 selecting.SaberSelector1(210, 400, gfx);
			characters[PLAYER1].lightSaber.color[0] = Color{ ColorValue,0,0 };
			characters[PLAYER1].lightSaber.isSelected1 = true;
		}
		if (wnd.kbd.KeyIsPressed('4'))
		{
			selecting.SaberSelector1(210, 430, gfx);
			characters[PLAYER1].lightSaber.color[0] = Color{ ColorValue,0,ColorValue };
			characters[PLAYER1].lightSaber.isSelected1 = true;
		}
	    
		if (wnd.kbd.KeyIsPressed('5'))
		{
			selecting.SaberSelector2(610, 350, gfx);
			characters[PLAYER2].lightSaber.color[0] = Color{ 0,0,ColorValue };
			characters[PLAYER2].lightSaber.isSelected2 = true;
		}
		if (wnd.kbd.KeyIsPressed('6'))
		{
			selecting.SaberSelector2(610, 370, gfx);
			characters[PLAYER2].lightSaber.color[0] = Color{ 0,ColorValue,0 };
			characters[PLAYER2].lightSaber.isSelected2 = true;
		}
		if (wnd.kbd.KeyIsPressed('7'))
		{
			selecting.SaberSelector2(610, 400, gfx);
			characters[PLAYER2].lightSaber.color[0] = Color{ ColorValue,0,0 };
			characters[PLAYER2].lightSaber.isSelected2 = true;
		}
		 if (wnd.kbd.KeyIsPressed('8'))
		{
			 selecting.SaberSelector2(610, 430, gfx);
			characters[PLAYER2 ].lightSaber.color[0] = Color{ ColorValue,0,ColorValue };
			characters[PLAYER2].lightSaber.isSelected2 = true;
		}
	
	
	if (characters[PLAYER1].lightSaber.isSelected1 && characters[PLAYER2].lightSaber.isSelected1)
	{
		LightsabersSelected = true;
		
	}
}



// Loop through characters and call selected character 
	// via a function pointer
void Game::CharacterDisplay()
{
	// Loop through characters and call selected character 
	// via a function pointer
	for (int i = 0; i < NUMBER_OF_CHRS; i++)
	{
		characters[i].Draw(gfx);
	}
}
//deal with lightsaber switching and saber length
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
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		characters[PLAYER2].lightSaber.isdown = true;
	}
	else {
		characters[PLAYER2].lightSaber.isdown = false;

	}
	
	for (int i = 0; i < 2; i++)
	{
		characters[i].lightSaber.length = 8;
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

void Game::StateChange(GameState state)
{
	stateofgame = state;
}
void Game::UpdateModel()
{ //switch statment not working.
	switch(stateofgame)
	{
	case GameState::TITLE:
	   {
		back.SaberColorChange();
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			StateChange(GameState::SELECTION);
		}
		break;
	   }
	case GameState::SELECTION:
	   {
		//backgroumd guard colorchange
		back.SaberColorChange();
		//PlayerCharacter(wnd.kbd.KeyIsPressed(VK_TAB));
		//here
		//ChosenLightSaber();
		TheMenuSelector(&wnd.kbd.ReadKey());

		if (wnd.kbd.KeyIsPressed(VK_SHIFT) && wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			StateChange(GameState::GAMESTART);
		}
		break;
	    }
	case GameState::GAMESTART:
	    {
		back.SaberColorChange();
		if (wnd.kbd.KeyIsPressed('N'))
		{
			Bolt.Respawn(Vec2{ 380,280 }, rng);

		}
		Bolt.update();
		
		for (int i = 0; i < NUMBER_OF_CHRS; ++i)
		{
			TestPlayerchar();
			Testchosesaber();
			UpdateLightSaber();
			//character movement and collision detections
			float movementspeed = 3.0f;
			Vec2 moveAmount = (*this.*GetMoveDirection[i])(movementspeed);
			characters[i].Move(moveAmount);
			//character to wall collision
			Vec2 reflection = collideManager.GetInnerReflection(characters[i].collider, back.colliders[i]);

			if (reflection.GetLengthSq())
			{
				characters[i].Move(reflection);

			}
			//for (int j = 0; j < 4; j++)
			//{
			//	//bolt to lightsaber collision
			//	bool SaberDeflection = collideManager.ReboundTestbool(Bolt.collider, characters[i].lightSaber.colliders[j]);
			//
			//	if (SaberDeflection)
			//	{
			//		Bolt.loc.x = -Bolt.loc.x;
			//	}
			//}
		}

	   //for (int j = 0; j < 4; j++)
	   //{
	   //	//bolt to lightsaber collision
	   //	bool SaberDeflection = collideManager.ReboundTestbool(Bolt.collider,Character::colliders[j]);
	   //
	   //	if (SaberDeflection)
	   //	{
	   //		Bolt.loc.x = -Bolt.loc.x;
	   //	}
	   //}
		
		
		//bolt to wall redirection
		Vec2 BoltRedirect = collideManager.GetInnerReflection(Bolt.collider, back.colliders[2]);
		if (BoltRedirect.GetLengthSq())
		{
			//adjust bolt location from off screen to put back on
			Bolt.loc += BoltRedirect;
			Bolt.collider.loc += BoltRedirect;

			//Bolt.Rebound();
			//if (BoltRedirect.x)
			{
				Bolt.vel.x = -Bolt.vel.x;

			}

			if (BoltRedirect.y)
			{
				Bolt.vel.y = -Bolt.vel.y;
			}

		}
		if (wnd.kbd.KeyIsPressed(VK_BACK))
		{
			StateChange(GameState::GAMEEND);
		}
		break;
		
	
	    }
	case GameState::GAMEEND:
	  {

		break;
	  }
    default:
	{ int i = 0; break; }
	}
	
}

void Game::ComposeFrame()
{
	switch (stateofgame)
	{
	case GameState::TITLE:
	   {
		back.EmperorThroneRoom(gfx);
		mainmenu.EmporerHand(gfx);
		mainmenu.EmporerDoit(gfx);
		mainmenu.TitleScreen(gfx);
		break;
	   }
	case GameState::SELECTION:
	  {
	 	back.EmperorThroneRoom(gfx);
		
		mainmenu.MainMenu(gfx);
		mainmenu.EmporerHand(gfx);
		mainmenu.EmporerSelect(gfx);
		DrawSelectingSaber();
		break;
	  }
	case GameState::GAMESTART:
	  {
		back.EmperorThroneRoom(gfx);
		Bolt.DrawLaser(gfx);
		

		Remote.DrawRemote(gfx);
		CharacterDisplay();
		//CharacterAnimation();
		characters[PLAYER1].SaberBackColorChange();
		characters[PLAYER2].SaberBackColorChange();
		break;
	  }
	case GameState::GAMEEND:
	  {
		back.EmperorThroneRoom(gfx);
		break;
	  }
	default:
	{ int i = 0; break; }
   
	}
}
