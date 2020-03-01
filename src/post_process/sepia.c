#include "../includes/rt.h"
#include "pp.h"

int		sepia(int color)
{
	int				r;
	int				g;
	int				b;
	unsigned int	v;

	r = color >> 24 & 0xFF;
	g = color >> 16 & 0xFF;
	b = color >> 8 & 0xFF;
	v = (MIN((int)255, (int)((float)(r) * 0.393 + (float)(g) * 0.769 + (float)(b) * 0.189)) << 24)
		| (MIN((int)255, (int)((float)(r) * 0.349 + (float)(g) * 0.686 + (float)(b) * 0.168)) << 16)
		| (MIN((int)255, (int)((float)(r) * 0.272 + (float)(g) * 0.534 + (float)(b) * 0.131)) << 8);

	return (v);
}
