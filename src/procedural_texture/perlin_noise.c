/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:08:19 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/11 19:25:31 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

// float		perlin_noise(int octaves, double frequency, double persistence, t_tab_obj *obj)
// {
	
// }

void		create_texture_procedural(t_tab_obj *obj)
{
	float	time;
	t_vec	t;

	int c = 12;
	time = noise(obj->normale.x * c, obj->normale.y * c, obj->normale.z * c);
	//t.x = noise(obj->normale.x, obj->normale.y, obj->normale.z);
	//t.y = noise(obj->normale.y, obj->normale.z, obj->normale.x);
	//t.z = noise(obj->normale.z, obj->normale.x, obj->normale.y);
	//obj->normale.x = obj->normale.x * t.x;
	//obj->normale.y = obj->normale.y * t.y;
	//obj->normale.z = obj->normale.z * t.z;
	if (time >= 0)
		obj->color = (t_color){obj->color.r * time, obj->color.g * time, obj->color.b * time, 255};
}
