/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   create_tab_obj.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/24 18:12:17 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 18:13:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

void	        create_lgt(t_env *v)
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

	i = 0;
	tmp = v->p.ob;
	while(tmp)
	{
		if (tmp->type == SPHERE)
			v->tab[i].q = make_sphere(tmp->pos, tmp->radius);
		else if (tmp->type == PLAN)
			v->tab[i].q = make_plan(tmp->a, tmp->b, tmp->c);
		else if (tmp->type == CONE)
			v->tab[i].q = make_cone(tmp->pos, tmp->dir, tmp->radius);
		else if (tmp->type == CYLINDER)
			v->tab[i].q = make_cylinder(tmp->pos, tmp->dir, tmp->radius);
		v->tab[i].color = tmp->color;
		tmp = tmp->next;
		//res = v->tab[i].q;
		//printf("%fx^2 + %fy^2 + %fz^2 + %fxy + %fxz + %fyz + %fx + %fy + %fz + %f = 0\n", res.a, res.b, res.c, res.d, res.e, res.f, res.g, res.h, res.i, res.j);
		i++;
	}
	return (v->tab);
}