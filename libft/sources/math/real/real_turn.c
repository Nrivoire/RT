/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:52:27 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:41 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_real	real_turn(t_real point, float degree)
{
	t_real	new;

	degree = ft_deg_to_rad(degree);
	new.x = cos(degree) * point.x - sin(degree) * point.y;
	new.y = sin(degree) * point.x + cos(degree) * point.y;
	return (new);
}
