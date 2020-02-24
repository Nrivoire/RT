/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 14:52:24 by qpupier     ###    #+. /#+    ###.fr     */
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
	ray.o = v->cam_ori;
	ray.d = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	matrix_rotation(v->cam_angle_x, v->cam_angle_y, 0, cam);
	ray.d = matrix_mult_vec(cam, ray.d);
	ray.o = matrix_mult_vec(cam, v->cam_ori);
	return (ray);
}

void	create_lgt(t_env *v)
{
	t_light *tmp;

	tmp = v->p.lg;
	while(tmp)
	{
		// if (tmp->type == POINT)
		//	fonction point light;
		// else if (tmp->type == SPOT)
		//	fonction spot light;
		tmp = tmp->next;
	}
}

int				closer_point_with_cam(t_env *v, t_sol_2_vec sol)
{
	float		tmp;
	float		dist_s1;
	float		dist_s2;

	dist_s1 = 0;
	dist_s2 = 0;
	if (sol.s1 != 0)
		dist_s1 = vec_norm(vec_sub(v->cam_ori, sol.v1));
	if (sol.s2 != 0)
		dist_s2 = vec_norm(vec_sub(v->cam_ori, sol.v2));
	tmp = fmin(dist_s1, dist_s2);
	if (v->dist_min == -1)
		v->dist_min = tmp;
	if (sol.s1 && sol.s2 && v->dist_min > tmp)
	{
		v->dist_min = tmp;
		return (1);
	}
	else if (sol.s1 || sol.s2)
		return (1);
	return (0);
}

t_tab			*create_obj(t_env *v)
{
	t_object	*tmp;
	int			i;

	i = 0;
	tmp = v->p.ob;
	while(tmp)
	{
		if (tmp->type == SPHERE)
			v->tab[i].q = make_sphere(tmp->pos, tmp->radius);
		else if (tmp->type == PLAN)
			v->tab[i].q = make_plan(tmp->a, tmp->b, tmp->c);
		else if (tmp->type == CONE)
			v->tab[i].q = make_cone(tmp->pos, tmp->dir, tmp->radius);
		else if (tmp->type == CYLINDER)
			v->tab[i].q = make_cylinder(tmp->pos, tmp->dir, tmp->radius);
		v->tab[i].color = tmp->color;
		tmp = tmp->next;
		//res = v->tab[i].q;
		//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
		i++;
	}
	return (v->tab);
}

void					bouclette(t_env *v)
{
	int					x;
	int					y;
	t_ray				ray;
	t_sol_2_vec			sol;
	t_tab				*tab;
	int					i;

	tab = create_obj(v);
	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray_win(v, x, y);
			i = -1;
			while (++i < v->nb_o)
				if (inter_ray_quadric(ray, tab[i].q, &sol))
					if (closer_point_with_cam(v, sol))
					{
						pixel_put(v, x, y, (t_rgb){tab[i].color.r, tab[i].color.g, tab[i].color.b, 255});
					}
		}
	}
}
