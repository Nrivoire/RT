#include "../includes/rt.h"
#include "pp.h"

int		negative(int color)
{
	int		r;
	int		g;
	int		b;

	r = (255 - ((color >> 8) & 0xFF)) << 8;
	g = (255 - ((color >> 8) & 0xFF)) << 16;
	b = (255 - ((color >> 16) & 0xFF)) << 24;
	return (r | g | b);
}
