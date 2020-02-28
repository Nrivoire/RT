/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:20:49 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/28 17:20:52 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			init_value(t_env *v)
{
	v->w = 1280;
	v->h = 720;
	v->p.sc.amb_light = (t_color){0.5, 0.5, 0.5, 255};
	v->p.cam.pos = (t_vec){0.0, 0.0, 0.0};
	v->p.cam.dir = (t_vec){0.0, 0.0, 0.0};
	v->p.cam.fov = 60;
	v->cam.fov = v->p.cam.fov;
	v->selected_obj = NULL;
	v->p.ob = NULL;
	v->p.lg = NULL;
}

void			scene_value(t_env *v)
{
	v->cam.fov = v->p.cam.fov;
	v->cam.ori = v->p.cam.pos;
	v->cam.dir = v->p.cam.dir;
}

void			restart_values(t_env *v)
{
	init_value(v);
	scene_value(v);
}
