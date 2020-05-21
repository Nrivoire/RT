/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 15:25:47 by vasalome         ###   ########lyon.fr   */
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

void		grad_texture(t_tab_obj *obj, float time)
{
	t_vec		grad;

	grad = obj->pos;
	grad.x < 0 ? grad.x = -grad.x : 0;
	grad.y < 0 ? grad.y = -grad.y : 0;
	grad.z < 0 ? grad.z = -grad.z : 0;
	grad.x > 255 ? grad.x = -grad.x : 0;
	grad.y > 255 ? grad.y = -grad.y : 0;
	grad.z > 255 ? grad.z = -grad.z : 0;
	if (obj->procedural == GRAD)
	{
		if (time >= 0.0 && time < 0.15)
			obj->color = (t_color){grad.x, grad.y, grad.z};
		else if (time < 0.35)
			obj->color = (t_color){grad.y, grad.z, grad.x};
		else if (time < 0.70)
			obj->color = (t_color){grad.z, grad.x, grad.y};
		else
			obj->color = (t_color){grad.z, grad.x, grad.y};
	}
}

void		create_texture_procedural(t_env *v, t_tab_obj *obj, t_vec *normal)
{
	float	time;

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
		time = perlin_noise(v, (t_perlin){1, obj->tx_pertu, 2}, *normal);
		time = (1. + sin((time / 2.) * 20.)) / 2;
	}
	else
		return ;
	if (time >= 0 && obj->procedural != GRAD)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time,
				obj->color.b * time};
	grad_texture(obj, time);
}
