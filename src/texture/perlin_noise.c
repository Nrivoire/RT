/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 10:53:47 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void		bump_mapping(t_env *v, t_tab_obj *obj, t_vec *normal, t_vec point)
// {
// 	t_vec	bump;

// 	bump.x = noise(v, point.x - obj->tx_pertu, point.y, point.z) - noise(v, point.x + obj->tx_pertu, point.y, point.z);
// 	bump.y = noise(v, point.x, point.y - obj->tx_pertu, point.z) - noise(v, point.x, point.y + obj->tx_pertu, point.z);
// 	bump.z = noise(v, point.x, point.y, point.z - obj->tx_pertu) - noise(v, point.x, point.y, point.z + obj->tx_pertu);
// 	normal->x = bump.x + normal->x;
// 	normal->y = bump.y + normal->y;
// 	normal->z = bump.z + normal->z;
// }

float		perlin_noise(t_env *v, t_perlin p, t_vec normal)
{
	int		i;
	float	r;
	float	amplitude;
	float	lim;

	amplitude = 1.;
	r = 0;
	i = -1;
	//if (obj->procedural == BUMP)
	//	bump_mapping(v, obj, normal, pt);
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

void		create_texture_procedural(t_env *v, t_tab_obj *obj, t_vec pt, t_vec *normal)
{
	float	time;

	// if (obj->procedural == WAVES)
	// 	quadric_normal_pertu(obj->q, pt, obj->tx_pertu, normal);
	if (obj->procedural == PERLIN)
		time = perlin_noise(v, (t_perlin){1, 7, 2}, *normal);
	else if (obj->procedural == WOOD)
	{
		time = perlin_noise(v, (t_perlin){2, 1, 15}, *normal);
		time = (1. + sin((time / 2.) * 150.)) / 2;
	}
	else if (obj->procedural == MARBLE)
	{
		time = perlin_noise(v, (t_perlin){1, 4, 4}, *normal);
		time = (1. + cos((normal->x + time) * 12.)) / 3;
	}
	else if (obj->procedural == GRAD)
	{
		time = perlin_noise(v, (t_perlin){1, 2, 2}, normal);
		time = (1. + sin((time / 2.) * 20.)) / 2;
	}
	else
		return ;
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time,
				obj->color.b * time};
}
