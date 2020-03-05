#include "../includes/rt.h"
#include "pp.h"

int		greyscale(int color)
{
	t_color			rgb;
	unsigned int	v;

	rgb.r = color >> 24 & 0xFF;
	rgb.g = color >> 16 & 0xFF;
	rgb.b = color >> 8 & 0xFF;
	v = rgb.r * 0.212671 + rgb.g * 0.715160 + rgb.b * 0.072169;

	return (((int)v << 24) | ((int)v << 16) | (int)v << 8 | (color & 0xFF));
}
