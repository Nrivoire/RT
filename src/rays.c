/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 15:57:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 18:18:51 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray		create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	rot;
	t_ray			ray;

	matrix_rotation((y - v->h * .5) * v->angle_ratio,
					(x - v->w * .5) * v->angle_ratio, 0, rot);
	ray.ori = (t_vec){v->p.ori.x, v->p.ori.y, v->p.ori.z};
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
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

int		inter_ray_quadratic(t_ray r, t_quadratic q)
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

t_quadratic		make_cylindre_infini(t_point a, t_vec vec, float r)
{
	t_quadratic	res;

	res.a = (vec.y * vec.y + vec.z * vec.z) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.b = (vec.x * vec.x + vec.z * vec.z) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.c = (vec.x * vec.x + vec.y * vec.y) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.d = -(2 * vec.x * vec.y) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.e = -(2 * vec.x * vec.z) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.f = -(2 * vec.y * vec.z) / (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	res.g = 0;
	res.h = 0;
	res.i = 0;
	res.j = -r * r;
	return (res);
}

void		    		bouclette(t_env *v)
{
	int		    		x;
	int		    		y;
	t_ray	    		ray;
    // t_quadratic 		sphere;
	t_quadratic 		cylindre;
	// t_quadratic 		plan;

	v->angle_ratio = (v->fov / (float)v->w) * M_PI / 180;
	t_quadratic 		res;

	cylindre = make_cylindre_infini((t_point){v->obj.x, v->obj.y, v->obj.z}, (t_vec){1, 2, 3}, 2);
	//sphere = make_sphere((t_vec){v->obj.x, v->obj.y, v->obj.z}, 5);
	//plan = make_plan((t_point){0, 1, 0},(t_point){3, 1, 0}, (t_point){-2, 1, 3});
	res = cylindre;
	printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
	return ;
	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (inter_ray_quadratic(ray, cylindre))
				pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
		}
	}
	//printf("%f %f %f\n", v->obj.x, v->obj.y, v->obj.z);
}
