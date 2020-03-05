/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:03:46 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/05 17:06:16 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	cam;
	t_ray			ray;

	ray.o = v->cam.ori;
	ray.d.x = v->cam.fov_x * (2. * x / v->w - 1);
	ray.d.y = v->cam.fov_y * (2. * y / v->h - 1);
	ray.d.z = -1;
	matrix_rotation(v->cam.angle_x, v->cam.angle_y, 0, cam);
	ray.d = matrix_mult_vec(cam, ray.d);
	ray.o = matrix_mult_vec(cam, v->cam.ori);
	return (ray);
}

float			diffuse_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float		dot;
	t_vec		light;

	light = vec_normalize(vec_sub(pos_light, px.point));
	dot = vec_scale_product(light, px.normale);
	return (dot);
}

void			calc_light(t_env *v, t_tab_obj closest, t_color *px_color)
{
	t_lst_lgt	*tmp;
	float		dot_diffuse_light;

	dot_diffuse_light = 0;
	float intensity = 0;
	tmp = v->p.lg;
	while (tmp)
	{
		if ((dot_diffuse_light = diffuse_light(v, closest, tmp->pos)) > 0)
		{
			intensity = dot_diffuse_light * tmp->intensity;
			px_color->r += tmp->color.r * intensity;
			px_color->g += tmp->color.g * intensity;
			px_color->b += tmp->color.b * intensity;
		}
		tmp = tmp->next;
	}
	px_color->r = (px_color->r + v->p.sc.amb_light.r) * closest.color.r;
	px_color->g = (px_color->g + v->p.sc.amb_light.g) * closest.color.g;
	px_color->b = (px_color->b + v->p.sc.amb_light.b) * closest.color.b;
	if (v->selected_obj && v->selected_obj->i == closest.i)
	{
		px_color->r *= 2;
		px_color->g *= 1.5;
		px_color->b *= 2.5;
	}
}

static void		big_pixel(t_env *v, int x, int y, t_color px_color)
{
	pixel_put(v, x, y, px_color);
	pixel_put(v, x, y + 1, px_color);
	pixel_put(v, x, y + 2, px_color);
	pixel_put(v, x, y + 3, px_color);
	pixel_put(v, x + 1, y, px_color);
	pixel_put(v, x + 2, y, px_color);
	pixel_put(v, x + 3, y, px_color);
	pixel_put(v, x + 1, y + 1, px_color);
	pixel_put(v, x + 2, y + 1, px_color);
	pixel_put(v, x + 3, y + 1, px_color);
	pixel_put(v, x + 1, y + 2, px_color);
	pixel_put(v, x + 2, y + 2, px_color);
	pixel_put(v, x + 3, y + 2, px_color);
	pixel_put(v, x + 1, y + 3, px_color);
	pixel_put(v, x + 2, y + 3, px_color);
	pixel_put(v, x + 3, y + 3, px_color);
}

double			fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));	
}

void			bruit_de_perlin(double x, double y, double z)
{
	int		permutation[256] = 
	{
		151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,
		142,8,99,37,240,21,10,23,190, 6,148,247,120,234,75,0,26,197,62,94,252,219,
		203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168, 68,175,
		74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,
		105,92,41,55,46,245,40,244,102,143,54, 65,25,63,161,1,216,80,73,209,76,132,
		187,208, 89,18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186,3,
		64,52,217,226,250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,
		47,16,58,17,182,189,28,42,223,183,170,213,119,248,152, 2,44,154,163, 70,221,
		153,101,155,167, 43,172,9,129,22,39,253, 19,98,108,110,79,113,224,232,178,185,
		112,104,218,246,97,228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,
		235,249,14,239,107,49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,
		127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,
		156,180
	};

	int			p[512];
	int			i;

	i = -1;
	while (++i < 511)
		p[i] = permutation[i & 255];

	int		xi;
	int		yi;
	int		zi;
	double	xf;
	double	yf;
	double	zf;

	xi = (int)x & 255;
	yi = (int)y & 255;
	zi = (int)z & 255;
	xf = x - (int)x;
	yf = y - (int)y;
	zf = z - (int)z;

	double u = fade(xf);
	double v = fade(yf);
	double w = fade(zf);

	int aaa, aba, aab, abb, baa, bba, bab, bbb;
    aaa = p[p[p[    xi ]+    yi ]+    zi ];
    aba = p[p[p[    xi ]+inc(yi)]+    zi ];
    aab = p[p[p[    xi ]+    yi ]+inc(zi)];
    abb = p[p[p[    xi ]+inc(yi)]+inc(zi)];
    baa = p[p[p[inc(xi)]+    yi ]+    zi ];
    bba = p[p[p[inc(xi)]+inc(yi)]+    zi ];
    bab = p[p[p[inc(xi)]+    yi ]+inc(zi)];
    bbb = p[p[p[inc(xi)]+inc(yi)]+inc(zi)];
}

void			bouclette(t_env *v)
{
	int			x;
	int			y;
	t_ray		ray;
	t_tab_obj	closest;
	t_color		px_color;

	y = 0;
	while (y <= v->h)
	{
		x = 0;
		while (x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (closest_intersect(v, ray, &closest))
			{
				px_color = (t_color) {0, 0, 0, 255};
				if (closest.texture)
					generate_texture(&closest);
				calc_light(v, closest, &px_color);
				if (v->ppc.render_size == 1)
					pixel_put(v, x, y, px_color);
				else if (v->ppc.render_size == 4)
					big_pixel(v, x, y, px_color);
			}
			x = x + v->ppc.render_size;
		}
		y = y + v->ppc.render_size;
	}
}
