/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 19:20:05 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/18 14:29:51 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static float	dist_closest_point(t_vec o, t_sol_2_vec s, t_vec *p)
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

static int		choose_closest_point(t_vec o, t_sol_2_vec s,
		float *dist, t_vec *point)
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

int				select_obj(t_env *v, t_ray ray, t_tab_obj *obj, t_color *light)
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
		{
			v->tab_obj[i].i = i;
			*obj = v->tab_obj[i];
		}
	*light = dist >= 0 ? ray_tracer(v, obj, point, ray.d) : (t_color){0, 0, 0};
	return (dist >= 0);
}
