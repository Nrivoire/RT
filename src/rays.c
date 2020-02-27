/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 14:24:17 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				create_ray_cam(t_env *v, int x, int y)
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

// t_color			light_dot(t_env *v, t_sol_2_vec sol, t_color obj_color)
// {
// 	float		dist_s1;
// 	float		dist_s2;
// 	float		dist;
// 	t_color		light;

// 	dist_s1 = vec_norm(vec_sub(v->light_ori, sol.v1));
// 	dist_s2 = vec_norm(vec_sub(v->light_ori, sol.v2));
// 	dist = fmin(dist_s1, dist_s2);
// 	if (dist < 0)
// 		dist = 0;
// 	if (dist > v->intens)
// 		dist = v->intens;
// 	light.r = obj_color.r - (dist / v->intens * obj_color.r);
// 	light.g = obj_color.g - (dist / v->intens * obj_color.g);
// 	light.b = obj_color.b - (dist / v->intens * obj_color.b);
// 	return (light);
// }

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

float			diffuse_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float		dot;
	t_vec		norm;
	t_vec		light;

	norm = vec_normalize(vec_sub(px.pos, px.point));
	light = vec_normalize(vec_sub(px.point, pos_light));
	dot = vec_scale_product(light, norm);
	return (dot);
}

t_tab_obj		make_closest(t_env *v, t_tab_obj p, t_vec point, float dist)
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
	return (closest);
}

int					closest_intersect(t_env *v, t_ray ray, t_tab_obj *closest)
{
	float			dist;
	float			tmp;
	t_sol_2_vec		sol;
	int				i;
	int				state;

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
				*closest = make_closest(v, v->tab_obj[i], closest_point(ray.o, sol), dist);
				state = 1;
			}
		}
	return (state);
}

void		    bouclette(t_env *v)
{
	int		    x;
	int		    y;
	t_ray	    ray;
	t_light		*tmp;
	float		dot_diffuse_light;
	t_color		ambient_color;
	t_color		px_color;
	t_tab_obj	closest;

	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray_cam(v, x, y);
				if (closest_intersect(v, ray, &closest))
				{
					ambient_color = (t_color) {.2, .2, .2, 255};
					px_color = (t_color) {0, 0, 0, 255};
					dot_diffuse_light = 0;
					float intensity = 0;
					tmp = v->p.lg;
					while (tmp)
					{
						if ((dot_diffuse_light = diffuse_light(v, closest, tmp->pos)) > 0)
						{
							intensity = dot_diffuse_light * tmp->intensity;
							px_color.r += (tmp->color.r * intensity);
							px_color.g += (tmp->color.g * intensity);
							px_color.b += (tmp->color.b * intensity);
						}
						tmp = tmp->next;
					}
					px_color.r = (ambient_color.r + px_color.r) * closest.color.r;
					px_color.g = (ambient_color.g + px_color.g) * closest.color.g;
					px_color.b = (ambient_color.b + px_color.b) * closest.color.b;
					pixel_put(v, x, y, px_color);
				}
		}
	}
}
