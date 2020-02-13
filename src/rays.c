/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 15:57:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 18:22:45 by vasalome    ###    #+. /#+    ###.fr     */
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
	ray.ori = (t_vec){0, 0, 50};
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	return (ray);
}

t_quadratic		make_plan(t_vec v, float d)
{
	t_quadratic	res;
	
	res.a = 0;
	res.b = 0;
	res.c = 0;
	res.d = 0;
	res.e = 0;
	res.f = 0;
	res.g = v.x;
	res.h = v.y;
	res.i = v.z;
	res.j = d;
	return (res);
}

// t_quadratic		make_cyl(t_vec p1, t_vec p2, float radius)
// {
// 	t_quadratic	res;
// 	float		sc_p1_n;
// 	t_vec   n;

	
// 	n = vec_normalize(vec_sub(p2, p1));
// 	sc_p1_n = vec_scale_product(p1, n);

// 	res.a = 1 - ft_sq(n.x);
// 	res.b = 1 - ft_sq(n.y);
// 	res.c = 1 - ft_sq(n.z);
// 	res.d = -2 * n.x * n.y;
// 	res.e = -2 * n.x * n.z;
// 	res.f = -2 * n.y * n.z;
// 	res.g = n.x * (2 * sc_p1_n - 1) - 2 * p1.x;
// 	res.h = n.y * (2 * sc_p1_n - 1) - 2 * p1.y;
// 	res.i = n.z * (2 * sc_p1_n - 1) - 2 * p1.z;
// 	res.j = -ft_sq(sc_p1_n) - ft_sq(radius) + vec_scale_product(p1, p1);

// 	printf("%.15f * x^2 + %.15f * y^2 + %.15f * z^2 + %.15f * x * y + %.15f * x * z + %.15f * y * z + %.15f * x + %.15f * y + %.15f * z + %.15f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);


// 	return (res);
// }

t_quadratic		make_cyl(t_vec p1, t_vec p2, float radius)
{
	t_quadratic	res;
	float		sc_p1_n;
	t_vec   n;

	
	n = vec_normalize(vec_sub(p2, p1));
	sc_p1_n = vec_scale_product(p1, n);

	res.a = 1;
	res.b = 1;
	res.c = 1;
	res.d = -1;
	res.e = -1;
	res.f = -1;
	res.g = 0;
	res.h = 0;
	res.i = 0;
	res.j = -25;

	//printf("%.15f * x^2 + %.15f * y^2 + %.15f * z^2 + %.15f * x * y + %.15f * x * z + %.15f * y * z + %.15f * x + %.15f * y + %.15f * z + %.15f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);


	return (res);
}

// void					print_ray(t_ray ray)
// {
// 	printf("DemiDroite((%f, %f, %f), Vecteur((%f, %f, %f)))\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
// }

void		    		bouclette(t_env *v)
{
	int		    		x;
	int		    		y;
	t_ray	    		ray;
    t_quadratic 		sphere;
	t_quadratic 		plan;
	t_quadratic 		cyl;
	t_sys_sol_1var_deg2	res_equ;

	v->angle_ratio = (v->fov / (float)v->w) * M_PI / 180;
	//t_quadratic 		res;
	//res = make_sphere((t_vec){25, 5, 0}, 5);
	//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
    //return ;
	
	// ray = create_ray(v, 0, 0);
	// print_ray(ray);
	// ray = create_ray(v, v->w, 0);
	// print_ray(ray);
	// ray = create_ray(v, v->w, v->h);
	// print_ray(ray);
	// ray = create_ray(v, 0, v->h);
	// print_ray(ray);
	// exit (1);

	//sphere = make_sphere((t_vec){v->obj_x, v->obj_y, v->obj_z}, 5);
	//plan = make_plan((t_vec){2, 0, 0}, -5);
	cyl = make_cyl((t_vec){v->obj_x, v->obj_y, v->obj_z}, (t_vec){8, 0, 0}, 2);
    y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
            // if (inter_line_quadratic(line_create_point_vec(ray.ori, ray.dir), sphere, &res_equ))
			// 	pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
			// if (inter_line_quadratic(line_create_point_vec(ray.ori, ray.dir), plan, &res_equ))
			// 	pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
			if (inter_line_quadratic(line_create_point_vec(ray.ori, ray.dir), cyl, &res_equ))
				pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
		}
	}
}
