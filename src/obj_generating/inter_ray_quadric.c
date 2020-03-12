/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_ray_quadric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:31:29 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:09:08 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	inter_ray_quadric_create_equ(t_ray r, t_quadric q, 	\
		t_sys_sol_1var_deg2 *sol)
{
	return (sys_solve_1equ_1var_deg2((t_equ_1var_deg2)				\
	{																\
				.a = q.a * r.d.x * r.d.x 							\
					+ q.b * r.d.y * r.d.y 							\
					+ q.c * r.d.z * r.d.z 							\
					+ q.d * r.d.x * r.d.y 							\
					+ q.e * r.d.x * r.d.z 							\
					+ q.f * r.d.y * r.d.z, 							\
				.b = q.a * 2 * r.o.x * r.d.x 						\
					+ q.b * 2 * r.o.y * r.d.y 						\
					+ q.c * 2 * r.o.z * r.d.z 						\
					+ q.d * (r.o.x * r.d.y + r.d.x * r.o.y) 		\
					+ q.e * (r.o.x * r.d.z + r.d.x * r.o.z) 		\
					+ q.f * (r.o.y * r.d.z + r.d.y * r.o.z) 		\
					+ q.g * r.d.x + q.h * r.d.y + q.i * r.d.z, 		\
				.c = q.a * r.o.x * r.o.x 							\
					+ q.b * r.o.y * r.o.y 							\
					+ q.c * r.o.z * r.o.z 							\
					+ q.d * r.o.x * r.o.y 							\
					+ q.e * r.o.x * r.o.z 							\
					+ q.f * r.o.y * r.o.z 							\
					+ q.g * r.o.x + q.h * r.o.y + q.i * r.o.z 		\
					+ q.j											\
	}, 																\
	sol));
}

int			inter_ray_quadric(t_ray r, t_quadric q, t_sol_2_vec *sol)
{
	t_sys_sol_1var_deg2	res;
	int					inter;

	sol->s1 = 0;
	sol->s2 = 0;
	if (!(inter = inter_ray_quadric_create_equ(r, q, &res)))
		return (0);
	sol->s1 = res.s1;
	sol->s2 = res.s2;
	if (res.s1)
	{
		if (res.x1 < 0)
			sol->s1 = 0;
		else
			sol->v1 = vec_add(r.o, vec_mult_float(r.d, res.x1));
	}
	if (res.s2)
	{
		if (res.x2 < 0)
			sol->s2 = 0;
		else
			sol->v2 = vec_add(r.o, vec_mult_float(r.d, res.x2));
	}
	return (sol->s1 || sol->s2);
}
