/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:05:31 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/23 17:18:18 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	goodnight_obj(t_env *v)
{
	v->selected_obj->radius = 0;
	v->selected_obj->pos = (t_vec){15000, 15000, 15000};
	v->selected_obj->dir = (t_vec){0, 0, 1};
	v->selected_obj->a = (t_vec){15000, 15000, 15000};
	v->selected_obj->b = (t_vec){15000, 15000, 15000};
	v->selected_obj->c = (t_vec){15000, 15000, 15000};
	v->selected_obj->color = (t_color){0, 0, 0};
	v->selected_obj->reflect = 0.0;
	v->selected_obj->refract = 0.0;
	v->selected_obj->rho = 0.0;
	v->selected_obj->shininess = 0.0;
	v->selected_obj->procedural = 0;
	v->selected_obj->texture = NULL;
	v->selected_obj->q = (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	v->selected_obj = NULL;
}

static void	event_texture(t_env *v, const Uint8 *keyboard_state)
{
	if (keyboard_state[SDL_SCANCODE_UP])
	{
		v->selected_obj->tex += 0.1;
		if (v->selected_obj->tex > 3.01)
			v->selected_obj->tex = 3.0;
	}
	if (keyboard_state[SDL_SCANCODE_DOWN])
	{
		v->selected_obj->tex -= 0.1;
		if (v->selected_obj->tex < 0.99999)
			v->selected_obj->tex = 1.0;
	}
}

static void			dir_tex_cylinder(t_tab_obj *obj)
{
	t_vec			cross;

	obj->ve = vec_normalize(vec_cross_product((t_vec){1, 0, 0}, obj->dir));
	if (vec_scale_product(obj->ve, obj->dir) != 0)
	{
		cross = vec_normalize(vec_cross_product(obj->ve, obj->dir));
		cross = vec_cross_product(cross, obj->ve);
		obj->ve = vec_sub(cross, obj->dir);
	}
	obj->vn = vec_normalize(vec_cross_product(obj->dir, obj->ve));
	obj->plan_cylinder_for_tex = (t_plane){obj->dir.x, obj->dir.y,
			obj->dir.z, -obj->dir.x * obj->pos.x - obj->dir.y *
			obj->pos.y - obj->dir.z * obj->pos.z};
}

static void	obj_event_rotate(t_env *v, const Uint8 *keyboard_state)
{
	float	angle;

	angle = .01 * v->sc_m;
	if (keyboard_state[SDL_SCANCODE_I])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_L])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_U])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'R');
	if (keyboard_state[SDL_SCANCODE_K])
		v->selected_obj->dir = rot_axe_x(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_J])
		v->selected_obj->dir = rot_axe_y(v->selected_obj->dir, angle, 'L');
	if (keyboard_state[SDL_SCANCODE_O])
		v->selected_obj->dir = rot_axe_z(v->selected_obj->dir, angle, 'L');
	if (v->selected_obj->type == 4 && v->selected_obj->texture)
		dir_tex_cylinder(v->selected_obj);
}

void		obj_event(t_env *v, const Uint8 *keyboard, float scale)
{
	if (v->selected_obj->type != 2)
	{
		if (keyboard[SDL_SCANCODE_W])
			v->selected_obj->pos.y += scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_S])
			v->selected_obj->pos.y -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_D])
			v->selected_obj->pos.x += scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_A])
			v->selected_obj->pos.x -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_Q])
			v->selected_obj->pos.z -= scale * v->sc_m;
		if (keyboard[SDL_SCANCODE_E])
			v->selected_obj->pos.z += scale * v->sc_m;
		obj_event_rotate(v, keyboard);
		render_obj(v, keyboard);
	}
	else
	{
		plane_event(v, keyboard, scale);
		plane_rotate(v, keyboard);
	}
	if (keyboard[SDL_SCANCODE_G] && keyboard[SDL_SCANCODE_N])
		goodnight_obj(v);
	event_texture(v, keyboard);
}
