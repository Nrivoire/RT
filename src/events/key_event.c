/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 18:05:31 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 19:00:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			key_event(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (v->selected_obj)
	{
		if (keyboard_state[SDL_SCANCODE_UP])
		{
			v->ppc.render_key = 1;
			v->selected_obj->pos.y += .5;
		}
		if (keyboard_state[SDL_SCANCODE_DOWN])
		{
			v->ppc.render_key = 1;
			v->selected_obj->pos.y -= .5;
		}
		if (keyboard_state[SDL_SCANCODE_RIGHT])
		{
			v->ppc.render_key = 1;
			v->selected_obj->pos.x += .5;
		}
		if (keyboard_state[SDL_SCANCODE_LEFT])
		{
			v->ppc.render_key = 1;
			v->selected_obj->pos.x -= .5;
		}
		if (!keyboard_state[SDL_SCANCODE_LEFT] && !keyboard_state[SDL_SCANCODE_RIGHT] && !keyboard_state[SDL_SCANCODE_DOWN] && !keyboard_state[SDL_SCANCODE_UP])
			v->ppc.render_key = 0;
	}
	if (keyboard_state[SDL_SCANCODE_KP_MINUS])
		v->cam.ori.z--;
	if (keyboard_state[SDL_SCANCODE_KP_PLUS])
		v->cam.ori.z++;
	if (keyboard_state[SDL_SCANCODE_P])
		screenshot(v);
	if (keyboard_state[SDL_SCANCODE_C])
		v->p.sc.filter = 0;
	if (keyboard_state[SDL_SCANCODE_V])
		v->p.sc.filter = 1;
	if (keyboard_state[SDL_SCANCODE_B])
		v->p.sc.filter = 2;
	if (keyboard_state[SDL_SCANCODE_N])
		v->p.sc.filter = 3;
	if (keyboard_state[SDL_SCANCODE_M])
		v->p.sc.filter = 4;
	if (keyboard_state[SDL_SCANCODE_R])
		v->ppc.active_rpx = 1;
	if (keyboard_state[SDL_SCANCODE_T])
		v->ppc.active_rpx = 0;
	if (keyboard_state[SDL_SCANCODE_Y])
		v->ppc.ssp = 0;
	if (keyboard_state[SDL_SCANCODE_U])
		v->ppc.ssp = 1;
	return (0);
}
