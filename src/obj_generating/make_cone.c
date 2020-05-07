/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:18:45 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:30:10 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		make_cone_quadric(t_quadric *q, t_vec v, float sin_2)
{
	float		vx_2;
	float		vy_2;
	float		vz_2;

	vx_2 = v.x * v.x;
	vy_2 = v.y * v.y;
	vz_2 = v.z * v.z;
	q->a = vy_2 + vz_2 - sin_2;
	q->b = vx_2 + vz_2 - sin_2;
	q->c = vx_2 + vy_2 - sin_2;
	q->d = -2 * v.x * v.y;
	q->e = -2 * v.x * v.z;
	q->f = -2 * v.y * v.z;
}

static void		make_cone_surface(t_quadric *q, t_vec a, t_vec v, float sin_2)
{
	float		vx_2;
	float		vy_2;
	float		vz_2;

	vx_2 = v.x * v.x;
	vy_2 = v.y * v.y;
	vz_2 = v.z * v.z;
	q->g = 2 * (v.y * (v.x * a.y - v.y * a.x) 		\
			+ v.z * (v.x * a.z - v.z * a.x) + sin_2 * a.x);
	q->h = 2 * (v.x * (v.y * a.x - v.x * a.y) 		\
			+ v.z * (v.y * a.z - v.z * a.y) + sin_2 * a.y);
	q->i = 2 * (v.x * (v.z * a.x - v.x * a.z) 		\
			+ v.y * (v.z * a.y - v.y * a.z) + sin_2 * a.z);
	q->j = a.x * a.x * (vy_2 + vz_2 - sin_2) 		\
			+ a.y * a.y * (vx_2 + vz_2 - sin_2) 	\
			+ a.z * a.z * (vx_2 + vy_2 - sin_2) 	\
			- 2 * (v.x * v.y * a.x * a.y 			\
			+ v.x * v.z * a.x * a.z 				\
			+ v.y * v.z * a.y * a.z);
}

t_quadric		make_cone(t_vec a, t_vec v, float alpha)
{
	t_quadric	q;
	float		sin_2;

	sin_2 = sin(alpha) * sin(alpha);
	make_cone_quadric(&q, v, sin_2);
	make_cone_surface(&q, a, v, sin_2);
	return (q);
}
