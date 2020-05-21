/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/21 13:18:37 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Add an object or a light to the list if necessary.
*/

void	add_lst_obj(t_lst_obj **ob, t_lst_obj content)
{
	t_lst_obj	*new;

	if (!(new = malloc(sizeof(t_lst_obj))))
		return ;
	new->type = content.type;
	new->radius = content.radius;
	new->pos = content.pos;
	new->dir = content.dir;
	new->a = content.a;
	new->b = content.b;
	new->c = content.c;
	new->color = content.color;
	new->reflect = content.reflect;
	new->refract = content.refract;
	new->rho = content.rho;
	new->shininess = content.shininess;
	new->texture = content.texture;
	new->procedural = content.procedural;
	new->tx_pertu = content.tx_pertu;
	new->bump = content.bump;
	new->fix = content.fix;
	new->next = (!*ob) ? NULL : *ob;
	*ob = new;
}

void	add_lst_lgt(t_lst_lgt **lg, t_lst_lgt content)
{
	t_lst_lgt		*new;

	if (!(new = malloc(sizeof(t_lst_lgt))))
		return ;
	new->type = content.type;
	new->pos = content.pos;
	new->dir = content.dir;
	new->color = content.color;
	new->intensity = content.intensity;
	new->next = (!*lg) ? NULL : *lg;
	*lg = new;
}
