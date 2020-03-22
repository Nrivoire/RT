/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:06:26 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	obj_event_rotate(t_env *v, const Uint8 *keyboard_state)
{
	float	angle;

	angle = .01 * v->sc_m;
	// CHANGER LES BOUTONS SUIVANT POUR LE PAVE NUMERIQUE APRES ?
	if (keyboard_state[SDL_SCANCODE_W])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_D])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_Q])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_S])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_A])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_E])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'L');
}

void		obj_event(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (v->selected_obj->type != PLAN)
	{
		if (keyboard_state[SDL_SCANCODE_UP])
			v->selected_obj->pos.y += scale * v->sc_m;
		if (keyboard_state[SDL_SCANCODE_DOWN])
			v->selected_obj->pos.y -= scale * v->sc_m;
		if (keyboard_state[SDL_SCANCODE_RIGHT])
			v->selected_obj->pos.x += scale * v->sc_m;
		if (keyboard_state[SDL_SCANCODE_LEFT])
			v->selected_obj->pos.x -= scale * v->sc_m;
		if (keyboard_state[SDL_SCANCODE_KP_MINUS])
			v->selected_obj->pos.z -= scale * v->sc_m;
		if (keyboard_state[SDL_SCANCODE_KP_PLUS])
			v->selected_obj->pos.z += scale * v->sc_m;
		obj_event_rotate(v, keyboard_state);
		render_obj(v, keyboard_state);
	}
	else
	{
		plane_event(v, keyboard_state, scale);
		plane_rotate(v, keyboard_state);
	}
}
