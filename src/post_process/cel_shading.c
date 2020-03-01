#include "../includes/rt.h"
#include "pp.h"

int		cel_shading(int color)
{
	int		r;
	int		g;
	int		b;

	r = color >> 24 & 0xFF;
	g = color >> 16 & 0xFF;
	b = color >> 8 & 0xFF;
	// if (r < 210 && g < 210 && b < 210)
	// {
		r = (int)((r / CELSHADING) * CELSHADING << 24);
		g = (int)((g / CELSHADING) * CELSHADING << 16);
		b = (int)((b / CELSHADING) * CELSHADING << 8);
		return (r | g | b);
	// }
	// return (color);
}
/*
int		scale(int col)
{
	if (col <= 0)
		return (0);
	else if (col > 0 && col <= 50)
		return (25);
	else if (col > 50 && col <= 100)
		return (75);
	else if (col > 100 && col <= 200)
		return (150);
	else if (col > 200 && col < 250)
		return (225);
	else if (col >= 255)
		return (255);
	return (col);
}

int		cel_shading(int color)
{
	int		r;
	int		g;
	int		b;

	r = scale(color >> 24 & 0xFF);
	g = scale(color >> 16 & 0xFF);
	b = scale(color >> 8 & 0xFF);

	if (r != 0)
		printf("%d de r", r);
	return (r | g | b);
}*/
