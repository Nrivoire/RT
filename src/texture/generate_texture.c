/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/05/19 19:21:46 by nrivoire         ###   ########lyon.fr   */
=======
/*   Updated: 2020/05/19 20:46:13 by qpupier          ###   ########lyon.fr   */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			make_texture_cylinder(t_tab_obj *obj, t_vec pt, SDL_Color col)
{
	t_plane	plane;
	t_vec	proj;
	float	v;
	t_vec	vec;
	t_vec	fix;
	float	u;
	t_vec	fix2;

	plane = (t_plane){obj->dir.x, obj->dir.y, obj->dir.z, -obj->dir.x * obj->pos.x - obj->dir.y * obj->pos.y - obj->dir.z * obj->pos.z};//A PRECALCULER
	proj = proj_point_plane(pt, plane, &v);
	vec = vec_normalize(vec_sub(proj, obj->pos));
	fix = vec_normalize(vec_cross_product((t_vec){1, 0, 0}, obj->dir));//A PRECALCULER
	u = acos(vec_scale_product(fix, vec)) / (2 * M_PI);
	fix2 = vec_normalize(vec_cross_product(obj->dir, fix));//A PRECALCULER
	if (vec_scale_product(vec, fix2) > 0)
		u = 1 - u;
	v /= 2 * M_PI * obj->radius;
	v = v - (int)v;
	if (vec_scale_product(obj->dir, vec_sub(pt, proj)) < 0)
		v = 1 - v;
	SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w, 	\
			v * obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
	obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
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
