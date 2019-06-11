#include "Characters.h"

Characters::Characters(Vec2 & in_loc)
	:
	loc(in_loc)
{
}
// Player 1 characters
void Characters::Leia1head(Graphics & gfx)
{
	gfx.Leia1head(gfx, int(loc.x), int(loc.y));
}

void Characters::Luke1head(Graphics & gfx)
{
	gfx.Luke1head(gfx, int(loc.x), int(loc.y));
}


void Characters::ahsoka1head(Graphics & gfx)
{
	gfx.ahsoka1head(gfx, int(loc.x), int(loc.y));
}

void Characters::emperor1head(Graphics & gfx)
{
	gfx.emperor1head(gfx, int(loc.x), int(loc.y));
}


void Characters::anakin1head(Graphics & gfx)
{
	gfx.anakin1head(gfx, int(loc.x), int(loc.y));
}


void Characters::Marajade1head(Graphics & gfx)
{
	gfx.Marajade1head(gfx, int(loc.x), int(loc.y));
}


void Characters::Rey1head(Graphics & gfx)
{
	gfx.Rey1head(gfx, int(loc.x), int(loc.y));
}


void Characters::Obiwan1head(Graphics & gfx)
{
	gfx.Obiwan1head(gfx, int(loc.x), int(loc.y));
}


//Player 1 robes
void Characters::Robe1(Graphics & gfx)
{
	gfx.Robe1(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe1falling(Graphics & gfx)
{
	gfx.Robe1falling(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe1fallen(Graphics & gfx)
{
	gfx.Robe1fallen(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe1Stand(Graphics & gfx)
{
	gfx.Robe1Stand(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe1moveX(Graphics & gfx)
{
	gfx.Robe1moveX(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe1moveY(Graphics & gfx)
{
	gfx.Robe1moveY(gfx, int(loc.x), int(loc.y));
}


//Player 2 Characters
void Characters::Leia2head(Graphics & gfx)
{
	gfx.Leia2head(gfx, int(loc.x), int(loc.y));
}


void Characters::Luke2head(Graphics & gfx)
{
	gfx.Luke2head(gfx, int(loc.x), int(loc.y));
}


void Characters::ahsoka2head(Graphics & gfx)
{
	gfx.ahsoka2head(gfx, int(loc.x), int(loc.y));
}


void Characters::emperor2head(Graphics & gfx)
{
	gfx.emperor2head(gfx, int(loc.x), int(loc.y));
}


void Characters::anakin2head(Graphics & gfx)
{
	gfx.anakin2head(gfx, int(loc.x), int(loc.y));
}


void Characters::Marajade2head(Graphics & gfx)
{
	gfx.Marajade2head(gfx, int(loc.x), int(loc.y));
}


void Characters::Rey2head(Graphics & gfx)
{
	gfx.Rey2head(gfx, int(loc.x), int(loc.y));
}


void Characters::Obiwan2head(Graphics & gfx)
{
	gfx.Obiwan2head(gfx, int(loc.x), int(loc.y));
}

//Player 2 robes
void Characters::Robe2(Graphics & gfx)
{
	gfx.Robe2(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe2falling(Graphics & gfx)
{
	gfx.Robe1falling(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe2fallen(Graphics & gfx)
{
	gfx.Robe2fallen(gfx, int(loc.x), int(loc.y));
}

void Characters::Robe2Stand(Graphics & gfx)
{
	gfx.Robe2Stand(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe2moveX(Graphics & gfx)
{
	gfx.Robe2moveX(gfx, int(loc.x), int(loc.y));
}


void Characters::Robe2moveY(Graphics & gfx)
{
	gfx.Robe2moveY(gfx, int(loc.x), int(loc.y));
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
