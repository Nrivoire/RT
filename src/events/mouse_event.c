/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_event.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:58:38 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/02 19:33:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		mouse_motion_event(SDL_Event event, t_env *v, uint32_t mouse_state)
{
	if (mouse_state == 1)
	{
		v->render_mouse = 1;
		if (abs(event.motion.xrel) > abs(event.motion.yrel))
			v->cam.angle_y -= (event.motion.xrel * 0.1) * (M_PI / 180);
		else
			v->cam.angle_x -= (event.motion.yrel * 0.1) * (M_PI / 180);
		SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	if (mouse_state == 4)
	{
		v->render_mouse = 1;
		if (event.motion.xrel > 0 || event.motion.xrel < 0)
			v->cam.ori.x -= event.motion.xrel * 0.02;
		if (event.motion.yrel > 0 || event.motion.yrel < 0)
			v->cam.ori.y += event.motion.yrel * 0.02;
	}
	if (mouse_state == 0)
	{
		v->render_mouse = 0;
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
}

void		mouse_button_event(SDL_Event e, t_env *v)
{
	t_tab_obj	tmp;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (closest_intersect(v, create_ray(v, e.button.x, e.button.y), &tmp))
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
	}
}

void		mouse_wheel_event(SDL_Event e, t_env *v)
{
	if (v->selected_obj)
	{
		
		if (e.wheel.y > 0)
		{
			v->render_mouse = 1;
			v->selected_obj->pos.z += e.wheel.y * 0.2;
		}
		if (e.wheel.y < 0)
		{
			v->render_mouse = 1;
			v->selected_obj->pos.z += e.wheel.y * 0.2;
		}
		if (e.wheel.y == 0)
		 	v->render_mouse = 0;
	}
}
