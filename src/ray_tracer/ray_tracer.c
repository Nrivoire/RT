/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:52:18 by qpupier           #+#    #+#             */
/*   Updated: 2020/05/20 20:23:33 by qpupier          ###   ########lyon.fr   */
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

t_color	ray_tracer(t_env *v, t_tab_obj *obj, t_vec point, t_rt rt)
{
	t_vec	normal;
	t_color	reflect;
	t_color	light;
	int		i;
	t_color	diffuse;
	t_color	shine;

	normal = quadric_normal(obj->q, point);
	if (obj->texture || obj->procedural)
		generate_texture(v, obj, point, &normal);
	if (vec_scale_product(normal, rt.ray) > 0)
		normal = vec_mult_float(normal, -1);
	reflect = (t_color){0, 0, 0};
	if (obj->reflect)
		reflect = rt.reflect-- 											\
				? color_ratio(light_reflection(v, point, rt, normal), 	\
					obj->reflect) 										\
				: (t_color){0, 0, 0};
	light = v->p.sc.amb_light;
	shine = (t_color){0, 0, 0};
	i = -1;
	while (++i < v->nb_l)
	{
		diffuse = light_diffuse(point, &normal, v->tab_lights[i]);
		if (!light_shadow(v, point, normal, v->tab_lights[i]))
		{
			light = color_op(light, '+', diffuse);
			shine = color_op(shine, '+', 						\
					light_shine(point, rt, normal, v->tab_lights[i]));
		}
	}
	light = color_op(color_ratio(color_op(light, '*', obj->color), 	\
			1 - obj->reflect), '+', color_ratio(shine, obj->reflect));
	return (color_op(light, '+', reflect));
}

t_rt	create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	cam;
	t_rt			ray;

	matrix_rotation(v->cam.angle_x, v->cam.angle_y, v->cam.angle_z, cam);
	ray.o = v->cam.ori;
	ray.ray = matrix_mult_vec(cam, 							\
			(t_vec){v->cam.fov_x * (2. * x / v->w - 1), 	\
			v->cam.fov_y * (2. * y / v->h - 1), -1});
	ray.reflect = REFLECTION;
	return (ray);
}
