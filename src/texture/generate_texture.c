/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/22 17:25:09 by qpupier          ###   ########lyon.fr   */
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
		else if (obj->type == 2)
			make_texture_plan(obj, point);
		else if (obj->type == 3)
			make_texture_cone(obj, point, col);
		else if (obj->type == 4)
			make_texture_cylinder(obj, point, col);
	}
}
