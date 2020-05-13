/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/13 06:51:52 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				cooldown(t_env *v, int seconds)
{
	int		tmp;

	tmp = clock() / CLOCKS_PER_SEC;
	if (tmp - v->cooldown > seconds)
	{
		v->cooldown = clock() / CLOCKS_PER_SEC;
		return (1);
	}
	return (0);
}

static void		key_angle(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_I] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_x += 0.02;
	if (keyboard_state[SDL_SCANCODE_K] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_x -= 0.02;
	if (keyboard_state[SDL_SCANCODE_J] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_y += 0.02;
	if (keyboard_state[SDL_SCANCODE_L] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_y -= 0.02;
	if (keyboard_state[SDL_SCANCODE_O] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_z -= 0.02;
	if (keyboard_state[SDL_SCANCODE_U] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.angle_z += 0.02;
}

static void		key_cam(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_W] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.z -= 1.0;
	if (keyboard_state[SDL_SCANCODE_S] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.z += 1.0;
	if (keyboard_state[SDL_SCANCODE_A] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.x -= 1.0;
	if (keyboard_state[SDL_SCANCODE_D] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.x += 1.0;
	if (keyboard_state[SDL_SCANCODE_E] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.y += 1.0;
	if (keyboard_state[SDL_SCANCODE_Q] && !keyboard_state[SDL_SCANCODE_SPACE])
		v->cam.ori.y -= 1.0;
}

void			key_post_process(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_F] && cooldown(v, 5))
	{
		v->p.sc.filter++;
		if (v->p.sc.filter == 5)
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
	if (v->selected_obj)
		obj_event(v, keyboard_state, 1);
	if (keyboard_state[SDL_SCANCODE_LSHIFT]
			|| keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 1;
	else if (!keyboard_state[SDL_SCANCODE_LSHIFT]
			&& !keyboard_state[SDL_SCANCODE_RSHIFT])
		v->sc_m = 0.1;
	if (keyboard_state[SDL_SCANCODE_R])
		v->ppc.active_rpx = 1;
	if (keyboard_state[SDL_SCANCODE_T])
		v->ppc.active_rpx = 0;
	key_post_process(v, keyboard_state);
	key_angle(v, keyboard_state);
	key_cam(v, keyboard_state);
	return (0);
}
