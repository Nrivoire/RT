/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:52:18 by qpupier           #+#    #+#             */
/*   Updated: 2020/05/23 10:13:27 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	ray_loop(t_env *v, t_tracer *t, t_vec point, t_rt rt)
{
	float	shadow;

	t->diffuse = light_diffuse(point, &t->normal, v->tab_lights[t->i]);
	if ((shadow = light_shadow(v, point, t->normal, v->tab_lights[t->i])) < 1)
	{
		t->light = color_op(t->light, '+', color_ratio(t->diffuse, 1 - shadow));
		t->shine = color_op(t->shine, '+', color_ratio(light_shine(point, 	\
				rt, t->normal, v->tab_lights[t->i]), 1 - shadow));
	}
}

static void	ray_init_value(t_env *v, t_tracer *t)
{
	t->refract = (t_color){0, 0, 0};
	t->reflect = (t_color){0, 0, 0};
	t->light = v->p.sc.amb_light;
	t->shine = (t_color){0, 0, 0};
	t->i = -1;
}

t_color		ray_tracer(t_env *v, t_tab_obj *obj, t_vec point, t_rt rt)
{
	t_tracer	t;

	t.normal = quadric_normal(obj->q, point);
	if (obj->texture || obj->procedural)
		generate_texture(v, obj, point, &t.normal);
	if (vec_scale_product(t.normal, rt.ray) > 0)
		t.normal = vec_mult_float(t.normal, -1);
	ray_init_value(v, &t);
	if (obj->refract && rt.refract--)
	{
		rt.o = point;
		t.refract = color_ratio(light_refraction(v, rt, t.normal, 	\
				obj->rho), obj->refract);
	}
	if (obj->reflect && rt.reflect--)
		t.reflect = color_ratio(light_reflection(v, point, rt, t.normal), 	\
				obj->reflect);
	while (++t.i < v->nb_l)
		ray_loop(v, &t, point, rt);
	t.light = color_op(color_ratio(color_op(t.light, '*', obj->color), 	\
			1 - obj->refract - obj->reflect), 							\
			'+', color_ratio(t.shine, obj->reflect));
	return (color_op(color_op(t.light, '+', t.refract), '+', t.reflect));
}

t_rt		create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	cam;
	t_rt			ray;

	matrix_rotation(v->cam.angle_x, v->cam.angle_y, v->cam.angle_z, cam);
	ray.o = v->cam.ori;
	ray.ray = vec_normalize(matrix_mult_vec(cam, 			\
			(t_vec){v->cam.fov_x * (2. * x / v->w - 1), 	\
			v->cam.fov_y * (2. * y / v->h - 1), -1}));
	ray.refract = REFRACTION;
	ray.reflect = REFLECTION;
	ray.n = 1;
	return (ray);
}
