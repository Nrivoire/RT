/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 06:46:04 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		bump_mapping(t_env *v, t_vec *normal, t_vec point)
{
	float	noise_coefx;
	float	noise_coefy;
	float	noise_coefz;

	noise_coefx = noise(v, 0.1f * point.x, 0.1f * point.y, 0.1f * point.z);
	noise_coefy = noise(v, 0.1f * point.y, 0.1f * point.z, 0.1f * point.x);
	noise_coefz = noise(v, 0.1f * point.z, 0.1f * point.x, 0.1f * point.y);
	normal->x = (1.0f - 0.5f) * normal->x + 0.5f * noise_coefx;
	normal->y = (1.0f - 0.5f) * normal->y + 0.5f * noise_coefy;
	normal->z = (1.0f - 0.5f) * normal->z + 0.5f * noise_coefz;
}

float		texture_color_move(float x)
{
	return ((1 - round((2 * (x - floor(x)) - 1))));
}

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec *normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural == GRAD)
	{
		obj->color.r = texture_color_move(obj->q.a * obj->q.b);
		obj->color.g = texture_color_move(obj->q.a * obj->q.c);
		obj->color.b = texture_color_move(obj->q.b * obj->q.c);
	}
	if (obj->procedural)
	{
		if (obj->procedural == BUMP)
			bump_mapping(v, normal, point);
		if (obj->procedural == WAVES)
			quadric_normal_pertu(obj->q, point, obj->tx_pertu, normal);
		else if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, *normal);
	}
	else
	{
		if (obj->type == 1)
			make_texture_sphere(obj, point, col);
		if (obj->type == 4)
			make_texture_cylinder(obj, point, col);
		if (obj->type == 2)
			make_texture_plan(obj, point);
	}
}
