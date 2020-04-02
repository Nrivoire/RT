/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_2d_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:48:39 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:41:00 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_2d_ray	create_2d_ray(t_real a, t_real b)
{
	t_2d_ray	new;
	t_2d_line	line;

	new.o = a;
	new.d = op_real(a, '>', b);
	line = create_2d_line_points(a, b);
	new.a = line.a;
	new.b = line.b;
	new.c = line.c;
	return (new);
}
