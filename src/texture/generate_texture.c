/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 19:11:49 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/20 13:23:07 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// if (currentMat.bump)
// {
//     float noiseCoefx = float(noise(0.1 * double(ptHitPoint.x), 0.1 * double(ptHitPoint.y),0.1 * double(ptHitPoint.z)));
//     float noiseCoefy = float(noise(0.1 * double(ptHitPoint.y), 0.1 * double(ptHitPoint.z),0.1 * double(ptHitPoint.x)));
//     float noiseCoefz = float(noise(0.1 * double(ptHitPoint.z), 0.1 * double(ptHitPoint.x),0.1 * double(ptHitPoint.y)));
   
//     vNormal.x = (1.0f - currentMat.bump ) * vNormal.x + currentMat.bump * noiseCoefx; 
//     vNormal.y = (1.0f - currentMat.bump ) * vNormal.y + currentMat.bump * noiseCoefy; 
//     vNormal.z = (1.0f - currentMat.bump ) * vNormal.z + currentMat.bump * noiseCoefz; 
   
//     temp = vNormal * vNormal;
//     if (temp == 0.0f)
//     break;
//     temp = invsqrtf(temp);
//     vNormal = temp * vNormal;
// }

// void	bump_mapping(t_vec normal)
// {

// }

void			generate_texture(t_env *v, t_tab_obj *obj, t_vec point, \
					t_vec *normal)
{
	SDL_Color col;

	col = (SDL_Color){0, 0, 0, 255};
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
