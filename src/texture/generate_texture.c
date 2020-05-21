/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 11:40:24 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			texture_color_move(float x)
{
	return ((1 - round((2 * (x - floor(x)) - 1))));
}

void			pos_color(t_tab_obj *obj)
{
	obj->color.r = texture_color_move(obj->pos.x + obj->pos.y * 10);
	obj->color.g = texture_color_move(obj->pos.y + obj->pos.z * 10);
	obj->color.b = texture_color_move(obj->pos.x + obj->pos.z * 10);
}

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec *normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural == GRAD)
	{
		pos_color(obj);
		// obj->color.r = texture_color_move(obj->pos.x * obj->pos.y);
		// obj->color.g = texture_color_move(obj->pos.y * obj->pos.z);
		// obj->color.b = texture_color_move(obj->pos.x * obj->pos.z);
	}
	if (obj->procedural)
	{
		if (obj->procedural == WAVES)
			quadric_normal_pertu(obj->q, point, obj->tx_pertu, normal);
		if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, normal);
	}
	else if (obj->texture)
	{
		if (obj->type == 1)
			make_texture_sphere(obj, point, col);
		if (obj->type == 4)
			make_texture_cylinder(obj, point, col);
		if (obj->type == 2)
			make_texture_plan(obj, point);
	}
}
