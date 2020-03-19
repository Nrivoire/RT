/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 19:55:41 by nrivoire         ###   ########lyon.fr   */
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

	if (obj->procedural == PERLIN)
		time = perlin_noise(1, 7, 2, *obj);
	if (obj->procedural == WOOD)
	{
		time = perlin_noise(2, 1, 15, *obj);
		time = (1. + sin((time / 2.) * 150.)) / 2;
	}
	else if (obj->procedural == MARBLE)
	{
		time = perlin_noise(1, 7, 2, *obj);
		time = sin(obj->normale.x + time * 12) / 24;
	}
	else if (obj->procedural == CHESS)
		time = checkboard(*obj);
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time,
				obj->color.b * time, 255};
}
