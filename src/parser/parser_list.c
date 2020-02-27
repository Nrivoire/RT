/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_list.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/21 18:54:06 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/26 16:51:11 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../includes/rt.h"

void	add_lst_obj(t_lst_obj **ob, t_lst_obj content)
{
	t_lst_obj	*new;
	t_lst_obj	*tmp;

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
	t_light		*tmp;

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
