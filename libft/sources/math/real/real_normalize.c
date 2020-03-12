/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 23:26:16 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:48 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_real	real_normalize(t_real v)
{
	float	tmp;

	if (!(tmp = real_norm(v)))
		return ((t_real){0, 0});
	tmp = 1 / tmp;
	v.x *= tmp;
	v.y *= tmp;
	return (v);
}
