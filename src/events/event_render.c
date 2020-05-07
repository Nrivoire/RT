/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/07 14:28:02 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	render_obj(t_env *v, const Uint8 *keyboard_state)
{
	if (!keyboard_state[SDL_SCANCODE_LEFT]
		&& !keyboard_state[SDL_SCANCODE_RIGHT]
		&& !keyboard_state[SDL_SCANCODE_DOWN]
		&& !keyboard_state[SDL_SCANCODE_UP]
		&& !keyboard_state[SDL_SCANCODE_KP_PLUS]
		&& !keyboard_state[SDL_SCANCODE_KP_MINUS]
		&& !keyboard_state[SDL_SCANCODE_W]
		&& !keyboard_state[SDL_SCANCODE_D]
		&& !keyboard_state[SDL_SCANCODE_Q]
		&& !keyboard_state[SDL_SCANCODE_S]
		&& !keyboard_state[SDL_SCANCODE_A]
		&& !keyboard_state[SDL_SCANCODE_E])
		v->ppc.render_key = 0;
	else
		v->ppc.render_key = 1;
}

void	render_plane(t_env *v, const Uint8 *keyboard_state)
{
	if (!keyboard_state[SDL_SCANCODE_LEFT]
		&& !keyboard_state[SDL_SCANCODE_RIGHT]
		&& !keyboard_state[SDL_SCANCODE_DOWN]
		&& !keyboard_state[SDL_SCANCODE_UP]
		&& !keyboard_state[SDL_SCANCODE_KP_PLUS]
		&& !keyboard_state[SDL_SCANCODE_KP_MINUS]
		&& !keyboard_state[SDL_SCANCODE_W]
		&& !keyboard_state[SDL_SCANCODE_D]
		&& !keyboard_state[SDL_SCANCODE_Q]
		&& !keyboard_state[SDL_SCANCODE_S]
		&& !keyboard_state[SDL_SCANCODE_A]
		&& !keyboard_state[SDL_SCANCODE_E])
		v->ppc.render_key = 0;
	else
		v->ppc.render_key = 1;
}
