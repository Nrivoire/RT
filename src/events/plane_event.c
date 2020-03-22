/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:06:26 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		plane_event_z(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (keyboard_state[SDL_SCANCODE_KP_MINUS])
	{
		v->selected_obj->a.z -= scale * v->sc_m;
		v->selected_obj->b.z -= scale * v->sc_m;
		v->selected_obj->c.z -= scale * v->sc_m;
	}
	if (keyboard_state[SDL_SCANCODE_KP_PLUS])
	{
		v->selected_obj->a.z += scale * v->sc_m;
		v->selected_obj->b.z += scale * v->sc_m;
		v->selected_obj->c.z += scale * v->sc_m;
	}
}

void			plane_event(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (keyboard_state[SDL_SCANCODE_UP])
	{
		v->selected_obj->a.y += scale * v->sc_m;
		v->selected_obj->b.y += scale * v->sc_m;
		v->selected_obj->c.y += scale * v->sc_m;
	}
	if (keyboard_state[SDL_SCANCODE_DOWN])
	{
		v->selected_obj->a.y -= scale * v->sc_m;
		v->selected_obj->b.y -= scale * v->sc_m;
		v->selected_obj->c.y -= scale * v->sc_m;
	}
	if (keyboard_state[SDL_SCANCODE_RIGHT])
	{
		v->selected_obj->a.x += scale * v->sc_m;
		v->selected_obj->b.x += scale * v->sc_m;
		v->selected_obj->c.x += scale * v->sc_m;
	}
	if (keyboard_state[SDL_SCANCODE_LEFT])
	{
		v->selected_obj->a.x -= scale * v->sc_m;
		v->selected_obj->b.x -= scale * v->sc_m;
		v->selected_obj->c.x -= scale * v->sc_m;
	}
	plane_event_z(v, keyboard_state, scale);
	render_plane(v, keyboard_state);
}

static void		plane_rotate_2(t_env *v, const Uint8 *keyboard_state, float angle)
{
	// CHANGER LES BOUTONS SUIVANT POUR LE PAVE NUMERIQUE APRES ?
	if (keyboard_state[SDL_SCANCODE_S]) {
		v->selected_obj->a = rot_axe_x(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_x(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_x(v->selected_obj->c, angle, 'L');
	}
	if (keyboard_state[SDL_SCANCODE_A]) {
		v->selected_obj->a = rot_axe_y(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_y(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_y(v->selected_obj->c, angle, 'L');
	}
	if (keyboard_state[SDL_SCANCODE_E]) {
		v->selected_obj->a = rot_axe_z(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_z(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_z(v->selected_obj->c, angle, 'L');
	}
}

void			plane_rotate(t_env *v, const Uint8 *keyboard_state)
{
	float	angle;

	angle = .01 * v->sc_m;
	// CHANGER LES BOUTONS SUIVANT POUR LE PAVE NUMERIQUE APRES ?
	if (keyboard_state[SDL_SCANCODE_W]) {
		v->selected_obj->a = rot_axe_x(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_x(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_x(v->selected_obj->c, angle, 'R');
	}
	if (keyboard_state[SDL_SCANCODE_D]) {
		v->selected_obj->a = rot_axe_y(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_y(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_y(v->selected_obj->c, angle, 'R');
	}
	if (keyboard_state[SDL_SCANCODE_Q]) {
		v->selected_obj->a = rot_axe_z(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_z(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_z(v->selected_obj->c, angle, 'R');
	}
	plane_rotate_2(v, keyboard_state, angle);
}
