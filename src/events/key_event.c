/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/08 23:42:20 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		key_event_two(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_R])
		v->ppc.active_rpx = 1;
	if (keyboard_state[SDL_SCANCODE_T])
		v->ppc.active_rpx = 0;
	if (keyboard_state[SDL_SCANCODE_Y])
		v->ppc.ssp = 0;
	if (keyboard_state[SDL_SCANCODE_U])
		v->ppc.ssp = 1;
	if (keyboard_state[SDL_SCANCODE_I])
		v->ppc.ssp = 2;
}

int			key_event(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (v->selected_obj)
		obj_event(v, keyboard_state, 1);
	if (keyboard_state[SDL_SCANCODE_LSHIFT]
			|| keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 1;
	else if (!keyboard_state[SDL_SCANCODE_LSHIFT]
			&& !keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 0.1;
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
	key_event_two(v, keyboard_state);
	return (0);
}
