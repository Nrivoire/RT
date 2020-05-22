/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:46:45 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/22 15:55:47 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	light_shadow(t_env *v, t_vec point, t_vec normal, t_tab_lights light)
{
	t_seg		seg;
	float		shadow;
	int			i;
	t_sol_2_vec	sol;

	seg = (t_seg){light.pos, vec_add(point, vec_mult_float(normal, 0.01))};
	shadow = 0;
	i = -1;
	while (++i < v->nb_o)
		if (inter_seg_quadric(seg, v->tab_obj[i].q, &sol))
			shadow += 1 - v->tab_obj[i].refract;
	return (shadow);
}

t_color	light_diffuse(t_vec point, t_vec *normal, t_tab_lights light)
{
	t_vec		ray;
	float		sp_ratio;

	ray = vec_normalize(vec_sub(point, light.pos));
	if ((sp_ratio = vec_scale_product(*normal, ray)) > 0)
		*normal = vec_mult_float(*normal, -1);
	else
		sp_ratio = -sp_ratio;
	return (color_ratio(light.color, sp_ratio));
}

t_color	light_reflection(t_env *v, t_vec point, t_rt rt, t_vec normal)
{
	t_tab_obj	obj;
	t_color		light;

	rt.o = point;
	rt.ray = vec_sub(rt.ray, vec_mult_float(vec_mult_float(normal, 2), 	\
			vec_scale_product(rt.ray, normal)));
	return (select_obj(v, rt, &obj, &light) ? light : (t_color){0, 0, 0});
}

t_color	light_shine(t_vec point, t_rt rt, t_vec normal, t_tab_lights light)
{
	t_vec	ori;
	t_vec	reflected;
	float	ratio;
	float	shine;

	ori = vec_normalize(vec_sub(point, light.pos));
	reflected = vec_sub(ori, vec_mult_float(vec_mult_float(normal, 2), 	\
			vec_scale_product(ori, normal)));
	ratio = vec_scale_product(reflected, vec_normalize(rt.ray));
	shine = 0.05;
	return (ratio < shine - 1 											\
			? color_ratio(light.color, 1 - (ratio + 1) / shine) 		\
			: (t_color){0, 0, 0});
}

t_color	light_refraction(t_env *v, t_rt rt, t_vec normal, float n)
{
	float		r;
	float		sp;
	float		radicand;
	t_tab_obj	obj;
	t_color		light;

	if (rt.n == 1)
		r = 1 / n;
	else
	{
		r = n;
		rt.n = n;
	}
	sp = vec_scale_product(normal, rt.ray);
	radicand = 1 - r * r * (1 - sp * sp);
	if (radicand < 0)
		return (light_reflection(v, rt.o, rt, normal));
	rt.ray = vec_sub(vec_mult_float(rt.ray, r), 	\
			vec_mult_float(normal, r * sp + sqrtf(radicand)));
	return (select_obj(v, rt, &obj, &light) ? light : (t_color){0, 0, 0});
}
