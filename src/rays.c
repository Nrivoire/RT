/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:03:46 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/14 15:33:18 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ray	create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	cam;
	t_ray			ray;

	ray.o = v->cam.ori;
	ray.d.x = v->cam.fov_x * (2. * x / v->w - 1);
	ray.d.y = v->cam.fov_y * (2. * y / v->h - 1);
	ray.d.z = -1;
	matrix_rotation(v->cam.angle_x, v->cam.angle_y, 0, cam);
	ray.d = matrix_mult_vec(cam, ray.d);
	ray.o = matrix_mult_vec(cam, v->cam.ori);
	return (ray);
}

t_color	color_ratio(t_color color, float ratio)
{
	return ((t_color){color.r * ratio, color.g * ratio, color.b * ratio});
}

t_color	color_op(t_color c1, char op, t_color c2)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	if (op == '*')
	{
		color.r = c1.r * c2.r;
		color.g = c1.g * c2.g;
		color.b = c1.b * c2.b;
	}
	else if (op == '+')
	{
		color.r = c1.r + c2.r;
		color.g = c1.g + c2.g;
		color.b = c1.b + c2.b;
	}
	return (color);
}

t_color	limit_color(t_color color)
{
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 1)
		color.r = 1;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 1)
		color.g = 1;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 1)
		color.b = 1;
	return (color);
}

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

t_color	light_reflect(t_env *v, t_vec point, t_vec ray, t_vec normal)
{
	t_ray		prev;
	t_tab_obj	obj;
	t_color		color;

	prev = (t_ray){													\
			point, 													\
			vec_sub(ray, vec_mult_float(vec_mult_float(normal, 2), 	\
				vec_scale_product(ray, normal)))					\
			};
	select_obj(v, prev, &obj, &color);
	return (color);
}

t_color	ray_tracer(t_env *v, t_tab_obj obj, t_vec point, t_vec ray)
{
	t_vec	normal;
	t_color	light;
	int		i;
	t_color	diffuse;

	normal = quadric_normal(obj.q, point);
	if (vec_scale_product(normal, ray) > 0)
		normal = vec_mult_float(normal, -1);
	if (obj.type == CONE || (obj.type == PLAN && !obj.q.h))
		return (v->reflect-- 											\
				? limit_color(light_reflect(v, point, ray, normal)) 	\
				: (t_color){0, 0, 0});
	light = v->p.sc.amb_light;
	i = -1;
	while (++i < v->nb_l)
	{
		diffuse = light_diffuse(point, &normal, v->tab_lights[i]);
		if (!light_shadow(v, point, normal, v->tab_lights[i]))
			light = color_op(light, '+', diffuse);
	}
	return (limit_color(color_op(light, '*', obj.color)));
}

void	big_pixel(t_env *v, t_int c, int size, t_color color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size && (i = -1))
		while (++i < size)
			pixel_put(v, c.x + i, c.y + j, color);
}

float	dist_closest_point(t_vec o, t_sol_2_vec s, t_vec *p)
{
	float	d1;
	float	d2;

	if (s.s1)
		d1 = vec_norm(vec_sub(s.v1, o));
	if (s.s2)
		d2 = vec_norm(vec_sub(s.v2, o));
	if (s.s1 && s.s2)
	{
		*p = d1 <= d2 ? s.v1 : s.v2;
		return (d1 <= d2 ? d1 : d2);
	}
	if (s.s1)
	{
		*p = s.v1;
		return (d1);
	}
	if (s.s2)
	{
		*p = s.v2;
		return (d2);
	}
	return (-1);
}

int		choose_closest_point(t_vec o, t_sol_2_vec s, float *dist, t_vec *point)
{
	float	d;
	t_vec	p;

	p = o;
	d = dist_closest_point(o, s, &p);
	if (*dist < 0 || d < *dist)
	{
		*dist = d;
		*point = p;
		return (1);
	}
	return (0);
}

int		select_obj(t_env *v, t_ray ray, t_tab_obj *obj, t_color *color)
{
	float		dist;
	int			i;
	t_sol_2_vec	sol;
	t_vec		point;

	dist = -1;
	ray.o = vec_add(ray.o, vec_mult_float(vec_normalize(ray.d), 0.01));
	i = -1;
	while (++i < v->nb_o)
		if (inter_ray_quadric(ray, v->tab_obj[i].q, &sol) 				\
				&& choose_closest_point(ray.o, sol, &dist, &point))
			*obj = v->tab_obj[i];
	*color = dist >= 0 ? ray_tracer(v, *obj, point, ray.d) : (t_color){0, 0, 0};
	return (dist >= 0);
}

void	loop(t_env *v)
{
	int			x;
	int			y;
	t_tab_obj	obj;
	t_color		color;

	y = -v->ppc.render_size;
	while ((y += v->ppc.render_size) <= v->h && (x = -v->ppc.render_size))
		while ((x += v->ppc.render_size) <= v->w)
		{
			v->reflect = 10;
			if (select_obj(v, create_ray(v, x, y), &obj, &color) && obj.texture)
			{
				generate_texture(&obj);
				color = limit_color(obj.color);
			}
			if (v->ppc.render_size == 1)
				pixel_put(v, x, y, color);
			else
				big_pixel(v, (t_int){x, y}, v->ppc.render_size, color);
		}
}
