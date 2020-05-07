/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_tab_obj.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:43:53 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:56:52 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_tab_obj	make_tab_obj(t_lst_obj *p)
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
		v->tab_obj[i] = make_tab_obj(tmp);
		i++;
		tmp = tmp->next;
	}
}
