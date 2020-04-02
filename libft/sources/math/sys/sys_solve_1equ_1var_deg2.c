/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_1equ_1var_deg2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:48 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 19:50:21 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			norme(t_equ_1var_deg2 e, t_sys_sol_1var_deg2 *s)
{
	float				delta;
	float				tmp;
	float				sqrt_delta;

	delta = ft_sq(e.b) - 4 * e.a * e.c;
	tmp = 1 / (2 * e.a);
	if (delta < 0)
		return (0);
	else if (!delta)
	{
		s->s1 = 1;
		s->x1 = -e.b * tmp;
		return (1);
	}
	sqrt_delta = sqrtf(delta);
	s->s1 = 1;
	s->s2 = 1;
	s->x1 = (-e.b - sqrt_delta) * tmp;
	s->x2 = (-e.b + sqrt_delta) * tmp;
	return (2);
}

int			sys_solve_1equ_1var_deg2(t_equ_1var_deg2 e, t_sys_sol_1var_deg2 *s)
{
	int					result;
	t_sys_sol_1var_deg1	sol;

	s->s1 = 0;
	s->s2 = 0;
	if (!e.a && !e.b)
		return (0);
	if (!e.a)
	{
		result = sys_solve_1equ_1var_deg1(e.b, e.c, &sol);
		if (!result)
			return (0);
		s->s1 = 1;
		s->x1 = sol.x;
		return (1);
	}
	norme(e, s);
	return (2);
}
