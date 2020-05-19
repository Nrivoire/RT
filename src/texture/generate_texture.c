/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/19 19:21:46 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			make_texture_cylinder(t_tab_obj *obj, t_vec pt, SDL_Color col)
{
	float		u;
	float		v;
	t_vec		proj;
	t_plane		plane;
	float		dist;
	t_vec		pproj;
	t_vec		ve;
	t_vec		u_vec;
	t_vec		v_vec;

	plane = (t_plane){obj->dir.x, obj->dir.y, obj->dir.z, obj->dir.x * obj->pos.x - obj->dir.y * obj->pos.y - obj->dir.z * obj->pos.z};
	proj = proj_point_plane(pt, plane, &dist);
	pproj = vec_normalize(vec_sub(proj, obj->pos));
	ve = (t_vec){1, 0, 0};
	u_vec = vec_normalize(vec_cross_product(ve, obj->dir));
	u = acos(vec_scale_product(u_vec, pproj)) / (2 * M_PI);
	v_vec = vec_normalize(vec_sub(proj, pt));
	v = vec_norm(v_vec);
	v = v - (int)v;
	if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
	{
		SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w,
		 			v * obj->texture->h), obj->texture->format,
		 			&col.r, &col.g, &col.b);
		obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
	}
}

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec *normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural)
	{
		if (obj->procedural == WAVES)
			quadric_normal_pertu(obj->q, point, obj->waves, normal);
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
