/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:47:32 by qpupier           #+#    #+#             */
/*   Updated: 2020/05/06 17:52:05 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

int		select_obj(t_env *v, t_ray ray, t_tab_obj *obj, t_color *light)
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
	*light = dist >= 0 ? ray_tracer(v, obj, point, ray.d) : (t_color){0, 0, 0};
	return (dist >= 0);
}

void	loop(t_env *v)
{
	int			x;
	int			y;
	t_tab_obj	obj;
	t_color		color;
	t_color		light;

	y = -v->ppc.render_size;
	while ((y += v->ppc.render_size) <= v->h && (x = -v->ppc.render_size))
		while ((x += v->ppc.render_size) <= v->w)
		{
			color = (t_color){0, 0, 0};
			v->reflect = 1;
			if (select_obj(v, create_ray(v, x, y), &obj, &light))
				color = limit_color(light);
			if (v->ppc.render_size == 1)
				pixel_put(v, x, y, color);
			else
				big_pixel(v, (t_int){x, y}, v->ppc.render_size, color);
		}
}
