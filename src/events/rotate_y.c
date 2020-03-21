/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/12 20:53:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec	rot_axe_y_r(t_vec point, float angle)
{
	point.x = point.x * cosf(angle) + point.z * sinf(angle);
	point.y = point.y;
	point.z = point.z * cosf(angle) - point.x * sinf(angle);
	return (point);
}

t_vec	rot_axe_y_l(t_vec point, float angle)
{
	point.x = point.x * cosf(angle) - point.z * sinf(angle);
	point.y = point.y;
	point.z = point.z * cosf(angle) + point.x * sinf(angle);
	return (point);
}
