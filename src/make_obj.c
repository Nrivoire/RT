/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_obj.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 14:17:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/20 16:45:42 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

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

t_quadratic		make_plan(t_point a, t_point b, t_point c)
{
	t_quadratic	res;
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

t_quadratic		make_cylindre_infini(t_point a, t_vec v, float r)
{
	t_quadratic	res;

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

t_quadratic		make_cone(t_vec a, t_vec v, float angle, float h)
{
	// t_quadratic	res;

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
