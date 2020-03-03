/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   closest_intersect.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/02 19:31:41 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/03 11:47:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

float			closest_dist(t_vec ori, t_sol_2_vec sol)
{
	float		tmp;
	float		dist_s1;
	float		dist_s2;

	dist_s1 = 0;
	dist_s2 = 0;
	if (sol.s1 && sol.s2)
	{
		dist_s1 = vec_norm(vec_sub(ori, sol.v1));
		dist_s2 = vec_norm(vec_sub(ori, sol.v2));
		tmp = fmin(dist_s1, dist_s2);
		return (tmp);
	}
	if (sol.s1 == 1 && sol.s2 == 0)
	{
		dist_s1 = vec_norm(vec_sub(ori, sol.v1));
		return (dist_s1);
	}
	if (sol.s2 == 1 && sol.s1 == 0)
	{
		dist_s2 = vec_norm(vec_sub(ori, sol.v2));
		return (dist_s2);
	}
	return (-1);
}

t_vec			closest_point(t_vec ori, t_sol_2_vec sol)
{
	float		dist_s1;
	float		dist_s2;

	dist_s1 = 0;
	dist_s2 = 0;
	if (sol.s1 && sol.s2)
	{
		dist_s1 = vec_norm(vec_sub(ori, sol.v1));
		dist_s2 = vec_norm(vec_sub(ori, sol.v2));
		if (dist_s1 < dist_s2)
			return (sol.v1);
		else
			return (sol.v2);
	}
	if (sol.s1 == 1 && sol.s2 == 0)
		return (sol.v1);
	return (sol.v2);
}

t_vec				quadric_normal(t_quadric q, t_vec p, t_vec r)
{
	t_vec			n;

	n = vec_normalize((t_vec){								\
			2 * q.a * p.x + q.d * p.y + q.e * p.z + q.g, 	\
			2 * q.b * p.y + q.d * p.x + q.f * p.z + q.h, 	\
			2 * q.c * p.z + q.e * p.x + q.f * p.y + q.i});
	return (vec_scale_product(n, r) > 0 ? vec_mult_float(n, -1) : n);
}

t_tab_obj		make_closest(t_tab_obj p, t_vec point, float dist, int i)
{
	t_tab_obj	closest;

	closest.type = p.type;
	closest.radius = p.radius;
	closest.pos = p.pos;
	closest.dir = p.dir;
	closest.a = p.a;
	closest.b = p.b;
	closest.c = p.c;
	closest.color = p.color;
	closest.reflect = p.reflect;
	closest.refract = p.refract;
	closest.transparency = p.transparency;
	closest.absorbtion = p.absorbtion;
	closest.ambient = p.ambient;
	closest.diffuse = p.diffuse;
	closest.specular = p.specular;
	closest.shininess = p.shininess;
	closest.texture = p.texture;
	closest.point = point;
	closest.dist = dist;
	closest.i = i;
	closest.q = p.q;
	return (closest);
}

int				closest_intersect(t_env *v, t_ray ray, t_tab_obj *closest)
{
	float		dist;
	float		tmp;
	t_sol_2_vec	sol;
	int			i;
	int			state;

	state = 0;
	i = -1;
	dist = INFINITY;
	tmp = -1;
	while (++i < v->nb_o)
		if (inter_ray_quadric(ray, v->tab_obj[i].q, &sol))
		{
			tmp = closest_dist(ray.o, sol);
			if (tmp >= 0 && tmp < dist)
			{
				dist = tmp;
				*closest = make_closest(v->tab_obj[i],
                        closest_point(ray.o, sol), dist, i);
				closest->normale = quadric_normal(closest->q, closest->point, ray.d);
				state = 1;
			}
		}
	return (state);
}
