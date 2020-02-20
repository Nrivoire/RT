/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/20 18:55:53 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				create_ray(t_env *v, int x, int y)
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

// void					print_ray(t_ray ray)
// {
// 	printf("DemiDroite((%f, %f, %f), Vecteur((%f, %f, %f)))\n", ray.o.x, ray.o.y, ray.o.z, ray.d.x, ray.d.y, ray.d.z);
	// ray = create_ray(v, 0, 0);
	// print_ray(ray);
	// ray = create_ray(v, v->w, 0);
	// print_ray(ray);
	// ray = create_ray(v, v->w, v->h);
	// print_ray(ray);
	// ray = create_ray(v, 0, v->h);
	// print_ray(ray);
	// exit (1);
// }

typedef struct	s_sol_2_vec
{
	int		s1;
	int		s2;
	t_vec	v1;
	t_vec	v2;
}				t_sol_2_vec;

static int	inter_ray_quadratic_create_equ(t_ray r, t_quadratic q, 	\
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

int		inter_ray_quadratic(t_ray r, t_quadratic q, t_sol_2_vec *sol)
{
	t_sys_sol_1var_deg2	res;
	int					inter;

	sol->s1 = 0;
	sol->s2 = 0;
	if (!(inter = inter_ray_quadratic_create_equ(r, q, &res)))
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

void	create_obj(t_env *v)
{
	t_object *tmp;

	tmp = v->p.ob;
	while(tmp)
	{
		if (tmp->type == SPHERE)
			// printf("%f %d %d %d ma boi\n", tmp->transparency, tmp->r, tmp->g, tmp->b);
			make_sphere(tmp->pos, tmp->radius);
		// else if (tmp->type == PLAN)
		// 	make_plan();
		// else if (tmp->type == CONE)
		// 	make_cone();
		// else if (tmp->type == CYLINDER)
		// 	make_cylinder(tmp->pos, tmp->radius);
		tmp = tmp->next;
	}
}

void		    		bouclette(t_env *v)
{
	int		    		x;
	int		    		y;
	t_ray	    		ray;
	//t_quadratic 		cylindre;
	// t_quadratic 		plan;
	//t_quadratic 		cone;
	//t_quadratic 		object;
	t_quadratic 		sphere;
	t_quadratic 		sphere2;
	//t_quadratic 		res;
	t_sol_2_vec			sol;

	//create_obj(v);
	//cylindre = make_cylindre_infini((t_point){v->obj.x, v->obj.y, v->obj.z}, (t_vec){0, 1, 0}, 2);
	sphere = make_sphere((t_vec){v->obj.x, v->obj.y, v->obj.z}, 2);
	sphere2 = make_sphere((t_vec){-5, 2, 0}, 2);
	//plan = make_plan((t_point){0, 1, 0},(t_point){3, 1, 0}, (t_point){-2, 1, 3});
	//cone = make_cone((t_vec){v->obj.x, v->obj.y, v->obj.z}, (t_vec){0, 1, 0}, 45, 10);
	//res = cylindre;
	//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
	//return ;
	//res = make_sphere((t_vec){v->obj.x, v->obj.y, v->obj.z}, 0.05);
	v->angle_ratio = (v->fov / (float)v->w) * M_PI / 180;
    y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (inter_ray_quadratic(ray, sphere, &sol))
				pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
			if (inter_ray_quadratic(ray, sphere2, &sol))
				pixel_put(v, x, y, (t_rgb){0, 255, 255, 255});
		}
	}
	//printf("%f %f %f\n", v->obj.x, v->obj.y, v->obj.z);
}
