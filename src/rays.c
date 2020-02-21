/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/21 15:57:29 by qpupier     ###    #+. /#+    ###.fr     */
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

typedef struct	s_sol_2_vec
{
	int			s1;
	int			s2;
	t_vec		v1;
	t_vec		v2;
}				t_sol_2_vec;

static int	inter_ray_quadric_create_equ(t_ray r, t_quadric q, 	\
		t_sys_sol_1var_deg2 *sol)
{
	return (sys_solve_1equ_1var_deg2((t_equ_1var_deg2)				\
			{														\
				.a = q.a * r.d.x * r.d.x 							\
					+ q.b * r.d.y * r.d.y 							\
					+ q.c * r.d.z * r.d.z 							\
					+ q.d * r.d.x * r.d.y 							\
					+ q.e * r.d.x * r.d.z 							\
					+ q.f * r.d.y * r.d.z, 							\
				.b = q.a * 2 * r.o.x * r.d.x 						\
					+ q.b * 2 * r.o.y * r.d.y 						\
					+ q.c * 2 * r.o.z * r.d.z 						\
					+ q.d * (r.o.x * r.d.y + r.d.x * r.o.y) 		\
					+ q.e * (r.o.x * r.d.z + r.d.x * r.o.z) 		\
					+ q.f * (r.o.y * r.d.z + r.d.y * r.o.z) 		\
					+ q.g * r.d.x + q.h * r.d.y + q.i * r.d.z, 		\
				.c = q.a * r.o.x * r.o.x 							\
					+ q.b * r.o.y * r.o.y 							\
					+ q.c * r.o.z * r.o.z 							\
					+ q.d * r.o.x * r.o.y 							\
					+ q.e * r.o.x * r.o.z 							\
					+ q.f * r.o.y * r.o.z 							\
					+ q.g * r.o.x + q.h * r.o.y + q.i * r.o.z 		\
					+ q.j											\
			}, 														\
			sol));
}

int		inter_ray_quadric(t_ray r, t_quadric q, t_sol_2_vec *sol)
{
	t_sys_sol_1var_deg2	res;
	int					inter;

	sol->s1 = 0;
	sol->s2 = 0;
	if (!(inter = inter_ray_quadric_create_equ(r, q, &res)))
		return (0);
	sol->s1 = res.s1;
	sol->s2 = res.s2;
	if (res.s1)
	{
		if (res.x1 < 0)
			sol->s1 = 0;
		else
			sol->v1 = vec_add(r.o, vec_mult_float(r.d, res.x1));
	}
	if (res.s2)
	{
		if (res.x2 < 0)
			sol->s2 = 0;
		else
			sol->v2 = vec_add(r.o, vec_mult_float(r.d, res.x2));
	}
	return (sol->s1 || sol->s2);
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

t_tab			*create_obj(t_env *v)
{
	t_object	*tmp;
	int			i;
	//t_quadric 		res;

	i = 0;
	tmp = v->p.ob;
	//printf("%f\n", v->p.ob->type);
	while(tmp)
	{
		if (tmp->type == SPHERE)
			v->tab[i].q = make_sphere(tmp->pos, tmp->radius);
		else if (tmp->type == PLAN)
			v->tab[i].q = make_plan(tmp->a, tmp->b, tmp->c);
		// else if (tmp->type == CONE)
		// 	v->tab[i].q = add_elem(&lst_q, make_cone());
		else if (tmp->type == CYLINDER)
			v->tab[i].q = make_cylinder(tmp->pos, tmp->dir, tmp->radius);
		tmp = tmp->next;
		i++;
		//printf("%f\n", tmp->type);
		//res = v->tab[i].q;
		//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
	}
	return (v->tab);
}

int						closer_intersect(t_env *v, t_sol_2_vec sol)
{
	float				tmp;

	if (sol.s1 != 0)
		v->dist.s1 = vec_norm(vec_sub(v->cam_ori, sol.v1));
	if (sol.s2 != 0)
		v->dist.s2 = vec_norm(vec_sub(v->cam_ori, sol.v2));
	tmp = fmin(v->dist.s1, v->dist.s2);
	v->dist.min = v->dist.min < tmp ? v->dist.min : tmp;
	if (sol.s1 && sol.s2)
		return (1);
	else if (sol.s1 || sol.s2)
		return (1);
	return (0);
}

void		    		bouclette(t_env *v)
{
	int		    		x;
	int		    		y;
	t_ray	    		ray;
	t_sol_2_vec			sol;
	t_tab				*tab;
	int					i;
	t_quadric			sphere;

	sphere = make_sphere((t_vec){0, 0, 0}, 3);
	//tab = create_obj(v);
    y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray_win(v, x, y);
			i = -1;
			//while (++i <= v->nb_o)
				if (inter_ray_quadric(ray, /*tab[i].q*/sphere, &sol))
					if (closer_intersect(v, sol))
						pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
		}
	}
	//printf("%f %f %f\n", v->obj.x, v->obj.y, v->obj.z);
}
