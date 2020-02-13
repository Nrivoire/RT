/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 18:05:31 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:12:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			key_event(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (keyboard_state[SDL_SCANCODE_UP])
		v->obj_y -= .5;
	if (keyboard_state[SDL_SCANCODE_DOWN])
		v->obj_y += .5;
	if (keyboard_state[SDL_SCANCODE_RIGHT])
		v->obj_x -= .5;
	if (keyboard_state[SDL_SCANCODE_LEFT])
		v->obj_x += .5;
	if (keyboard_state[SDL_SCANCODE_KP_MINUS])
		v->obj_z -= .5;
	if (keyboard_state[SDL_SCANCODE_KP_PLUS])
		v->obj_z += .5;
	return (0);
}
