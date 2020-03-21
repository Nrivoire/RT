/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:06:26 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	plane_event_z(t_env *v, const Uint8 *keyboard_state, float scale)
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

static void	plane_event(t_env *v, const Uint8 *keyboard_state, float scale)
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

static void	obj_event_rotate(t_env *v, const Uint8 *keyboard_state)
{
	// CHANGER LES BOUTONS SUIVANT POUR LE PAVE NUMERIQUE APRES ?
	if (keyboard_state[SDL_SCANCODE_W])
		v->selected_obj->dir = rot_axe_x_r(v->selected_obj->dir, .01 * v->sc_m);
	if (keyboard_state[SDL_SCANCODE_D])
		v->selected_obj->dir = rot_axe_y_r(v->selected_obj->dir, .01 * v->sc_m);
	if (keyboard_state[SDL_SCANCODE_Q])
		v->selected_obj->dir = rot_axe_z_r(v->selected_obj->dir, .01 * v->sc_m);
	if (keyboard_state[SDL_SCANCODE_S])
		v->selected_obj->dir = rot_axe_x_l(v->selected_obj->dir, .01 * v->sc_m);
	if (keyboard_state[SDL_SCANCODE_A])
		v->selected_obj->dir = rot_axe_y_l(v->selected_obj->dir, .01 * v->sc_m);
	if (keyboard_state[SDL_SCANCODE_E])
		v->selected_obj->dir = rot_axe_z_l(v->selected_obj->dir, .01 * v->sc_m);
}

static void	obj_event(t_env *v, const Uint8 *keyboard_state, float scale)
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
		plane_event(v, keyboard_state, scale);
}

int			key_event(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (v->selected_obj)
		obj_event(v, keyboard_state, .025);
	if (keyboard_state[SDL_SCANCODE_LSHIFT])
		v->sc_m = 6;
	if (!keyboard_state[SDL_SCANCODE_LSHIFT])
		v->sc_m = 1;
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
	if (keyboard_state[SDL_SCANCODE_I])
		v->ppc.ssp = 2;
	return (0);
}
