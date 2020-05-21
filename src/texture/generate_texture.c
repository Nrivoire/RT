/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 10:11:12 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float			texture_color_move(float x)
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
		obj->color.r = texture_color_move(obj->pos.x * obj->pos.y);
		obj->color.g = texture_color_move(obj->pos.y * obj->pos.z);
		obj->color.b = texture_color_move(obj->pos.x * obj->pos.z);
	}
	if (obj->procedural && obj->procedural != GRAD)
	{
		if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, point, normal);
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
