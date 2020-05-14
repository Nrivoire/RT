/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/14 13:40:21 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		plane_event_z(t_env *v, const Uint8 *keyboard, float scale)
{
	if (keyboard[SDL_SCANCODE_Q])
	{
		v->selected_obj->a.z -= scale * v->sc_m;
		v->selected_obj->b.z -= scale * v->sc_m;
		v->selected_obj->c.z -= scale * v->sc_m;
	}
	if (keyboard[SDL_SCANCODE_E])
	{
		v->selected_obj->a.z += scale * v->sc_m;
		v->selected_obj->b.z += scale * v->sc_m;
		v->selected_obj->c.z += scale * v->sc_m;
	}
}

void			plane_event_t(t_env *v, const Uint8 *keyboard, float scale)
{
	if (keyboard[SDL_SCANCODE_D])
	{
		v->selected_obj->a.x += scale * v->sc_m;
		v->selected_obj->b.x += scale * v->sc_m;
		v->selected_obj->c.x += scale * v->sc_m;
	}
	if (keyboard[SDL_SCANCODE_A])
	{
		v->selected_obj->a.x -= scale * v->sc_m;
		v->selected_obj->b.x -= scale * v->sc_m;
		v->selected_obj->c.x -= scale * v->sc_m;
	}
	plane_event_z(v, keyboard, scale);
	render_obj(v, keyboard);
}

void			plane_event(t_env *v, const Uint8 *keyboard, float scale)
{
	if (keyboard[SDL_SCANCODE_W])
	{
		v->selected_obj->a.y += scale * v->sc_m;
		v->selected_obj->b.y += scale * v->sc_m;
		v->selected_obj->c.y += scale * v->sc_m;
	}
	if (keyboard[SDL_SCANCODE_S])
	{
		v->selected_obj->a.y -= scale * v->sc_m;
		v->selected_obj->b.y -= scale * v->sc_m;
		v->selected_obj->c.y -= scale * v->sc_m;
	}
	plane_event_t(v, keyboard, scale);
}

static void		plane_rotate_2(t_env *v, const Uint8 *keyboard, float angle)
{
	if (keyboard[SDL_SCANCODE_K])
	{
		v->selected_obj->a = rot_axe_x(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_x(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_x(v->selected_obj->c, angle, 'L');
	}
	if (keyboard[SDL_SCANCODE_J])
	{
		v->selected_obj->a = rot_axe_y(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_y(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_y(v->selected_obj->c, angle, 'L');
	}
	if (keyboard[SDL_SCANCODE_U])
	{
		v->selected_obj->a = rot_axe_z(v->selected_obj->a, angle, 'L');
		v->selected_obj->b = rot_axe_z(v->selected_obj->b, angle, 'L');
		v->selected_obj->c = rot_axe_z(v->selected_obj->c, angle, 'L');
	}
}

void			plane_rotate(t_env *v, const Uint8 *keyboard)
{
	float	angle;

	angle = .01 * v->sc_m;
	if (keyboard[SDL_SCANCODE_I])
	{
		v->selected_obj->a = rot_axe_x(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_x(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_x(v->selected_obj->c, angle, 'R');
	}
	if (keyboard[SDL_SCANCODE_L])
	{
		v->selected_obj->a = rot_axe_y(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_y(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_y(v->selected_obj->c, angle, 'R');
	}
	if (keyboard[SDL_SCANCODE_O])
	{
		v->selected_obj->a = rot_axe_z(v->selected_obj->a, angle, 'R');
		v->selected_obj->b = rot_axe_z(v->selected_obj->b, angle, 'R');
		v->selected_obj->c = rot_axe_z(v->selected_obj->c, angle, 'R');
	}
	plane_rotate_2(v, keyboard, angle);
}
