/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/12 20:53:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec	rot_axe_x_r(t_vec point, float angle)
{
	point.x = point.x;
	point.y = point.y * cosf(angle) + point.z * sinf(angle);
	point.z = point.z * cosf(angle) - point.y * sinf(angle);
	return (point);
}

t_vec	rot_axe_x_l(t_vec point, float angle)
{
	point.x = point.x;
	point.y = point.y * cosf(angle) - point.z * sinf(angle);
	point.z = point.z * cosf(angle) + point.y * sinf(angle);
	return (point);
}
