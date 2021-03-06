/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:17:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vec	rot_axe_x(t_vec point, float angle, char dir)
{
	point.x = point.x;
	if (dir == 'R')
	{
		point.y = point.y * cosf(angle) + point.z * sinf(angle);
		point.z = point.z * cosf(angle) - point.y * sinf(angle);
	}
	if (dir == 'L')
	{
		point.y = point.y * cosf(angle) - point.z * sinf(angle);
		point.z = point.z * cosf(angle) + point.y * sinf(angle);
	}
	return (point);
}

t_vec	rot_axe_y(t_vec point, float angle, char dir)
{
	point.y = point.y;
	if (dir == 'R')
	{
		point.x = point.x * cosf(angle) + point.z * sinf(angle);
		point.z = point.z * cosf(angle) - point.x * sinf(angle);
	}
	if (dir == 'L')
	{
		point.x = point.x * cosf(angle) - point.z * sinf(angle);
		point.z = point.z * cosf(angle) + point.x * sinf(angle);
	}
	return (point);
}

t_vec	rot_axe_z(t_vec point, float angle, char dir)
{
	point.z = point.z;
	if (dir == 'R')
	{
		point.x = point.x * cosf(angle) + point.y * sinf(angle);
		point.y = point.y * cosf(angle) - point.x * sinf(angle);
	}
	if (dir == 'L')
	{
		point.x = point.x * cosf(angle) - point.y * sinf(angle);
		point.y = point.y * cosf(angle) + point.x * sinf(angle);
	}
	return (point);
}
