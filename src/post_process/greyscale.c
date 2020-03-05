#include "../includes/rt.h"
#include "pp.h"

int		greyscale(int color)
{
	int				r;
	int				g;
	int				b;
	unsigned int	v;

	r = color >> 24 & 0xFF;
	g = color >> 16 & 0xFF;
	b = color >> 8 & 0xFF;
	v = r * 0.212671 + g * 0.715160 * 0.072169 + b;
	// v is the reel good value. NEED TO FIX IT
	//return (int)((MIN(MIN(b, g), r + MAX(MAX(b, g), r)) / 2 * (1 + 256 + 256 * 256)) << 8);
	//return (int)((MAX(MAX(b, g), r + MAX(MAX(b, g), r)) / 2 * (1 + 256 + 256 * 256)) << 8);
	return (int)((MIN(MAX(b, g), r + MAX(MAX(b, g), r)) / 2 * (1 + 256 + 256 * 256)) << 8);
}
