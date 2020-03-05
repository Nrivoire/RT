#include "../includes/rt.h"
#include "pp.h"

t_color			get_ssp_value(t_env *v, int x, int y, t_color px_color)
{
	//t_ray		dir;
	//t_tab_obj	obj;
	//t_color		ssp;

	//dir = create_ray(v, x, y);
	//obj = closest_intersect(v, (t_ray){dir, v->cam.ori}, );
	//if (!obj.type)
	//	return ((t_color){0.1, 0.1, 0.1});
	//ssp = calc_light(v, obj, &ssp);

	//return (ssp);
}

void	supersampling(t_env *v, int x, int y, t_color px_color)
{
	t_color		calcul_ssp[4];
	t_color		ssp;

	//calcul_ssp[0] = get_ssp_value(v, x, y, px_color);
	//calcul_ssp[1] = get_ssp_value(v, x + 0.5, y, px_color);
	//calcul_ssp[2] = get_ssp_value(v, x , y + 0.5, px_color);
	//calcul_ssp[3] = get_ssp_value(v, x + 0.5, y + 0.5, px_color);
	//calcul_ssp[0] = v->pixels[15];
	ssp.r = (calcul_ssp[0].r + calcul_ssp[1].r + calcul_ssp[2].r + calcul_ssp[3].r) * 0.25;
	ssp.g = (calcul_ssp[0].g + calcul_ssp[1].g + calcul_ssp[2].g + calcul_ssp[3].g) * 0.25;
	ssp.b = (calcul_ssp[0].b + calcul_ssp[1].b + calcul_ssp[2].b + calcul_ssp[3].b) * 0.25;
	v->pixels[y * v->w + x] = get_hex_rgba(ssp.r * 255, ssp.g * 255, ssp.b * 255, px_color.a);
}

// motion blur