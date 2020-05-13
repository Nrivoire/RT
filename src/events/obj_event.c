/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/13 06:46:32 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	obj_event_rotate(t_env *v, const Uint8 *keyboard_state)
{
	float	angle;

	angle = .01 * v->sc_m;
	if (keyboard_state[SDL_SCANCODE_W] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_D] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_Q] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_S] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_A] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_E] && keyboard_state[SDL_SCANCODE_SPACE])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'L');
}

void		obj_event(t_env *v, const Uint8 *keyboard, float scale)
{
	if (v->selected_obj->type != PLAN)
	{
		if (keyboard[SDL_SCANCODE_I] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.y += scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_K] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.y -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_L] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.x += scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_J] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.x -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_U] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.z -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_O] && keyboard[SDL_SCANCODE_SPACE])
			v->selected_obj->pos.z += scale * v->sc_m;
		obj_event_rotate(v, keyboard);
		render_obj(v, keyboard);
	}
	else
	{
		plane_event(v, keyboard, scale);
		plane_rotate(v, keyboard);
	}
}
