/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 19:00:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				create_ray_win(t_env *v, int x, int y)
{
	t_matrix_3_3	rot;
	t_matrix_3_3	cam;
	t_ray			ray;

	matrix_rotation((y - v->h * .5) * v->angle_ratio,
					(x - v->w * .5) * v->angle_ratio, 0, rot);
	ray.o = v->cam.ori;
	ray.d = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	matrix_rotation(v->cam.angle_x, v->cam.angle_y, 0, cam);
	ray.d = matrix_mult_vec(cam, ray.d);
	ray.o = matrix_mult_vec(cam, v->cam.ori);
	return (ray);
}

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

t_color			light_dot(t_env *v, t_sol_2_vec sol, t_color obj_color)
{
	float		dist_s1;
	float		dist_s2;
	float		dist;
	t_color		light;

	dist_s1 = vec_norm(vec_sub(v->light_ori, sol.v1));
	dist_s2 = vec_norm(vec_sub(v->light_ori, sol.v2));
	dist = fmin(dist_s1, dist_s2);
	if (dist < 0)
		dist = 0;
	if (dist > v->intens)
		dist = v->intens;
	light.r = obj_color.r - (dist / v->intens * obj_color.r);
	light.g = obj_color.g - (dist / v->intens * obj_color.g);
	light.b = obj_color.b - (dist / v->intens * obj_color.b);
	return (light);
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

t_tab			*closest_intersect(t_env *v, t_tab *tab_obj, t_ray ray)
{
	t_tab		*closest;
	float		dist_obj_1;
	float		dist_obj_2;
	t_vec		point;
	t_sol_2_vec	sol;
	int			i;

	i = -1;
	dist_obj_1 = INFINITY;
	dist_obj_2 = -1;
	closest = NULL;
	while (++i < v->nb_o)
		if (inter_ray_quadric(ray, tab_obj[i].q, &sol))
		{
			point = closest_point(ray.o, sol);
			dist_obj_2 = closest_dist(ray.o, sol);
			if (dist_obj_2 >= 0 && dist_obj_2 < dist_obj_1)
			{
				closest = &tab_obj[i];
				dist_obj_1 = dist_obj_2;
			}
		}
	return (closest);
}

void		    bouclette(t_env *v, t_tab *tab_obj)
{
	int		    x;
	int		    y;
	t_ray	    ray;
	//t_color		light_d;
	t_tab		*closest;

	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray_win(v, x, y);
			closest = closest_intersect(v, tab_obj, ray);
			if (closest)
			{
				//light_d = light_dot(v, sol, closest->color);
				pixel_put(v, x, y, (t_rgb){closest->color.r, closest->color.g, closest->color.b, 255});
			}
		}
	}
}
