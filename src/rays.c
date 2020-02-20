/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/20 15:15:27 by nrivoire    ###    #+. /#+    ###.fr     */
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
	ray.ori = v->cam_ori;
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	matrix_rotation(v->cam_angle_x, v->cam_angle_y, 0, cam);
	ray.dir = matrix_mult_vec(cam, ray.dir);
	ray.ori = matrix_mult_vec(cam, v->cam_ori);
	return (ray);
}

// void					print_ray(t_ray ray)
// {
// 	printf("DemiDroite((%f, %f, %f), Vecteur((%f, %f, %f)))\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
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

float			inter_ray_quadratic(t_ray r, t_quadratic q)
{
	t_sys_sol_1var_deg2	res_equ;
	int					nb;

	//printf("(%f %f %f) | (%f %f %f)\n", r.ori.x, r.ori.y, r.ori.z, r.dir.x, r.dir.y, r.dir.z);
	nb = sys_solve_1equ_1var_deg2((t_equ_1var_deg2)				\
			{													\
				.a = q.a * r.dir.x * r.dir.x 						\
					+ q.b * r.dir.y * r.dir.y 						\
					+ q.c * r.dir.z * r.dir.z 						\
					+ q.d * r.dir.x * r.dir.y 						\
					+ q.e * r.dir.x * r.dir.z 						\
					+ q.f * r.dir.y * r.dir.z, 						\
				.b = q.a * 2 * r.ori.x * r.dir.x 					\
					+ q.b * 2 * r.ori.y * r.dir.y 					\
					+ q.c * 2 * r.ori.z * r.dir.z 					\
					+ q.d * (r.ori.x * r.dir.y + r.dir.x * r.ori.y) 	\
					+ q.e * (r.ori.x * r.dir.z + r.dir.x * r.ori.z) 	\
					+ q.f * (r.ori.y * r.dir.z + r.dir.y * r.ori.z) 	\
					+ q.g * r.dir.x + q.h * r.dir.y + q.i * r.dir.z, 	\
				.c = q.a * r.ori.x * r.ori.x 						\
					+ q.b * r.ori.y * r.ori.y 						\
					+ q.c * r.ori.z * r.ori.z 						\
					+ q.d * r.ori.x * r.ori.y 						\
					+ q.e * r.ori.x * r.ori.z 						\
					+ q.f * r.ori.y * r.ori.z 						\
					+ q.g * r.ori.x + q.h * r.ori.y + q.i * r.ori.z 	\
					+ q.j										\
			}, 													\
			&res_equ);
	// nb = inter_line_quadratic(line_create_point_vec(r.ori, r.dir), q, &res_equ);
	//if (nb)
	//	printf("nb : [%d] => %f | %f\n", nb, res_equ.x1, res_equ.x2);
	if (nb == 1)
		return (res_equ.x1 > 0);
	else if (nb == 2)
		return (res_equ.x1 > 0 || res_equ.x2 > 0);
	return (0);
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
	//t_quadratic 		res;
	t_quadratic 		sphere;
	t_quadratic 		sphere2;

	// create_obj(v);
	//cylindre = make_cylindre_infini((t_vec){v->obj.x, v->obj.y, v->obj.z}, 2);
	sphere = make_sphere((t_vec){v->obj.x, v->obj.y, v->obj.z}, 2);
	sphere2 = make_sphere((t_vec){-5, 2, 0}, 2);
	//plan = make_plan((t_point){0, 1, 0},(t_point){3, 1, 0}, (t_point){-2, 1, 3});
	//cone = make_cone((t_vec){v->obj.x, v->obj.y, v->obj.z}, (t_vec){0, 1, 0}, 45, 10);
	//res = cone;
	//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
	//return ;
	v->angle_ratio = (v->fov / (float)v->w) * M_PI / 180;
    y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (inter_ray_quadratic(ray, sphere))
				pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
			if (inter_ray_quadratic(ray, sphere2))
				pixel_put(v, x, y, (t_rgb){0, 255, 255, 255});
		}
	}
	//printf("%f %f %f\n", v->obj.x, v->obj.y, v->obj.z);
}
