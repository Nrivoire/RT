/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:58:38 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/17 14:05:38 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		add_new_obj(t_env *v, t_tab_obj new_obj)
{
	int			i;
	t_tab_obj	*old_tab;

	if (!(old_tab = (t_tab_obj *)malloc(sizeof(t_tab_obj) * v->nb_o)))
		ft_error("malloc error in add_new_obj");
	i = -1;
	while (++i < v->nb_o)
		old_tab[i] = v->tab_obj[i];
	free(v->tab_obj);
	if (!(v->tab_obj = (t_tab_obj *)malloc(sizeof(t_tab_obj) * (v->nb_o + 1))))
		ft_error("malloc error in add_new_obj");
	i = -1;
	while (++i < v->nb_o)
		v->tab_obj[i] = old_tab[i];
	v->tab_obj[i] = new_obj;
	v->nb_o = v->nb_o + 1;
	free(old_tab);
}

void		create_new_obj(t_env *v, float x, float y, float z)
{
	if (v->add_new_obj == SPHERE)
		add_new_obj(v, (t_tab_obj){v->nb_o + 1, SPHERE, 2, (t_vec){x, y, z},
			(t_vec){0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0},
			(t_vec){0, 0, 0}, (t_color){205 / 255.0, 35 / 255.0, 35 / 255.0},
			0, 0, 0, 0, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0}});
	else if (v->add_new_obj == CYLINDER)
		add_new_obj(v, (t_tab_obj){v->nb_o + 1, CYLINDER, 2,
			(t_vec){x, y, z}, (t_vec){0, 1, 0}, (t_vec){0, 0, 0},
			(t_vec){0, 0, 0}, (t_vec){0, 0, 0},
			(t_color){35 / 255.0, 205 / 255.0, 35 / 255.0},
			0, 0, 0, 0, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0}});
	else if (v->add_new_obj == CONE)
		add_new_obj(v, (t_tab_obj){v->nb_o + 1, CONE, 0.3, (t_vec){x, y, z},
			(t_vec){0, 1, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0},
			(t_vec){0, 0, 0}, (t_color){35 / 255.0, 35 / 255.0, 205 / 255.0},
			0, 0, 0, 0, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0}});
	else if (v->add_new_obj == PLAN)
		add_new_obj(v, (t_tab_obj){v->nb_o + 1, PLAN, 0, (t_vec){x, y, z},
			(t_vec){0, 0, 0}, (t_vec){15, -8, 30}, (t_vec){-15, -8, 30},
			(t_vec){15, -8, -10}, (t_color){30 / 255.0, 30 / 255.0, 30 / 255.0},
			0, 0, 0, 0, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0}});
	v->add_new_obj = 0;
}

void		mouse_motion_event(SDL_Event e, t_env *v, uint32_t mouse)
{
	if (mouse == 1)
	{
		//v->ppc.render_mouse = 1;
		// if (abs(e.motion.xrel) > abs(e.motion.yrel))
		// 	v->cam.angle_y -= (e.motion.xrel * 0.1) * (M_PI / 180);
		// else
		// 	v->cam.angle_x -= (e.motion.yrel * 0.1) * (M_PI / 180);
		// SDL_SetRelativeMouseMode(SDL_TRUE);
	}
	if (mouse == 4)
	{
		v->ppc.render_mouse = 1;
		if (e.motion.xrel > 0 || e.motion.xrel < 0)
			v->cam.ori.x -= e.motion.xrel * 0.02;
		if (e.motion.yrel > 0 || e.motion.yrel < 0)
			v->cam.ori.y += e.motion.yrel * 0.02;
	}
	if (mouse == 0)
	{
		v->ppc.render_mouse = 0;
		SDL_SetRelativeMouseMode(SDL_FALSE);
	}
}

void		button_left(SDL_Event e, t_env *v)
{
	t_tab_obj	tmp;
	t_color		light;
	int			i;

	if (SDL_GetMouseFocus() == v->win)
	{
		if (v->add_new_obj > 0)
		{
			t_matrix_3_3	cam;
			t_ray			ray;
			matrix_rotation(v->cam.angle_x, v->cam.angle_y, v->cam.angle_z, cam);
			ray.d = matrix_mult_vec(cam, (t_vec){v->cam.fov_x * (2. * e.button.x / v->w - 1), v->cam.fov_y * (2. * e.button.y / v->h - 1), -1});
			create_new_obj(v, v->cam.ori.x + ray.d.x * 20, v->cam.ori.y + ray.d.y * 20, v->cam.ori.z + ray.d.z * 20);
		}
		else if (select_obj(v, create_ray(v, e.button.x, e.button.y),
				&tmp, &light))
		{
			if (v->selected_obj && v->selected_obj->i == tmp.i)
				v->selected_obj = NULL;
			else
			{
				v->selected_obj = &v->tab_obj[tmp.i];
				v->selected_obj->i = tmp.i;
			}
		}
		else
			v->selected_obj = NULL;
	}
	else if (SDL_GetMouseFocus() == v->ui.m_win)
		if ((i = is_it_a_button(e)) > 0)
			v->add_new_obj = i;
}

void		mouse_button_event(SDL_Event e, t_env *v)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
			button_left(e, v);
		if (e.button.button == SDL_BUTTON_RIGHT && cooldown(v, 5))
			screenshot(v, 1);
	}
}

void		mouse_wheel_event(SDL_Event e, t_env *v)
{
	if (e.wheel.y != 0)
	{
		if (v->selected_obj->type != PLAN)
		{
			v->ppc.render_mouse = 1;
			v->selected_obj->radius -= e.wheel.y * 0.01;
			if (v->selected_obj->radius < 0.1)
				v->selected_obj->radius = 0.11;
			else if (v->selected_obj->radius > 10000.01)
				v->selected_obj->radius = 10000;
		}
	}
	else
		v->ppc.render_mouse = 0;
}
