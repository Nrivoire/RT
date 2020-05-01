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

// static int		calc_u(t_vec vn, t_vec ve, t_vec normal)
// {
// 	float		phi;
// 	float		theta;
// 	float		u;
// 	float		precision;

// 	phi = acos(vec_scale_product(vn, normal));
// 	precision = vec_scale_product(normal, ve) / sin(phi);
// 	if (precision <= -1)
// 		precision = -1.0f;
// 	if (precision >= 1)
// 		precision = 1.0f;
// 	theta = acos(precision) / (2 * M_PI);
// 	if (vec_scale_product(vec_cross_product(vn, ve), normal) > 0)
// 		u = theta;
// 	else
// 		u = 1 - theta;
// 	return (u);
// }

// static int		calc_v(t_vec vn, t_vec ve, t_vec normal)
// {
// 	float		v;
// 	float		phi;

// 	phi = acos(vec_scale_product(vn, normal));
// 	v = phi / M_PI;
// 	return (v);
// 	(void)ve;
// }

// void			make_texture_sphere(t_tab_obj obj, t_vec normal)
// {
// 	t_vec		vn;
// 	t_vec		ve;
// 	float		u;
// 	float		v;
// 	SDL_Color	col;

// 	col = (SDL_Color){0, 0, 0, 255};
// 	vn = (t_vec){0, 1, 0};
// 	ve = (t_vec){1, 0, 0};
// 	u = calc_u(vn, ve, normal);
// 	v = calc_v(vn, ve, normal);
// 	if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
// 	{
// 		SDL_GetRGB(get_pixel(obj.texture, u * obj.texture->w, v *
// 			obj.texture->h), obj.texture->format, &col.r, &col.g, &col.b);
// 		obj.color = (t_color){col.r / 255., col.g / 255., col.b / 255.};
// 		//printf("r: %f g: %f b: %f\n", obj.color.r, obj.color.g, obj.color.b);
// 	}
// }

void			make_texture_sphere(t_tab_obj *obj, t_vec point)
{
	t_vec	vp;
	t_vec	vn;
	t_vec	ve;
	float	phi;
	float	theta;
	float	u;
	float	v;
	float	precision;
	SDL_Color col = (SDL_Color){0, 0, 0, 255};

	vn = (t_vec){0, 1, 0};
	ve = (t_vec){1, 0, 0};
	vp = vec_normalize(vec_sub(point, obj->pos));
	phi = acos(vec_scale_product(vn, vp));
	v = phi / M_PI;
	precision = vec_scale_product(vp, ve) / sin(phi);
	if (precision <= -1)
		precision = -1.0f;
	if (precision >= 1)
		precision = 1.0f;
	theta = acos(precision) / (2 * M_PI);
	if (vec_scale_product(vec_cross_product(vn, ve), vp) > 0)
		u = theta;
	else
		u = 1 - theta;
	if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
	{
		SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w, v * obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
		//printf("r: %hhu g: %hhu b: %hhu\n", col.r, col.g, col.b);
		obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
		//printf("r: %f g: %f b: %f\n", obj->color.r, obj->color.g, obj->color.b);
	}
}
