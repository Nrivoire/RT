/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:55:49 by qpupier           #+#    #+#             */
/*   Updated: 2020/05/21 05:58:38 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_ratio(t_color color, float ratio)
{
	return ((t_color){color.r * ratio, color.g * ratio, color.b * ratio});
}

t_color	color_op(t_color c1, char op, t_color c2)
{
	t_color	color;

	color = (t_color){0, 0, 0};
	if (op == '*')
	{
		color.r = c1.r * c2.r;
		color.g = c1.g * c2.g;
		color.b = c1.b * c2.b;
	}
	else if (op == '+')
	{
		color.r = c1.r + c2.r;
		color.g = c1.g + c2.g;
		color.b = c1.b + c2.b;
	}
	return (color);
}

t_color	limit_color(t_color color)
{
	if (color.r < 0)
		color.r = 0;
	else if (color.r > 1)
		color.r = 1;
	if (color.g < 0)
		color.g = 0;
	else if (color.g > 1)
		color.g = 1;
	if (color.b < 0)
		color.b = 0;
	else if (color.b > 1)
		color.b = 1;
	return (color);
}
