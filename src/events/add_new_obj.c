/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/20 19:10:41 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		recreate_tab(t_env *v, t_tab_obj new_obj)
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

static void		set_new_obj(t_env *v, float x, float y, float z)
{
	if (v->add_new_obj == 1)
		recreate_tab(v, (t_tab_obj){v->nb_o + 1, 1, 2, (t_vec){x, y, z},\
		(t_vec){0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0},\
		(t_color){205 / 255.0, 35 / 255.0, 35 / 255.0}, 0, 0, 0, 0, 0, 0,\
		(t_vec){0, 0, 0}, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
		(t_plane){0, 0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}});
	else if (v->add_new_obj == 4)
		recreate_tab(v, (t_tab_obj){v->nb_o + 1, 4, 2, (t_vec){x, y, z},\
		(t_vec){0, 1, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0},\
		(t_color){35 / 255.0, 205 / 255.0, 35 / 255.0}, 0, 0, 0, 0, 0, 0,\
		(t_vec){0, 0, 0}, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
		(t_plane){0, 0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}});
	else if (v->add_new_obj == 3)
		recreate_tab(v, (t_tab_obj){v->nb_o + 1, 3, 0.3, (t_vec){x, y, z},\
		(t_vec){0, 1, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0},\
		(t_color){35 / 255.0, 35 / 255.0, 205 / 255.0}, 0, 0, 0, 0, 0, 0,\
		(t_vec){0, 0, 0}, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0, 0, 0, 0},\
		(t_plane){0, 0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}});
	else if (v->add_new_obj == 2)
		recreate_tab(v, (t_tab_obj){v->nb_o + 1, 2, 0, (t_vec){x, y, z},\
		(t_vec){0, 0, 0}, (t_vec){15, -3, 30}, (t_vec){-15, -3, 30},\
		(t_vec){15, -3, -10}, (t_color){30 / 255.0, 30 / 255.0, 30 / 255.0}, 0,\
		0, 0, 0, 0, 0, (t_vec){0, 0, 0}, NULL, (t_quadric){0, 0, 0, 0, 0, 0, 0,\
		0, 0, 0}, (t_plane){0, 0, 0, 0}, (t_vec){0, 0, 0}, (t_vec){0, 0, 0}});
	v->add_new_obj = 0;
}

void			add_new_obj(t_env *v, SDL_Event e)
{
	t_matrix_3_3	cam;
	t_ray			ray;

	matrix_rotation(v->cam.angle_x, v->cam.angle_y, v->cam.angle_z, cam);
	ray.d = matrix_mult_vec(cam, (t_vec){v->cam.fov_x *
			(2. * e.button.x / v->w - 1), v->cam.fov_y *
			(2. * e.button.y / v->h - 1), -1});
	set_new_obj(v, v->cam.ori.x + ray.d.x * 20,
			v->cam.ori.y + ray.d.y * 20, v->cam.ori.z + ray.d.z * 20);
}
