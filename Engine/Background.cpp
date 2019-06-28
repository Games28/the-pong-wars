#include "Background.h"

Background::Background(Graphics& gfx)
	:
	gfx(gfx),
	rng(std::random_device()()),
	colliders{ {Vec2(20,40), Vec2(BackBorderwidth,BackBorderHeight)}
		,{Vec2(480,40), Vec2(BackBorderwidth,BackBorderHeight)},
		 {Vec2(0,0), Vec2(Graphics::ScreenWidth - 1,Graphics::ScreenHeight - 1)} }
	
{
	std::uniform_int_distribution<int> xdist(350, 480);
	std::uniform_int_distribution<int> ydist(120, 250);
	for (int i = 0; i < maxRegularStars; i++)
	{
		Regularstars[i].StarSet(xdist(rng),ydist(rng));
	}
	for (int i = 0; i < maxBrightStars; i++)
	{
		Brightstars[i].StarSet(xdist(rng), ydist(rng));
	}
	
}

void Background::Midline(Graphics & gfx)
{
	Vec2 locTop{ 0,30 };
	gfx.DrawRectDim(int(locTop.x), int(locTop.y), Graphics::ScreenWidth, height, c);
	Vec2 locMid{ 0,300 };
	gfx.DrawRectDim(int(locMid.x), int(locMid.y), Graphics::ScreenWidth, height, c);
	Vec2 loc{ 0,320 };
	gfx.DrawRectDim(int(loc.x), int(loc.y), Graphics::ScreenWidth, height, c);
	Vec2 locBottom{ 0,570 };
	gfx.DrawRectDim(int(locBottom.x), int(locBottom.y), Graphics::ScreenWidth, height, c);
	Vec2 carpet1{ 360,320 };
	gfx.DrawRectDim(int(carpet1.x), int(carpet1.y), 4, 250, c);
	Vec2 carpet2{ 440,320 };
	gfx.DrawRectDim(int(carpet2.x), int(carpet2.y), 4, 250, c);

}

void Background::Throne(Graphics & gfx)
{

	Vec2 Armrest1{360,250};
	gfx.DrawRectDim(int(Armrest1.x) , int(Armrest1.y), height +4, ChairH, Colors::Gray);
	Vec2 Armrest2{440,250};
	gfx.DrawRectDim(int(Armrest2.x), int(Armrest2.y), height + 4 , ChairH, Colors::Gray);
	

}

void Background::Thestars(Graphics & gfx)
{
	BrightStarCounter++;
	if (BrightStarCounter >= BrightStarresetMax)
	{
		BrightStarCounter = 0;
	}

	for (int i = 0; i < maxRegularStars; i++)
	{
		Regularstars[i].DrawDStar(gfx);
	}
	for (int i = 0; i < maxBrightStars; i++)
	{
		if (BrightStarCounter > 50)
		{
			Brightstars[i].DrawBrightStar2(gfx);
		}
		else if (BrightStarCounter < 50)
		{
			Brightstars[i].DrawBrightStar1(gfx);
		}
	}
}

void Background::Window(Graphics & gfx)
{
	Vec2 WindowEdge{ 400,200 };
	gfx.DrawCircle(int(WindowEdge.x), int(WindowEdge.y), 100 + height, c);
	Vec2 Window{ 400,200 };
	gfx.DrawCircle(int(Window.x), int(Window.y), 100, Colors::Black);
	Vec2 Panel1{ 300,200 };
	gfx.DrawRectDim(int(Panel1.x), int(Panel1.y), 200, 4, c);
	Vec2 Panel2{ 400,100 };
	gfx.DrawRectDim(int(Panel2.x), int(Panel2.y), 4, 200, c);
	Vec2 innerWindowedge{ 400,200 };
	gfx.DrawCircle(int(innerWindowedge.x), int(innerWindowedge.y), 70 + height, c);
	Vec2 innerWindow{ 400,200 };
	gfx.DrawCircle(int(innerWindow.x), int(innerWindow.y), 70, Colors::Black);

}

void Background::SaberColorChange()
{
	if (colorIncreasing)
	{
		if (R.GetR() >= 253)
		{
			colorIncreasing = false;
		}
		else
		{
			R = Color(R.GetR() + 2, R.GetG()  , R.GetB() );
		}

	}
	else
	{
		if (R.GetR() <= 127)
		{
			colorIncreasing = true;
		}
		else
		{
			R = Color(R.GetR() - 2, R.GetG() , R.GetB());
		}

	}
}

void Background::EmperorThroneRoom(Graphics& gfx)
{
	Midline(gfx);
	Throne(gfx);
	Thestars(gfx);
	Window(gfx);
	art.Theemperor(355, 180, gfx);
	art.Vader(280, 120 ,gfx);
	art.EmperorGuard(100, 120, gfx);
	art.EmperorGuard(600, 120, gfx);
	art.GuardSaber(110, 90, gfx, R);
	art.GuardSaber(610, 90, gfx, R);
	//this is debug code
	for (int i = 0; i < 3; i++)
	{
		colliders[i].DrawBox(gfx, Colors::Cyan);
	}
	
}

void Background::TestCollision(Character& player)
{
	//for (int i = 0; i < player.NumberofCharacters; i++)
	//{
	//	const float PlayerLeft = player.CharacterBoundry[i].
	//}
}

