/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_obj.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 14:17:18 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/20 14:08:47 by nrivoire    ###    #+. /#+    ###.fr     */
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

t_quadratic		make_cylindre_infini(t_vec vec, float r)
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
	res.j = -(r * r);
	return (res);
}

t_quadratic		make_cone(t_vec a, t_vec v, float angle, float h)
{
	t_quadratic	res;

 	res.a = 1 * (1 / tan(angle) * 1 / tan(angle));
 	res.b = 1;
 	res.c = -1;
 	res.d = 0;
 	res.e = 0;
 	res.f = 0;
 	res.g = -2 * a.x * (1 / tan(angle) * 1 / tan(angle));
 	res.h = -2 * a.y;
 	res.i = 2 * a.z;
 	res.j = (a.x * a.x * (1 / tan(angle) * 1 / tan(angle))) + a.y * a.y + (-a.z) * a.z;
	return (res);
}
