/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:12:17 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/09 14:34:44 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			make_tab_obj(t_env *v)
{
	int			i;

	i = -1;
	while (++i < v->nb_o)
	{
		if (v->tab_obj[i].type == SPHERE)
			v->tab_obj[i].q = make_sphere(v->tab_obj[i].pos,
					v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == PLAN)
			v->tab_obj[i].q = make_plan(v->tab_obj[i].a, v->tab_obj[i].b,
					v->tab_obj[i].c);
		else if (v->tab_obj[i].type == CONE)
			v->tab_obj[i].q = make_cone(v->tab_obj[i].pos, v->tab_obj[i].dir,
					v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == CYLINDER)
			v->tab_obj[i].q = make_cylinder(v->tab_obj[i].pos,
					v->tab_obj[i].dir, v->tab_obj[i].radius);
	}
}
