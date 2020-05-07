/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_first_tab_lgt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:47:04 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:48:21 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_tab_lights		make_tab_lights(t_lst_lgt *p)
{
	t_tab_lights	light;

	light.pos = p->pos;
	light.color = p->color;
	return (light);
}

void					create_first_tab_lgt(t_env *v)
{
	t_lst_lgt	*tmp2;
	int			i;

	i = 0;
	tmp2 = v->p.lg;
	while (tmp2)
	{
		v->tab_lights[i++] = make_tab_lights(tmp2);
		tmp2 = tmp2->next;
	}
}
