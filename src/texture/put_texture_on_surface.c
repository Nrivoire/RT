/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_on_surface.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:18:10 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

float			dot_product(t_vec u, t_vec v)
{
	float		dot;
	float		magnitude;
	float		dot_product;

	dot = u.x * v.x + u.y * v.y + u.z * v.z;
	magnitude = sqrt(u.x * u.x + u.y * u.y + u.z * u.z) *
			sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	dot_product = dot / magnitude;
	return (dot_product);
}

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
	t_vec ref = matrix_mult_vec(rot, (t_vec){1,0,0});
	//printf("%f %f %f\n", ref.x, ref.y, ref.z);
}

void			make_texture_cone(t_tab_obj *obj)
{
	
}

void			generate_texture(t_tab_obj *closest)
{
	if (closest->type == SPHERE)
		make_texture_sphere(closest);
	if (closest->type == CYLINDER)
		make_texture_cylinder(&closest);
	if (closest->type == PLAN)
		make_texture_plan(closest);
	//if (closest->type == CONE)
	//	make_texture_cone(closest);
}
