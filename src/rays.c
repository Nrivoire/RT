/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 15:57:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 19:59:26 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray		create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	rot;
	t_ray			ray;

	matrix_rotation((x - v->w * .5) * v->angle_ratio * M_PI / 180,
					(y - v->h * .5) * v->angle_ratio * M_PI / 180, 0, rot);
	ray.ori = (t_vec){0, 0, 0};
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	return (ray);
}

t_quadratic		make_sphere(t_vec center, float radius)
{
	t_quadratic	res;

	res.a = 1;
	res.b = 1;
	res.c = 1;
	res.d = 0;
	res.e = 0;
	res.f = 0;
	res.g = -2 * center.x;
	res.h = -2 * center.y;
	res.i = -2 * center.z;
	res.j = center.x * center.x + center.y * center.y + center.z * center.z
			- radius * radius;
	return (res);
}

int		sys_solve_1equ_1var_deg2(t_equ_1var_deg2 e, t_sys_sol_1var_deg2 *s)
{
	float	delta;
	float	tmp;
	float	sqrt_delta;
	int		result;
	t_sys_sol_1var_deg1	sol;

	if (!e.a && !e.b)
		return (0);
	if (!e.a)
	{
		result = sys_solve_1equ_1var_deg1(e.b, e.c, &sol);
		if (!result)
			return (0);
		s->x1 = sol.x;
		return (1);
	}
	delta = ft_sq(e.b) - 4 * e.a * e.c;
	tmp = 1 / (2 * e.a);
	if (delta < 0)
		return (0);
	else if (!delta)
	{
		s->x1 = -e.b * tmp;
		return (1);
	}
	sqrt_delta = sqrtf(delta);
	s->x1 = (-e.b - sqrt_delta) * tmp;
	s->x2 = (-e.b + sqrt_delta) * tmp;
	return (2);
}

int		inter_line_quadratic(t_line l, t_quadratic q, t_sys_sol_1var_deg2 *result)
{
	return (sys_solve_1equ_1var_deg2((t_equ_1var_deg2)			\
			{													\
				.a = q.a * ft_sq(l.x.u) 						\
					+ q.b * ft_sq(l.y.u) 						\
					+ q.c * ft_sq(l.z.u) 						\
					+ q.d * l.x.u * l.y.u 						\
					+ q.e * l.x.u * l.z.u 						\
					+ q.f * l.y.u * l.z.u, 						\
				.b = q.a * 2 * l.x.o * l.x.u 					\
					+ q.b * 2 * l.y.o * l.y.u 					\
					+ q.c * 2 * l.z.o * l.z.u 					\
					+ q.d * (l.x.o * l.y.u + l.x.u * l.y.o) 	\
					+ q.e * (l.x.o * l.z.u + l.x.u * l.z.o) 	\
					+ q.f * (l.y.o * l.z.u + l.y.u * l.z.o) 	\
					+ q.g * l.x.u + q.h * l.y.u + q.i * l.z.u, 	\
				.c = q.a * ft_sq(l.x.o) 						\
					+ q.b * ft_sq(l.y.o) 						\
					+ q.c * ft_sq(l.z.o) 						\
					+ q.d * l.x.o * l.y.o 						\
					+ q.e * l.x.o * l.z.o 						\
					+ q.f * l.y.o * l.z.o 						\
					+ q.g * l.x.o + q.h * l.y.o + q.i * l.z.o 	\
					+ q.j										\
			}, 													\
			result));
}

void		    		bouclette(t_env *v)
{
	int		    		x;
	int		    		y;
	t_ray	    		ray;
    t_quadratic 		sphere;
	//t_quadratic 		res;
	t_sys_sol_1var_deg2	res;

	v->angle_ratio = (float)v->fov / (float)v->w;
	//res = make_sphere((t_vec){25, 5, 0}, 5);
	//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
    //return ;
	sphere = make_sphere((t_vec){0, 5, 30}, 5);
    y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
            if (inter_line_quadratic(line_create_point_vec(ray.ori, ray.dir), sphere, &res))
			{
				pixel_put(v, x, y, (t_rgb){255, 255, 255, 255});
			}
		}
	}
}
