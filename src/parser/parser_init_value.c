/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:23:30 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/28 16:27:33 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	init_value_obj(t_lst_obj *content)
{
	content->type = 0;
	content->radius = 0.0;
	content->pos = (t_vec){0.0, 0.0, 0.0};
	content->dir = (t_vec){0.0, 0.0, 0.0};
	content->a = (t_vec){0.0, 0.0, 0.0};
	content->b = (t_vec){0.0, 0.0, 0.0};
	content->c = (t_vec){0.0, 0.0, 0.0};
	content->color = (t_color){255.0, 255.0, 255.0, 255};
	content->reflect = 0.0;
	content->refract = 0.0;
	content->transparency = 0.0;
	content->absorbtion = 0.0;
	content->ambient = 0.0;
	content->diffuse = 0.0;
	content->specular = 0.0;
	content->shininess = 0.0;
	content->texture = NULL;
}

void	init_value_light(t_lst_lgt *content)
{
	content->type = 0;
	content->pos = (t_vec){0.0, 0.0, 0.0};
	content->dir = (t_vec){0.0, 0.0, 0.0};
	content->color = (t_color){0.0, 0.0, 0.0, 255};
	content->intensity = 0.0;
}
