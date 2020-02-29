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
	if (r < 220 && g < 220 && b < 220)
	{
		r = ((int)(((color >> 24) & 0xFF) / CELSHADING) * CELSHADING << 24);
		g = ((int)(((color >> 16) & 0xFF) / CELSHADING) * CELSHADING << 16);
		b = ((int)(((color >> 8) & 0xFF) / CELSHADING) * CELSHADING << 8);
		return (r | g | b);
	}
	return (color);
}

Uint32	greyscale(Uint32 pixel)
{
	Uint8	r;
	Uint8	g;
	Uint8	b;
	Uint8	v;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	v = (r + g + b) / 3;
	//Uint32 px = 
	//v = r * 0.212671 + g * 0.715160 * 0.072169 + b;
	
	Uint8 px = (0xFF << 24) | (v << 16) | (v << 8) | v;

	return (px);
}
