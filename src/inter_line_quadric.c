/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inter_line_quadric.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 12:31:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/21 15:57:55 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

int	inter_line_quadric(t_line l, t_quadric q, t_sys_sol_1var_deg2 *result)
{
	return (sys_solve_1equ_1var_deg2((t_equ_1var_deg2)			\
			{													\
				.a = q.a * ft_sq(l.x.u) 						\
					+ q.b * ft_sq(l.y.u) 						\
					+ q.c * ft_sq(l.z.u) 						\
					+ q.d * l.x.u * l.y.u 						\
					+ q.e * l.x.u * l.z.u 						\
					+ q.f * l.y.u * l.z.u, 						\
				.b = q.a * 2 * l.x.o * l.x.u 					\
					+ q.b * 2 * l.y.o * l.y.u 					\
					+ q.c * 2 * l.z.o * l.z.u 					\
					+ q.d * (l.x.o * l.y.u + l.x.u * l.y.o) 	\
					+ q.e * (l.x.o * l.z.u + l.x.u * l.z.o) 	\
					+ q.f * (l.y.o * l.z.u + l.y.u * l.z.o) 	\
					+ q.g * l.x.u + q.h * l.y.u + q.i * l.z.u, 	\
				.c = q.a * ft_sq(l.x.o) 						\
					+ q.b * ft_sq(l.y.o) 						\
					+ q.c * ft_sq(l.z.o) 						\
					+ q.d * l.x.o * l.y.o 						\
					+ q.e * l.x.o * l.z.o 						\
					+ q.f * l.y.o * l.z.o 						\
					+ q.g * l.x.o + q.h * l.y.o + q.i * l.z.o 	\
					+ q.j										\
			}, 													\
			result));
}
