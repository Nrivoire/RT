/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_obj.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 14:17:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/21 16:05:21 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_quadric		make_sphere(t_vec center, float radius)
{
	t_quadric	res;

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

int				is_it_colieaires(t_vec v1, t_vec v2)
{
	int			i;
	int			j;
	int			k;

	i = v1.x / v2.x;
	j = v1.y / v2.y;
	k = v1.z / v2.z;
	if (i == j && j == k && k == i)
		return (1);
	return (0);
}

t_quadric		make_plan(t_vec a, t_vec b, t_vec c)
{
	t_quadric	res;
	t_vec		ab;
	t_vec		ac;
	t_vec		cross;

	ab = (t_vec){b.x - a.x, b.y - a.y, b.z - a.z};
	ac = (t_vec){c.x - a.x, c.y - a.y, c.z - a.z};
	if (is_it_colieaires(ab, ac))
		ft_putendl("Les vecteurs sont colineaires, le plan ne s'affichera pas");
	cross = vec_cross_product(ab, ac);
	res.a = 0;
	res.b = 0;
	res.c = 0;
	res.d = 0;
	res.e = 0;
	res.f = 0;
	res.g = cross.x;
	res.h = cross.y;
	res.i = cross.z;
	res.j = -cross.x * a.x - cross.y * a.y - cross.z * a.z;
	return (res);
}

t_quadric		make_cylinder(t_vec a, t_vec v, float r)
{
	t_quadric	res;

	res.a = v.y * v.y + v.z * v.z;
	res.b = v.x * v.x + v.z * v.z;
	res.c = v.y * v.y + v.x * v.x;
	res.d = -2 * v.x * v.y;
	res.e = -2 * v.x * v.z;
	res.f = -2 * v.y * v.z;
	res.g = 2 * (v.z * (v.x * a.z - v.z * a.x) + v.y * (v.x * a.y - v.y * a.x));
	res.h = 2 * (v.x * (v.y * a.x - v.x * a.y) + v.z * (v.y * a.z - v.z * a.y));
	res.i = 2 * (v.x * (v.z * a.z - v.x * a.z) + v.y * (v.z * a.y - v.y * a.z));
	res.j = v.z * v.z * a.y * a.y + v.z * v.z * a.x * a.x +
			v.x * v.x * a.z * a.z + v.x * v.x * a.y * a.y +
			v.y * v.y * a.z * a.z + v.y * v.y * a.x * a.x - 2 * (
			v.y * v.z * a.y * a.z +
			v.x * v.z * a.x * a.z +
			v.x * v.y * a.x * a.y) - r * r;
	return (res);
}

static void	make_cone_quadratic(t_quadric *q, t_vec a, t_vec v, float sin_2)
{
	float	vx_2;
	float	vy_2;
	float	vz_2;

	vx_2 = v.x * v.x;
	vy_2 = v.y * v.y;
	vz_2 = v.z * v.z;
	q->a = vy_2 + vz_2 - sin_2;
	q->b = vx_2 + vz_2 - sin_2;
	q->c = vx_2 + vy_2 - sin_2;
	q->d = -2 * v.x * v.y;
	q->e = -2 * v.x * v.z;
	q->f = -2 * v.y * v.z;
}

static void	make_cone_surface(t_quadric *q, t_vec a, t_vec v, float sin_2)
{
	float	vx_2;
	float	vy_2;
	float	vz_2;

	vx_2 = v.x * v.x;
	vy_2 = v.y * v.y;
	vz_2 = v.z * v.z;
	q->g = 2 * (v.y * (v.x * a.y - v.y * a.x) 		\
			+ v.z * (v.x * a.z - v.z * a.x) + sin_2 * a.x);
	q->h = 2 * (v.x * (v.y * a.x - v.x * a.y) 		\
			+ v.z * (v.y * a.z - v.z * a.y) + sin_2 * a.y);
	q->i = 2 * (v.x * (v.z * a.z - v.x * a.z) 		\
			+ v.y * (v.z * a.y - v.y * a.z) + sin_2 * a.z);
	q->j = a.x * a.x * (vy_2 + vz_2 - sin_2) 		\
			+ a.y * a.y * (vx_2 + vz_2 - sin_2) 	\
			+ a.z * a.z * (vx_2 + vy_2 - sin_2) 	\
			- 2 * (v.x * v.y * a.x * a.y 			\
			+ v.x * v.z * a.x * a.z 				\
			+ v.y * v.z * a.y * a.z);
}

t_quadric	make_cone(t_vec a, t_vec v, float alpha)
{
	t_quadric	q;
	float		vx_2;
	float		vy_2;
	float		vz_2;
	float		sin_2;

	vx_2 = v.x * v.x;
	vy_2 = v.y * v.y;
	vz_2 = v.z * v.z;
	sin_2 = sin(alpha) * sin(alpha);
	make_cone_quadratic(&q, a, v, sin_2);
	make_cone_surface(&q, a, v, sin_2);
	return (q);
}

t_quadric		make_cone(t_vec a, t_vec v, float angle, float h)
{
	// t_quadric	res;

 	// res.a = ;
 	// res.b = ;
 	// res.c = ;
 	// res.d = ;
 	// res.e = ;
 	// res.f = ;
 	// res.g = ;
 	// res.h = ;
 	// res.i = ;
 	// res.j = ;
	// return (res);
}
