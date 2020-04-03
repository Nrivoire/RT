/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:03:46 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/02 14:22:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float				diffuse_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float			dot;
	t_vec			light;

	light = vec_normalize(vec_sub(pos_light, px.point));
	dot = vec_scale_product(light, px.normale);
	return (dot);
	(void)v;
}

float				spot_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float			spot;
	t_vec			light;

	light = vec_normalize(pos_light);
	spot = vec_scale_product(light, px.normale);
	return (spot);
	(void)v;
}

float				dir_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float			spot;
	t_vec			light;

	light = vec_normalize(pos_light);
	spot = vec_scale_product(light, px.normale);
	return (spot);
	(void)v;
}

static void			calc_condition(t_lst_lgt *tmp, float light, t_color *px_color)
{
	float	intensity;

	intensity = light * tmp->intensity;
	px_color->r += tmp->color.r * intensity;
	px_color->g += tmp->color.g * intensity;
	px_color->b += tmp->color.b * intensity;
}

void				calc_light(t_env *v, t_tab_obj closest, t_color *px_color)
{
	t_lst_lgt		*tmp;
	float			light;

	light = 0;
	tmp = v->p.lg;
	while (tmp)
	{
		if (v->p.lg->type == POINT)
			if ((light = diffuse_light(v, closest, tmp->pos)) > 0)
				calc_condition(tmp, light, px_color);
		if (v->p.lg->type == SPOT)
			if ((light = spot_light(v, closest, tmp->pos)) > 0)
				calc_condition(tmp, light, px_color);
		if (v->p.lg->type == DIRECTIONAL)
			if ((light = dir_light(v, closest, tmp->pos)) > 0)
				calc_condition(tmp, light, px_color);
		tmp = tmp->next;
	}
	px_color->r = (px_color->r + v->p.sc.amb_light.r) * closest.color.r;
	px_color->g = (px_color->g + v->p.sc.amb_light.g) * closest.color.g;
	px_color->b = (px_color->b + v->p.sc.amb_light.b) * closest.color.b;
	if (v->selected_obj && v->selected_obj->i == closest.i)
	{
		px_color->r *= 2;
		px_color->g *= 1.5;
		px_color->b *= 2.5;
	}
}
