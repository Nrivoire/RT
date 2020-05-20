/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/20 15:18:44 by vasalome         ###   ########lyon.fr   */
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
	else if (obj->procedural == GRAD)
	{
		// t_vec tmp;
		// unsigned int x, y, z;
		// tmp = sub(quadric_normal(obj->q, obj->pos), obj->pos);
		// y = (unsigned int) round(tmp.y * 0.1);
		// z = (unsigned int) round(tmp.z * 0.1);
		// if (obj->pos.x >= 0)
		// 	x = (unsigned int)round(tmp.x * 0.1);
		// if (z % 2)
		// {
		// 	if ((x % 2 && y % 2) || (!(x % 2) && !(y % 2)))
		// 		obj->color = obj->color;
		// 	else
		// 		obj->color = (t_color){0,0,0};
		// }
		time = 1;
	}
	else
		return ;
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time,
				obj->color.b * time};
}

//////////////
// static void	type_damier(t_obj *obj, unsigned int x, unsigned int y,
//                            unsigned int z)
// {
// 	t_vec tmp;
// 	tmp = sub(quadric_normal(obj->q, obj->pos), obj->pos);
// 	y = (unsigned int) round(tmp.y * 0.1);
// 	z = (unsigned int) round(tmp.z * 0.1);
// 	if (obj->pos.x >= 0)
// 		x = (unsigned int)round(tmp.x * 0.1);

//     if (z % 2)
//     {
//         if ((x % 2 && y % 2) || (!(x % 2) && !(y % 2)))
//             obj->color = obj->color;
//         else
//             obj->color = 0xFF;
//     }
//     else
//     {
//         if ((((x % 2 && y % 2) || (!(x % 2) && !(y % 2))) && (obj->type == 16 ||
//                 obj->type == 2 || obj->type == 4)) || (!((x % 2 && y % 2) ||
//                 (!(x % 2) && !(y % 2))) && !(obj->type == 16 || obj->type == 2
//                 || obj->type == 4)))
//             obj->color = obj->color;
//         else
//             obj->color = 0xFF;
//     }
// }