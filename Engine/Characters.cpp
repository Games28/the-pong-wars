#include "Characters.h"

Characters::Characters(Vec2 & in_loc)
	:
	loc(in_loc)
{
}
// Player 1 characters
void Characters::Leia1head(Graphics & gfx)
{
	gfx.Leia1head( int(loc.x), int(loc.y));
}

void Characters::Luke1head(Graphics & gfx)
{
	gfx.Luke1head( int(loc.x), int(loc.y));
}


void Characters::ahsoka1head(Graphics & gfx)
{
	gfx.ahsoka1head( int(loc.x), int(loc.y));
}

void Characters::emperor1head(Graphics & gfx)
{
	gfx.emperor1head( int(loc.x), int(loc.y));
}


void Characters::anakin1head(Graphics & gfx)
{
	gfx.anakin1head( int(loc.x), int(loc.y));
}


void Characters::Marajade1head(Graphics & gfx)
{
	gfx.Marajade1head( int(loc.x), int(loc.y));
}


void Characters::Rey1head(Graphics & gfx)
{
	gfx.Rey1head( int(loc.x), int(loc.y));
}


void Characters::Obiwan1head(Graphics & gfx)
{
	gfx.Obiwan1head( int(loc.x), int(loc.y));
}


//Player 1 robes
void Characters::Robe1(Graphics & gfx)
{
	gfx.Robe1( int(loc.x), int(loc.y));
}


void Characters::Robe1falling(Graphics & gfx)
{
	gfx.Robe1falling( int(loc.x), int(loc.y));
}


void Characters::Robe1fallen(Graphics & gfx)
{
	gfx.Robe1fallen( int(loc.x), int(loc.y));
}


void Characters::Robe1Stand(Graphics & gfx)
{
	gfx.Robe1Stand( int(loc.x), int(loc.y));
}


void Characters::Robe1moveX(Graphics & gfx)
{
	gfx.Robe1moveX( int(loc.x), int(loc.y));
}


void Characters::Robe1moveY(Graphics & gfx)
{
	gfx.Robe1moveY( int(loc.x), int(loc.y));
}


//Player 2 Characters
void Characters::Leia2head(Graphics & gfx)
{
	gfx.Leia2head( int(loc.x), int(loc.y));
}


void Characters::Luke2head(Graphics & gfx)
{
	gfx.Luke2head( int(loc.x), int(loc.y));
}


void Characters::ahsoka2head(Graphics & gfx)
{
	gfx.ahsoka2head( int(loc.x), int(loc.y));
}


void Characters::emperor2head(Graphics & gfx)
{
	gfx.emperor2head( int(loc.x), int(loc.y));
}


void Characters::anakin2head(Graphics & gfx)
{
	gfx.anakin2head( int(loc.x), int(loc.y));
}


void Characters::Marajade2head(Graphics & gfx)
{
	gfx.Marajade2head( int(loc.x), int(loc.y));
}


void Characters::Rey2head(Graphics & gfx)
{
	gfx.Rey2head( int(loc.x), int(loc.y));
}


void Characters::Obiwan2head(Graphics & gfx)
{
	gfx.Obiwan2head( int(loc.x), int(loc.y));
}

//Player 2 robes
void Characters::Robe2(Graphics & gfx)
{
	gfx.Robe2( int(loc.x), int(loc.y));
}


void Characters::Robe2falling(Graphics & gfx)
{
	gfx.Robe1falling( int(loc.x), int(loc.y));
}


void Characters::Robe2fallen(Graphics & gfx)
{
	gfx.Robe2fallen( int(loc.x), int(loc.y));
}

void Characters::Robe2Stand(Graphics & gfx)
{
	gfx.Robe2Stand( int(loc.x), int(loc.y));
}


void Characters::Robe2moveX(Graphics & gfx)
{
	gfx.Robe2moveX( int(loc.x), int(loc.y));
}


void Characters::Robe2moveY(Graphics & gfx)
{
	gfx.Robe2moveY( int(loc.x), int(loc.y));
}


void Characters::P1MovementUpdate(Keyboard & kbd)
{
	if (kbd.KeyIsPressed('W'))
	{
		loc.y--;
	}
	if (kbd.KeyIsPressed('S'))
	{
		loc.y++;
	}
	if (kbd.KeyIsPressed('A'))
	{
		loc.x--;
	}
	if (kbd.KeyIsPressed('D'))
	{
		loc.x++;
	}
}

void Characters::P2MovementUpdate(Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_UP))
	{
		loc.y--;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		loc.y++;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		loc.x--;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		loc.x++;
	}
}

void Characters::Player2Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 100))
	{
		loc.y = float(Graphics::ScreenHeight - 100) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 460)
	{
		loc.x = 460;
	}
	else if (right >= float(Graphics::ScreenWidth - 100))
	{
		loc.x = float(Graphics::ScreenWidth - 100) - width;
	}
}

void Characters::Player1Collision()
{
	const float bottom = loc.y + height;
	if (loc.y < 100)
	{
		loc.y = 100;
	}
	else if (bottom >= float(Graphics::ScreenHeight - 100))
	{
		loc.y = float(Graphics::ScreenHeight - 100) - height;
	}
	const float right = loc.x + width;
	if (loc.x < 50)
	{
		loc.x = 50;
	}
	else if (right >= float(Graphics::ScreenWidth - 530))
	{
		loc.x = float(Graphics::ScreenWidth - 530) - width;
	}
}
