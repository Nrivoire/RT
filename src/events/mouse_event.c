/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:58:38 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/25 10:36:11 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	mouv_cam_with_mouse(SDL_Event e, t_env *v)
{
	v->ppc.render_mouse = 1;
	if (abs(e.motion.xrel) > abs(e.motion.yrel))
	{
		v->cam.angle_y -= (e.motion.xrel * 0.01);
		if (v->cam.angle_y > (360 * (M_PI / 180)))
			v->cam.angle_y = 0.00000;
		else if (v->cam.angle_y < 0.000000)
			v->cam.angle_y = (360 * (M_PI / 180));
	}
	else
	{
		v->cam.angle_x -= (e.motion.yrel * 0.01);
		if (v->cam.angle_x > (360 * (M_PI / 180)))
			v->cam.angle_x = 0.00000;
		else if (v->cam.angle_x < 0.000000)
			v->cam.angle_x = (360 * (M_PI / 180));
	}
	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetWindowGrab(v->win, SDL_TRUE);
}

void		mouse_motion_event(SDL_Event e, t_env *v, uint32_t mouse)
{
	if (mouse == 1)
		mouv_cam_with_mouse(e, v);
	else if (mouse == 4)
	{
		v->ppc.render_mouse = 1;
		if (e.motion.xrel > 0 || e.motion.xrel < 0)
			v->cam.ori.x -= e.motion.xrel * 0.02;
		if (e.motion.yrel > 0 || e.motion.yrel < 0)
			v->cam.ori.y += e.motion.yrel * 0.02;
	}
	else if (mouse == 0)
	{
		v->ppc.render_mouse = 0;
		SDL_SetWindowGrab(v->win, SDL_FALSE);
		SDL_ShowCursor(SDL_ENABLE);
	}
}

void		button_left(SDL_Event e, t_env *v)
{
	t_tab_obj	tmp;
	t_color		light;
	int			i;

	if (SDL_GetMouseFocus() == v->win)
	{
		if (v->add_new_obj > 0)
			add_new_obj(v, e);
		else if (select_obj(v, create_ray(v, e.button.x, e.button.y),
				&tmp, &light))
		{
			if (v->selected_obj && v->selected_obj->i == tmp.i)
				v->selected_obj = NULL;
			else
			{
				v->selected_obj = &v->tab_obj[tmp.i];
				v->selected_obj->i = tmp.i;
			}
		}
		else
			v->selected_obj = NULL;
	}
	else if (SDL_GetMouseFocus() == v->ui.m_win)
		if ((i = is_it_a_button(e)) > 0)
			v->add_new_obj = i;
}

void		mouse_button_event(SDL_Event e, t_env *v)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
			button_left(e, v);
		if (e.button.button == SDL_BUTTON_RIGHT && cooldown(v, 5))
			screenshot(v, 1);
	}
}

void		mouse_wheel_event(SDL_Event e, t_env *v)
{
	if (e.wheel.y != 0)
	{
		if (v->selected_obj)
		{
			if (v->selected_obj->type != 2 && v->selected_obj->type != 0)
			{
				v->ppc.render_mouse = 1;
				v->selected_obj->radius -= e.wheel.y * 0.01;
				if (v->selected_obj->radius < 0.1)
					v->selected_obj->radius = 0.11;
				else if (v->selected_obj->radius > 10000.01)
					v->selected_obj->radius = 10000;
			}
		}
	}
	else
		v->ppc.render_mouse = 0;
}
