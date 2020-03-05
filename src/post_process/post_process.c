#include "../includes/rt.h"
#include "pp.h"

static int		get_hex(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

t_color		color_ssp(Uint32 pixel)
{
	int		r;
	int		g;
	int		b;
	int		a;
	t_color	color;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	a = pixel & 0xFF;
	color = (t_color){r, g, b, a};
	return (color);
}

void			supersampling(t_env *v)
{
	t_color		calcul_ssp[4];
	t_color		ssp;
	int			x;
	int			y;

	y = -1;
	while (++y < v->h)
	{
		x = -1;
		while (++x < v->w)
		{
			calcul_ssp[0] = color_ssp(v->pixels[y * v->w + x]);
			calcul_ssp[1] = color_ssp(v->pixels[y * v->w + (x + 1)]);
			calcul_ssp[2] = color_ssp(v->pixels[(y + 1) * v->w + x]);
			calcul_ssp[3] = color_ssp(v->pixels[(y + 1) * v->w + (x + 1)]);
			ssp.r = (calcul_ssp[0].r + calcul_ssp[1].r + calcul_ssp[2].r + calcul_ssp[3].r) * 0.25;
			ssp.g = (calcul_ssp[0].g + calcul_ssp[1].g + calcul_ssp[2].g + calcul_ssp[3].g) * 0.25;
			ssp.b = (calcul_ssp[0].b + calcul_ssp[1].b + calcul_ssp[2].b + calcul_ssp[3].b) * 0.25;
			ssp.a = (calcul_ssp[0].a + calcul_ssp[1].a + calcul_ssp[2].a + calcul_ssp[3].a) * 0.25;
			v->pixels[y * v->w + x] = get_hex(ssp.r, ssp.g, ssp.b, ssp.a);
		}
	}
}

// motion blur