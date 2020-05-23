/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/23 03:28:32 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		key_angle_z(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (keyboard_state[SDL_SCANCODE_U])
	{
		v->cam.angle_z += scale * v->sc_m;
		if (v->cam.angle_z > (360 * (M_PI / 180)))
			v->cam.angle_z = 0.000000;
	}
	if (keyboard_state[SDL_SCANCODE_O])
	{
		v->cam.angle_z -= scale * v->sc_m;
		if (v->cam.angle_z < 0.000000)
			v->cam.angle_z = (360 * (M_PI / 180));
	}
}

static void		key_angle(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (keyboard_state[SDL_SCANCODE_I])
	{
		v->cam.angle_x += scale * v->sc_m;
		if (v->cam.angle_x > (360 * (M_PI / 180)))
			v->cam.angle_x = 0.00000;
	}
	if (keyboard_state[SDL_SCANCODE_K])
	{
		v->cam.angle_x -= scale * v->sc_m;
		if (v->cam.angle_x < 0.000000)
			v->cam.angle_x = (360 * (M_PI / 180));
	}
	if (keyboard_state[SDL_SCANCODE_J])
	{
		v->cam.angle_y += scale * v->sc_m;
		if (v->cam.angle_y > (360 * (M_PI / 180)))
			v->cam.angle_y = 0.000000;
	}
	if (keyboard_state[SDL_SCANCODE_L])
	{
		v->cam.angle_y -= scale * v->sc_m;
		if (v->cam.angle_y < 0.000000)
			v->cam.angle_y = (360 * (M_PI / 180));
	}
	key_angle_z(v, keyboard_state, scale);
}

static void		key_cam(t_env *v, const Uint8 *keyboard_state, float scale)
{
	if (keyboard_state[SDL_SCANCODE_W])
		v->cam.ori.z -= scale;
	if (keyboard_state[SDL_SCANCODE_S])
		v->cam.ori.z += scale;
	if (keyboard_state[SDL_SCANCODE_A])
		v->cam.ori.x -= scale;
	if (keyboard_state[SDL_SCANCODE_D])
		v->cam.ori.x += scale;
	if (keyboard_state[SDL_SCANCODE_E])
		v->cam.ori.y += scale;
	if (keyboard_state[SDL_SCANCODE_Q])
		v->cam.ori.y -= scale;
}

void			key_post_process(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_F] && cooldown(v, 5))
	{
		v->p.sc.filter++;
		if (v->p.sc.filter == 6)
			v->p.sc.filter = 0;
	}
	if (keyboard_state[SDL_SCANCODE_C])
		v->ppc.ssp = 0;
	if (keyboard_state[SDL_SCANCODE_V])
		v->ppc.ssp = 1;
	if (keyboard_state[SDL_SCANCODE_B])
		v->ppc.ssp = 2;
}

int				key_event(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
		return (1);
	if (v->selected_obj && keyboard_state[SDL_SCANCODE_SPACE])
		obj_event(v, keyboard_state, 1);
	if (keyboard_state[SDL_SCANCODE_LSHIFT]
			|| keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 1;
	else if (!keyboard_state[SDL_SCANCODE_LSHIFT]
			&& !keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 0.1;
	if (keyboard_state[SDL_SCANCODE_P] && cooldown(v, 5))
		screenshot(v, 1);
	if (keyboard_state[SDL_SCANCODE_R])
		v->ppc.active_rpx = 1;
	if (keyboard_state[SDL_SCANCODE_T])
		v->ppc.active_rpx = 0;
	key_post_process(v, keyboard_state);
	if (!keyboard_state[SDL_SCANCODE_SPACE])
	{
		render_obj(v, keyboard_state);
		key_angle(v, keyboard_state, 0.03);
		key_cam(v, keyboard_state, 1.0);
	}
	return (0);
}
