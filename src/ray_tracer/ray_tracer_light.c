/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:46:45 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/20 22:47:13 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		light_shadow(t_env *v, t_vec point, t_vec normal, t_tab_lights light)
{
	t_seg		seg;
	int			shadow;
	int			i;
	t_sol_2_vec	sol;

	seg = (t_seg){light.pos, vec_add(point, vec_mult_float(normal, 0.01))};
	shadow = 0;
	i = -1;
	while (++i < v->nb_o)
		shadow += inter_seg_quadric(seg, v->tab_obj[i].q, &sol);
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
	t_rt		prev;
	t_tab_obj	obj;
	t_color		light;

	prev = (t_rt){point, 												\
			vec_sub(rt.ray, vec_mult_float(vec_mult_float(normal, 2), 	\
			vec_scale_product(rt.ray, normal))), rt.reflect};
	select_obj(v, prev, &obj, &light);
	return (light);
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
