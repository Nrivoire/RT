/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:01:20 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_cross_product(t_vec u, t_vec v)
{
	t_vec	n;

	n.x = u.y * v.z - u.z * v.y;
	n.y = u.z * v.x - u.x * v.z;
	n.z = u.x * v.y - u.y * v.x;
	return (n);
}

inline float	vec_scale_product(t_vec u, t_vec v)
{
	return (fmaf(u.x, v.x, fmaf(u.y, v.y, fmaf(u.z, v.z, 0))));
}
