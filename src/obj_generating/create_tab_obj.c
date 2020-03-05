/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tab_obj.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/24 18:12:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 12:23:38 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

void			create_tab_obj(t_env *v)
{
	int			i;
	//t_quadric	res;

	i = -1;
	while (++i < v->nb_o)
	{
		if (v->tab_obj[i].type == SPHERE)
			v->tab_obj[i].q = make_sphere(v->tab_obj[i].pos, v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == PLAN)
			v->tab_obj[i].q = make_plan(v->tab_obj[i].a, v->tab_obj[i].b, v->tab_obj[i].c);
		else if (v->tab_obj[i].type == CONE)
			v->tab_obj[i].q = make_cone(v->tab_obj[i].pos, v->tab_obj[i].dir, v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == CYLINDER)
			v->tab_obj[i].q = make_cylinder(v->tab_obj[i].pos, v->tab_obj[i].dir, v->tab_obj[i].radius);
		//res = v->tab_obj[i].q;
		//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
		//exit(0);
	}
}
