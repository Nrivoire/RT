/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:20:49 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/11 19:30:22 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			put_icon(t_env *v)
{
	SDL_Surface		*icon;

	if (!(icon = IMG_Load("textures/icon.png")))
		ft_putstr("Error: Can't find the icon\n");
	SDL_SetWindowIcon(v->win, icon);
	SDL_FreeSurface(icon);
}

void			init_value(t_env *v)
{
	v->w = 1280;
	v->h = 720;
	v->p.sc.amb_light = (t_color){0.5, 0.5, 0.5};
	v->p.cam.pos = (t_vec){0.0, 0.0, 0.0};
	v->p.cam.dir = (t_vec){0.0, 0.0, 0.0};
	v->p.cam.fov = 60;
	v->cam.fov = v->p.cam.fov;
	v->selected_obj = NULL;
	v->p.sc.filter = 0;
	v->ppc.active_rpx = 1;
	v->ppc.ssp = 0;
	v->stats.last = clock();
	v->stats.fps = 0;
	v->p.ob = NULL;
	v->p.lg = NULL;
	v->ui.m_h = 720;
	v->ui.m_w = 500;
	v->hover[0] = get_hex_menu(218, 112, 214);
	v->hover[1] = v->hover[0];
	v->hover[2] = v->hover[0];
	v->hover[3] = v->hover[0];
}

void			scene_value(t_env *v)
{
	v->cam.fov = v->p.cam.fov;
	v->cam.ori = v->p.cam.pos;
	v->cam.dir = v->p.cam.dir;
	v->cam.angle_x = 0;
	v->cam.angle_y = 0;
	v->cam.fov_x = tan(v->cam.fov * M_PI / 180 * 0.5);
	v->cam.fov_y = -tan(v->h * v->cam.fov / v->w * M_PI / 180 * 0.5);
}
