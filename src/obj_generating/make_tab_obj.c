/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:12:17 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 06:44:01 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			make_tab_obj(t_env *v)
{
	int			i;

	i = -1;
	while (++i < v->nb_o)
	{
		if (v->tab_obj[i].type == 1)
			v->tab_obj[i].q = make_sphere(v->tab_obj[i].pos,
					v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == 2)
			v->tab_obj[i].q = make_plan(v->tab_obj[i].a, v->tab_obj[i].b,
					v->tab_obj[i].c);
		else if (v->tab_obj[i].type == 3)
			v->tab_obj[i].q = make_cone(v->tab_obj[i].pos, v->tab_obj[i].dir,
					v->tab_obj[i].radius);
		else if (v->tab_obj[i].type == 4)
			v->tab_obj[i].q = make_cylinder(v->tab_obj[i].pos,
					v->tab_obj[i].dir, v->tab_obj[i].radius);
	}
}
