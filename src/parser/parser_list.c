/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:54:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/21 18:54:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	add_lst_obj(t_object **ob, t_object content)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
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
	new->transparency = content.transparency;
	new->absorbtion = content.absorbtion;
	new->ambient = content.ambient;
	new->diffuse = content.diffuse;
	new->specular = content.specular;
	new->shininess = content.shininess;
	new->texture = content.texture;
	new->next = (!*ob) ? NULL : *ob;
	*ob = new;
}

void	add_lst_lgt(t_light **lg, t_light content)
{
	t_light		*new;

	if (!(new = malloc(sizeof(t_light))))
		return ;
	new->type = content.type;
	new->pos = content.pos;
	new->dir = content.dir;
	new->color = content.color;
	new->intensity = content.intensity;
	new->next = (!*lg) ? NULL : *lg;
	*lg = new;
}
