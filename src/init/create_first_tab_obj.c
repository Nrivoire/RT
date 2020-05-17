/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_tab_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:43:53 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/17 18:09:29 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			check_plan(int i, t_env *v)
{
	t_vec			ab;
	t_vec			ac;
	t_vec			cross;

	ab = vec_sub(v->tab_obj[i].b, v->tab_obj[i].a);
	ac = vec_sub(v->tab_obj[i].c, v->tab_obj[i].a);
	cross = vec_cross_product(ab, ac);
	if (vec_scale_product(ab, ac) != 0)
	{
		cross = vec_cross_product(cross, ab);
		v->tab_obj[i].c = vec_sub(cross, v->tab_obj[i].a);
	}
}

static t_tab_obj	make_obj(t_lst_obj *p)
{
	t_tab_obj		data;

	data.type = p->type;
	data.radius = p->radius;
	data.pos = p->pos;
	data.dir = p->dir;
	data.a = p->a;
	data.b = p->b;
	data.c = p->c;
	data.color = p->color;
	data.reflect = p->reflect;
	data.refract = p->refract;
	data.shininess = p->shininess;
	data.procedural = p->procedural;
	data.texture = p->texture;
	return (data);
}

void				create_first_tab_obj(t_env *v)
{
	int				i;
	t_lst_obj		*tmp;

	i = 0;
	tmp = v->p.ob;
	if (!(v->tab_obj = (t_tab_obj *)malloc(sizeof(t_tab_obj) * v->nb_o)))
		return ;
	if (!(v->tab_lights = (t_tab_lights *)malloc(sizeof(t_tab_lights)
			* v->nb_l)))
		return ;
	while (tmp)
	{
		if (tmp->type == 2)
			check_plan(i, v);
		v->tab_obj[i] = make_obj(tmp);
		i++;
		tmp = tmp->next;
	}
}
