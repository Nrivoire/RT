/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:17:59 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/12 21:22:00 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float		precision(t_vec vp, t_vec ve, float phi)
{
	float	precision;

	precision = vec_scale_product(vp, ve) / sin(phi);
	if (precision <= -1)
		precision = -1.0f;
	if (precision >= 1)
		precision = 1.0f;
	return (precision);
}

t_unit		calc_u_and_v(t_vec vn, t_vec vp, t_vec ve)
{
	t_unit	res;
	float	phi;
	float	theta;

	phi = acos(vec_scale_product(vn, vp));
	theta = acos(precision(vp, ve, phi)) / (2 * M_PI);
	if (vec_scale_product(vec_cross_product(vn, ve), vp) > 0)
		res.u = theta;
	else
		res.u = 1 - theta;
	res.v = phi / M_PI;
	return (res);
}

void		make_texture_sphere(t_tab_obj *obj, t_vec point, SDL_Color col)
{
	t_vec	vp;
	t_vec	vn;
	t_vec	ve;
	t_unit	res;

	vn = (t_vec){0, 1, 0};
	ve = (t_vec){1, 0, 0};
	vp = vec_normalize(vec_sub(point, obj->pos));
	res = calc_u_and_v(vn, vp, ve);
	if (res.u >= 0 && res.v >= 0 && res.u <= 1 && res.v <= 1)
	{
		SDL_GetRGB(get_pixel(obj->texture, res.u * obj->texture->w,
				res.v * obj->texture->h), obj->texture->format,
				&col.r, &col.g, &col.b);
		obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
	}
}
