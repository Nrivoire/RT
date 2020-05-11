/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/11 14:50:56 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void			make_texture_cylinder(t_tab_obj obj)
// {
// 	t_real		rx;
// 	t_real		ry;
// 	t_real		rz;
// 	t_vec		dir_norm;

// 	dir_norm = vec_normalize(obj->dir);
// 	rx = (t_real){dir_norm.y, dir_norm.z};
// 	ry = (t_real){dir_norm.x, dir_norm.z};
// 	rz = (t_real){dir_norm.x, dir_norm.y};
// 	t_vec point = (t_vec){0,1,0};
// 	float ax = real_oriented_angle((t_real){point.y, point.z}, rx);
// 	float ay = real_oriented_angle((t_real){point.x, point.z}, ry);
// 	float az = real_oriented_angle((t_real){point.x, point.y}, rz);
// 	t_matrix_3_3 rot;
// 	matrix_rotation(ax, ay, az, rot);
// }

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural)
	{
		if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, normal);
	}
	else
	{
		if (obj->type == SPHERE)
			make_texture_sphere(obj, point, col);
		// if (obj->type == CYLINDER)
			// make_texture_cylinder(obj);
		if (obj->type == PLAN)
			make_texture_plan(obj, point);
	}
}
