/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:22 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/06 16:07:01 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

// t_vec			*gradient()
// {
// 	float	unit;
// 	t_vec	gradient[12];

// 	unit = 1.0f / sqrt(2);
// 	gradient[0] = (t_vec){unit, unit, 0};
// 	gradient[1] = (t_vec){-unit, unit, 0};
// 	gradient[2] = (t_vec){unit, -unit, 0};
// 	gradient[3] = (t_vec){-unit, -unit, 0};
// 	gradient[4] = (t_vec){unit, 0, unit};
// 	gradient[5] = (t_vec){-unit, 0, unit};
// 	gradient[6] = (t_vec){unit, 0, -unit};
// 	gradient[7] = (t_vec){-unit, 0, -unit};
// 	gradient[8] = (t_vec){0, unit, unit};
// 	gradient[9] = (t_vec){0, -unit, unit};
// 	gradient[10] = (t_vec){0, unit, -unit};
// 	gradient[11] = (t_vec){0, -unit, -unit};
// 	return (gradient);
// }

// t_mapping		data_mapping(float start1, float stop1,
// 		float start2, float stop2)
// {
// 	t_mapping	map;

// 	map.start1 = start1;
// 	map.stop1 = stop1;
// 	map.start2 = start2;
// 	map.stop2 = stop2;
// 	return (map);
// }

// float			map(float var, t_mapping s)
// {
// 	float		result;

// 	result = s.start2 + (s.stop2 - s.start2) * ((var - s.start1) /
// 			(s.stop1 - s.start1));
// 	return (result);
// }

int				*init_bruit_de_perlin()
{
	int		permutation[256] = 
	{
		151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,
		69,142,8,99,37,240,21,10,23,190, 6,148,247,120,234,75,0,26,197,62,94,
		252,219,203,117,35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,
		168, 68,175,74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,
		60,211,133,230,220,105,92,41,55,46,245,40,244,102,143,54, 65,25,63,161,
		1,216,80,73,209,76,132,187,208, 89,18,169,200,196,135,130,116,188,159,
		86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,202,38,147,
		118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,223,183,
		170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
		129,22,39,253, 19,98,108,110,79,113,224,232,178,185,112,104,218,246,97,
		228,251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,
		239,107,49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,
		127,4,150,254,138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,
		215,61,156,180
	};
	int			p[512];
	int			i;

	i = -1;
	while (++i < 511)
		p[i] = permutation[i & 255];
	return (p);
}

float			dot_gradient_noise(int hash, float x, float y, float z)
{
	int			h;
	float		u;
	float		v;

	h = hash & 15;
	u = h < 8 ? x : y;
	if (h < 4)
		v = y;
	else if (h == 12 || h == 14)
		v = x;
	else
		v = z;
	return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

static float	fade(float t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10)); 
}

float			lerp(float a, float b, float weight)
{
	return (a + weight * (b - a));
}

float			perlin_noise(float x, float y, float z)
{
	int			xi;
	int			yi;
	int			zi;
	int			*p;
	float		n;
	t_vec		*g;
	int			xoff;
	int			yoff;
	int			zoff;
	float		u;
	float		v;
	float		w;
	int aaa, aba, aab, abb, baa, bba, bab, bbb;

	p = init_bruit_de_perlin();
	xi = (int)x & 255;
	yi = (int)y & 255;
	zi = (int)z & 255;
	xoff = x - (int)x;
	yoff = y - (int)y;
	zoff = z - (int)z;
	u = fade(xoff);
	v = fade(yoff);
	w = fade(zoff);
    aaa = p[p[p[xi]+ yi] + zi];
    aba = p[p[p[xi]+ yi + 1] + zi];
    aab = p[p[p[xi]+ yi] + zi + 1];
    abb = p[p[p[xi]+ yi + 1] + zi + 1];
    baa = p[p[p[xi + 1] + yi] + zi];
    bba = p[p[p[xi + 1] + yi + 1]+ zi];
    bab = p[p[p[xi + 1] + yi] + zi + 1];
    bbb = p[p[p[xi + 1] + yi + 1] + zi + 1];

	float	x1;
	float	x2;
	float	y1;
	float	y2;

	x1 = lerp(dot_gradient_noise(aaa, xoff, yoff, zoff), dot_gradient_noise(aba, xoff - 1, yoff, zoff), u);
	x2 = lerp(dot_gradient_noise(aab, xoff, yoff - 1, zoff), dot_gradient_noise(abb, xoff - 1, yoff - 1, zoff), u);
	y1 = lerp(x1, x2, v);
	x1 = lerp(dot_gradient_noise(baa, xoff, yoff, zoff - 1), dot_gradient_noise(aba, xoff - 1, yoff, zoff - 1), u);
	x2 = lerp(dot_gradient_noise(bba, xoff, yoff - 1, zoff - 1), dot_gradient_noise(aba, xoff - 1, yoff - 1, zoff - 1), u);
	y2 = lerp(x1, x2, v);
	return ((lerp(y1, y2, w) + 1) / 2);
}

void		create_texture_procedural(t_tab_obj *obj)
{
    t_color	c;

    c.r = perlin_noise(obj->point.x, obj->point.y, obj->point.z);
	c.g = perlin_noise(obj->point.x, obj->point.y, obj->point.z);
	c.b = perlin_noise(obj->point.x, obj->point.y, obj->point.z);
    obj->color = (t_color){c.r / 255.0, c.g / 255.0, c.b / 255.0, 255};
}
