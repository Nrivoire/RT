/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:36:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:09 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	vec_equal(t_vec u, t_vec v)
{
	return (u.x == v.x && u.y == v.y && u.z == v.z);
}

inline int	vec_equal_precision(t_vec u, t_vec v, float p)
{
	return (floatcmp(u.x, v.x, p) && floatcmp(u.y, v.y, p)
			&& floatcmp(u.z, v.z, p));
}
