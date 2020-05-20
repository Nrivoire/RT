/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture_cylinder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/20 13:34:16 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			make_texture_cylinder(t_tab_obj *obj, t_vec pt, SDL_Color col)
{
	t_vec	proj;
	float	v;
	t_vec	vec;
	float	u;

	proj = proj_point_plane(pt, obj->plan_cylinder_for_tex, &v);
	vec = vec_normalize(vec_sub(proj, obj->pos));
	u = acos(vec_scale_product(obj->ve, vec)) / (2 * M_PI);
	if (vec_scale_product(vec, obj->vn) > 0)
		u = 1 - u;
	v /= 2 * M_PI * obj->radius;
	v = v - (int)v;
	if (vec_scale_product(obj->dir, vec_sub(pt, proj)) < 0)
		v = 1 - v;
	SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w, v *
			obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
	obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
}
