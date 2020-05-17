/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:19:32 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/16 21:05:19 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// t_quadric		make_sphere(t_vec center, float radius)
// {
// 	t_quadric	res;

// 	res.a = 1;
// 	res.b = 1;
// 	res.c = 1;
// 	res.d = 0;
// 	res.e = 0;
// 	res.f = 0;
// 	res.g = -2 * center.x;
// 	res.h = -2 * center.y;
// 	res.i = -2 * center.z;
// 	res.j = center.x * center.x + center.y * center.y + center.z * center.z
// 			- radius * radius;
// 	return (res);
// }

t_quadric		make_sphere(t_vec center, float radius)
{
	t_quadric	res;

	res.a = 1;
	res.b = 1;
	res.c = 1;
	res.d = 0;
	res.e = 0;
	res.f = 0;
	res.g = -2 * center.x;
	res.h = -2 * center.y;
	res.i = -2 * center.z;
	res.j = (center.x * center.x + center.y * center.y + center.z * center.z
			- radius * radius ) / 1;
	return (res);
}
