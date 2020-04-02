/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_collinears.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:47:18 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:39:13 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline int	vec_collinears(t_vec u, t_vec v)
{
	double	k;

	if (v.x)
		k = (double)u.x / (double)v.x;
	else if (v.y)
		k = (double)u.y / (double)v.y;
	else if (v.z)
		k = (double)u.z / (double)v.z;
	else
		return (1);
	return (u.x == k * v.x && u.y == k * v.y && u.z == k * v.z);
}
