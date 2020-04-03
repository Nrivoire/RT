/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_on_surface.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/02 14:13:21 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			make_texture_cylinder(t_tab_obj *obj)
{
	t_real		rx;
	t_real		ry;
	t_real		rz;
	t_vec		dir_norm;

	dir_norm = vec_normalize(obj->dir);
	rx = (t_real){dir_norm.y, dir_norm.z};
	ry = (t_real){dir_norm.x, dir_norm.z};
	rz = (t_real){dir_norm.x, dir_norm.y};
	t_vec point = (t_vec){0,1,0};
	float ax = real_oriented_angle((t_real){point.y, point.z}, rx);
	float ay = real_oriented_angle((t_real){point.x, point.z}, ry);
	float az = real_oriented_angle((t_real){point.x, point.y}, rz);
	t_matrix_3_3 rot;
	matrix_rotation(ax, ay, az, rot);
}

void			generate_texture(t_tab_obj *closest)
{
	if (closest->type == SPHERE)
		make_texture_sphere(closest);
	if (closest->type == CYLINDER)
		make_texture_cylinder(closest);
	if (closest->type == PLAN)
		make_texture_plan(closest);
}
