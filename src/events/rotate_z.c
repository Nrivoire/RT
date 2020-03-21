/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/12 20:53:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec	rot_axe_z_r(t_vec point, float angle)
{
	point.x = point.x * cosf(angle) + point.y * sinf(angle);
	point.y = point.y * cosf(angle) - point.x * sinf(angle);
	point.z = point.z;
	return (point);
}

t_vec	rot_axe_z_l(t_vec point, float angle)
{
	point.x = point.x * cosf(angle) - point.y * sinf(angle);
	point.y = point.y * cosf(angle) + point.x * sinf(angle);
	point.z = point.z;
	return (point);
}
