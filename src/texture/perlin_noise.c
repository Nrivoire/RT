/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/20 16:12:26 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		perlin_noise(t_env *v, t_perlin p, t_vec normal)
{
	int		i;
	float	r;
	float	amplitude;
	float	lim;

	amplitude = 1.;
	r = 0;
	i = -1;
	while (++i < p.octaves)
	{
		r += noise(v, normal.x * p.frequency, normal.y * p.frequency,
				normal.z * p.frequency) * amplitude;
		amplitude *= p.persistence;
		p.frequency *= 2;
	}
	lim = (1 - p.persistence) / (1 - amplitude);
	return (r * lim);
}

void		create_texture_procedural(t_env *v, t_tab_obj *obj, t_vec normal)
{
	float	time;

	if (obj->procedural == PERLIN)
		time = perlin_noise(v, (t_perlin){1, 7, 2}, normal);
	else if (obj->procedural == WOOD)
	{
		time = perlin_noise(v, (t_perlin){2, 1, 15}, normal);
		time = (1. + sin((time / 2.) * 150.)) / 2;
	}
	else if (obj->procedural == MARBLE)
	{
		time = perlin_noise(v, (t_perlin){1, 7, 2}, normal);
		time = sin(normal.x + time * 12) / 24;
	}
	else
		return ;
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time,
				obj->color.b * time};
}
