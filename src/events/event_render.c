/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/13 09:12:27 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	render_obj(t_env *v, const Uint8 *keyboard_state)
{
	if (!keyboard_state[SDL_SCANCODE_J]
		&& !keyboard_state[SDL_SCANCODE_L]
		&& !keyboard_state[SDL_SCANCODE_K]
		&& !keyboard_state[SDL_SCANCODE_I]
		&& !keyboard_state[SDL_SCANCODE_U]
		&& !keyboard_state[SDL_SCANCODE_O]
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
	if (!keyboard_state[SDL_SCANCODE_J]
		&& !keyboard_state[SDL_SCANCODE_L]
		&& !keyboard_state[SDL_SCANCODE_K]
		&& !keyboard_state[SDL_SCANCODE_I]
		&& !keyboard_state[SDL_SCANCODE_U]
		&& !keyboard_state[SDL_SCANCODE_O]
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
