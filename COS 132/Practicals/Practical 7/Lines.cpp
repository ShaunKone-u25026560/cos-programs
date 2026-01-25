#include <iostream>
#include "Lines.h"
#include "Screen.h"

float implicitLineEquation(int p0x, int p0y, int p1x, int p1y, float x, float y)
{
	return (p0y - p1y)*x + (p1x - p0x)*y + (p0x*p1y - p1x*p0y);
}

int min(int v1, int v2)
{
	return (v1 < v2)? v1: v2;
}

int max(int v1, int v2)
{
	return (v1 > v2)? v1 : v2;
}

int absV(int v)
{
	return (v < 0)? v * -1: v;
}

float absV(float v)
{
	return (v < 0)? v * -1: v;
}

float gradient(int p0x, int p0y, int p1x, int p1y)
{
	float dy = p1y - p0y;
	float dx = p1x - p0x;

	float grad = dy/dx;


	if (dx == 0)
	{
		return 0;
	}else
		return grad;
}

void drawLineA(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	for (int i = 0; i <= absV(p1y - p0y); i++)
	{
		(min(p0y, p1y) == p0y)? Screen::draw(p0x, p0y + i, symbol): Screen::draw(p0x, p1y + i, symbol);
	}
}

void drawLineB(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	for (int i = 0; i <= absV(p1x - p0x); i++)
	{
		(min(p0x, p1x) == p0x)? Screen::draw(p0x + i, p0y, symbol): Screen::draw(p1x + i, p0y, symbol) ;
	}
}

void drawLineC(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	if (min(p0x, p1x) != p0x)
	{
		drawLineC(p1x, p1y, p0x, p0y, symbol);
	}else{

	int y = p0y;

	for (int x = p0x; x <= p1x; x++)
	{
		Screen::draw(x, y, symbol);
		if ( implicitLineEquation(p0x, p0y, p1x, p1y, x + 1, y + 0.5) < 0 )
		{
			y += 1;
		}
	}

	}
}

void drawLineD(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	if (min(p0x, p1x) != p0x)
        {
                drawLineD(p1x, p1y, p0x, p0y, symbol);
        }else{

	int y = p0y;

	for (int x = p0x; x <= p1x; x++)
	{
		Screen::draw(x, y, symbol);
		if ( implicitLineEquation(p0x, p0y, p1x, p1y, x + 1, y - 0.5) > 0 )
		{
			y -= 1;
		}
	}
	}
}

void drawLineE(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	if (min(p0x, p1x) != p0x)
        {
                drawLineE(p1x, p1y, p0x, p0y, symbol);
        }else{
	int x = p0x;

	for (int y = p0y; y <= p1y; y++)
	{
		Screen::draw(x, y , symbol);
		if ( implicitLineEquation(p0x, p0y, p1x, p1y, x + 0.5, y + 1) > 0 )
		{
			x += 1;
		}
	}
	}
}

void drawLineF(int p0x, int p0y, int p1x, int p1y, char symbol)
{
	if (min(p0x, p1x) != p0x)
        {
                drawLineF(p1x, p1y, p0x, p0y, symbol);
        }else{
        int x = p0x;

        for (int y = p0y; y >= p1y; y--)
        {
                Screen::draw(x, y , symbol);
                if ( implicitLineEquation(p0x, p0y, p1x, p1y, x + 0.5, y - 1) < 0 )
                {
                        x += 1;
                }
        }
	}
}

void drawLine(int p0x, int p0y, int p1x, int p1y, char symbol)
{

	float grad = gradient(p0x, p0y, p1x, p1y);

	if (p0x == p1x)
		drawLineA(p0x, p0y, p1x, p1y, symbol);
	else if (p0y == p1y)
		drawLineB(p0x, p0y, p1x, p1y, symbol);
	else if ( (grad  > 0) && (grad < 1) )
		drawLineC(p0x, p0y, p1x, p1y, symbol);
	else if ( (grad > -1) && (grad < 0) )
		drawLineD(p0x, p0y, p1x, p1y, symbol);
	else if (grad >= 1)
		drawLineE(p0x, p0y, p1x, p1y, symbol);
	else if (grad <= -1)
		drawLineF(p0x, p0y, p1x, p1y, symbol);
}
