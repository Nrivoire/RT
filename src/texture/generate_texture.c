/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/18 18:58:31 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

//  // Based off of pseudocode from Jamis Buck: http://raytracerchallenge.com/bonus/texture-mapping.html
//     // Input: point on the cylinder. The cylinder is assumed to be of radius 1, centered at the origin and parallel with the y axis.
//     // Output: (u,v) with u and v both between 0 and 1.
//     // u will vary from 0 to 1 with the azimuthal angle, counter-clockwise.
//     // v will vary from 0 to 1 with whole units of y; note that the cylinder will have to be scaled by PI in the y axis to prevent stretching
//     map_cylinder_point_to_uv(point: (x: float, y: float, z: float)) -> (float, float) {
//         // compute the azimuthal angle, -PI < theta <= PI
//     float theta = arctan2(point.x, point.z);
//         // convert from radians to units
//         // -0.5 < rawU <= 0.5
//     float rawU = theta / (2 * M_PI)
//         // convert to correct scale, and flip it so that u increases with theta counter-clockwise
//         // 0 <= u < 1
//      float u = 1 - (rawU + 0.5);

//         // v will vary from 0 to 1 between whole units of y
//         // Use whatever modulus method or operator your language has to gauarantee a positive value for v.
//         // It's different for every programming language: https://en.wikipedia.org/wiki/Modulo_operation#In_programming_languages
//         float v = point.y % 1

//         return (u, v)
//     }
	// float		theta;
	// float		rawU;
	// float		u;
	// float		v;

	// theta = atan2(point.x, point.z);
	// rawU = theta / (2 * M_PI);
	// u = 1 - (rawU + 0.5);
	// v = point.y % 1;
	// printf("%f %f\n", u, v);
	// if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
	// {
	// 	SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w,
	// 			v * obj->texture->h), obj->texture->format,
	// 			&col.r, &col.g, &col.b);
	// 	obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
	// }

// void			make_texture_cylinder(t_tab_obj *obj, t_vec point, SDL_Color col)
// {
// 	t_real		rx;
// 	t_real		ry;
// 	t_real		rz;
// 	t_vec		dir_norm;

// 	dir_norm = vec_normalize(obj.dir);
// 	rx = (t_real){dir_norm.y, dir_norm.z};
// 	ry = (t_real){dir_norm.x, dir_norm.z};
// 	rz = (t_real){dir_norm.x, dir_norm.y};
// 	t_vec point = (t_vec){0,1,0};
// 	float ax = real_oriented_angle((t_real){point.y, point.z}, rx);
// 	float ay = real_oriented_angle((t_real){point.x, point.z}, ry);
// 	float az = real_oriented_angle((t_real){point.x, point.y}, rz);
// 	t_matrix_3_3 rot;
// 	matrix_rotation(ax, ay, az, rot);
// 	SDL_GetRGB(get_pixel(obj->texture, res.u * obj->texture->w,
// 				res.v * obj->texture->h), obj->texture->format,
// 				&col.r, &col.g, &col.b);
// 		obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
// }

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural)
	{
		if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, normal);
	}
	else
	{
		if (obj->type == 1)
			make_texture_sphere(obj, point, col);
		//if (obj->type == 4)
		//	make_texture_cylinder(obj, point, col);
		if (obj->type == 2)
			make_texture_plan(obj, point);
	}
}
