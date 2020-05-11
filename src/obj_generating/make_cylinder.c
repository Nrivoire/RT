/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:17:25 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:30:13 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_quadric		make_cylinder(t_vec a, t_vec v, float r)
{
	t_quadric	res;

	res.a = v.y * v.y + v.z * v.z;
	res.b = v.x * v.x + v.z * v.z;
	res.c = v.y * v.y + v.x * v.x;
	res.d = -2 * v.x * v.y;
	res.e = -2 * v.x * v.z;
	res.f = -2 * v.y * v.z;
	res.g = 2 * (v.z * (v.x * a.z - v.z * a.x) + v.y * (v.x * a.y - v.y * a.x));
	res.h = 2 * (v.x * (v.y * a.x - v.x * a.y) + v.z * (v.y * a.z - v.z * a.y));
	res.i = 2 * (v.x * (v.z * a.x - v.x * a.z) + v.y * (v.z * a.y - v.y * a.z));
	res.j = v.x * v.x * (a.y * a.y + a.z * a.z) +
			v.y * v.y * (a.x * a.x + a.z * a.z) +
			v.z * v.z * (a.x * a.x + a.y * a.y)
			- 2 * (v.x * v.y * a.x * a.y
				+ v.x * v.z * a.x * a.z
				+ v.y * v.z * a.y * a.z)
			- r * r;
	return (res);
}
