/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_2equ_2var_deg1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:00:58 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:30 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sys_solve_2equ_2var_deg1(t_equ_2var_deg1 e1, t_equ_2var_deg1 e2,
														t_sys_sol_2var_deg1 *s)
{
	float	tmp;

	if (!(tmp = e2.a_x * e1.a_y - e1.a_x * e2.a_y))
		return (0);
	tmp = 1. / tmp;
	s->x = (e2.a_y * e1.b - e1.a_y * e2.b) * tmp;
	s->y = (e1.a_x * e2.b - e2.a_x * e1.b) * tmp;
	return (1);
}
