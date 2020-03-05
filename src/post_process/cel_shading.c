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
	r = (int)((r / CELSHADING) * CELSHADING << 24);
	g = (int)((g / CELSHADING) * CELSHADING << 16);
	b = (int)((b / CELSHADING) * CELSHADING << 8);
		return (r | g | b | (color & 0xFF));
}
