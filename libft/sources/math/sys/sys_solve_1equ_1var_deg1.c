/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_solve_1equ_1var_deg1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:55:12 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:35 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	sys_solve_1equ_1var_deg1(float a, float b, t_sys_sol_1var_deg1 *s)
{
	if (!a)
		return (0);
	s->x = -b / a;
	return (1);
}
