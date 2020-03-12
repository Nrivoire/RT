/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 13:14:28 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float		perlin_noise(int octaves, float f, float persistence, t_tab_obj obj)
{
	int		i;
	float	r;
	float	amplitude;
	float	lim;

	amplitude = 1.;
	r = 0;
	i = -1;
	while (++i < octaves)
	{
		r += noise(obj.normale.x * f, obj.normale.y * f, obj.normale.z * f) *
				amplitude;
		amplitude *= persistence;
		f *= 2;
	}
	lim = (1 - persistence) / (1 - amplitude);
	return (r * lim);
}

void		create_texture_procedural(t_tab_obj *obj)
{
	float	time;
	t_vec	t;

	//int c = 12;
	//time = noise(obj->normale.x * c, obj->normale.y * c, obj->normale.z * c);
	//t.x = noise(obj->normale.x, obj->normale.y, obj->normale.z);
	//t.y = noise(obj->normale.y, obj->normale.z, obj->normale.x);
	//t.z = noise(obj->normale.z, obj->normale.x, obj->normale.y);
	//obj->normale.x = obj->normale.x * t.x;
	//obj->normale.y = obj->normale.y * t.y;
	//obj->normale.z = obj->normale.z * t.z;
	time = perlin_noise(1, 7, 2, *obj);
	//if (obj->texture == WOOD)
	//	time = (1. + sin((time / 2.) * 150.)) / 2;
	//if (obj->texture == MARBRE)
	//time = sin(obj->normale.x + 1. / time);
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time, obj->color.b * time, 255};
}
