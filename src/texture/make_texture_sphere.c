/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:17:59 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:24:46 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		calc_u(t_vec vn, t_vec ve, t_tab_obj *obj)
{
	float		phi;
	float		theta;
	float		u;
	float		v;
	float		precision;

	phi = acos(dot_product(vn, obj->normale));
	v = phi / M_PI;
	precision = dot_product(obj->normale, ve) / sin(phi);
	if (precision <= -1)
		precision = -1.0f;
	if (precision >= 1)
		precision = 1.0f;
	theta = acos(precision) / (2 * M_PI);
	if (dot_product(vec_cross_product(vn, ve), obj->normale) > 0)
		u = theta;
	else
		u = 1 - theta;
	return (u);
}

static int		calc_v(t_vec vn, t_vec ve, t_tab_obj *obj)
{
	float		v;
	float		phi;

	phi = acos(dot_product(vn, obj->normale));
	v = phi / M_PI;
    return (v);
}

void			make_texture_sphere(t_tab_obj *obj)
{
	t_vec		vn;
	t_vec		ve;
    float		u;
	float		v;
	SDL_Color	col;

    col = (SDL_Color){0, 0, 0, 255};
	vn = (t_vec){0, 1, 0};
	ve = (t_vec){1, 0, 0};
    u = calc_u(vn, ve, obj);
    v = calc_v(vn, ve, obj);
	if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
	{
		SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w, v *
			obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
		obj->color = (t_color){col.r / 255., col.g / 255., col.b / 255., 255};
	}
}
