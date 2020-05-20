/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/20 15:35:38 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
   
//     vNormal.x = (1.0f - currentMat.bump ) * vNormal.x + currentMat.bump * noiseCoefx; 
//     vNormal.y = (1.0f - currentMat.bump ) * vNormal.y + currentMat.bump * noiseCoefy; 
//     vNormal.z = (1.0f - currentMat.bump ) * vNormal.z + currentMat.bump * noiseCoefz; 
   
//     temp = vNormal * vNormal;
//     if (temp == 0.0f)
//     break;
//     temp = invsqrtf(temp);
//     vNormal = temp * vNormal;
// }

// void	bump_mapping(t_env *v, t_vec *normal, t_vec point)
// {
// 	float	noiseCoefx;
// 	float	noiseCoefy;
// 	float	noiseCoefz;

// 	noiseCoefx = noise(v, 0.1 * point.x, 0.1 * point.y, 0.1 * point.z);
// 	noiseCoefy = noise(v, 0.1 * point.y, 0.1 * point.z, 0.1 * point.x);
// 	noiseCoefz = noise(v, 0.1 * point.z, 0.1 * point.x, 0.1 * point.y);
// 	normal->x = (1.0 - currentMat.bump ) * vNormal.x + currentMat.bump * noiseCoefx;
// }

float			texture_color_move(float x)
{
	return ((1 - round((2 * (x - floor(x)) - 1))));
}

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec *normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
	if (obj->procedural == GRAD)
	{
		obj->color.r = texture_color_move(obj->pos.x * obj->pos.y);
		obj->color.g = texture_color_move(obj->pos.y * obj->pos.z);
		obj->color.b = texture_color_move(obj->pos.x * obj->pos.z);
	}
	if (obj->procedural)
	{
		if (obj->procedural == WAVES)
			quadric_normal_pertu(obj->q, point, obj->waves, normal);
		else if (v->pe[0] != 151)
			init_permutation(v);
		create_texture_procedural(v, obj, *normal);
	}
	else
	{
		if (obj->type == 1)
			make_texture_sphere(obj, point, col);
		if (obj->type == 4)
			make_texture_cylinder(obj, point, col);
		if (obj->type == 2)
			make_texture_plan(obj, point);
	}
}
