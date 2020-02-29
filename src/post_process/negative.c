#include "../includes/rt.h"
#include "pp.h"

int		negative(int color)
{
	int		r;
	int		g;
	int		b;

	r = 255 - (color & 0xFF);
	g = (255 - ((color >> 8) & 0xFF)) << 8;
	b = (255 - ((color >> 16) & 0xFF)) << 16;
	return (r | g | b);
}
