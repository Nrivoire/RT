/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:34:26 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/09 22:02:06 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Apply a filter to each pixel: sepia.
*/

static float	min_value(float limit, float value)
{
	float	res;

	if (value < limit)
		res = value;
	else
		res = limit;
	return (res);
}

int				sepia(int color)
{
	t_color				rgb;
	t_color				sepia;

	rgb.r = (color >> 24 & 0xFF);
	rgb.g = (color >> 16 & 0xFF);
	rgb.b = (color >> 8 & 0xFF);
	sepia.r = rgb.r * 0.393 + rgb.g * 0.769 + rgb.b * 0.189;
	sepia.g = rgb.r * 0.349 + rgb.g * 0.686 + rgb.b * 0.168;
	sepia.b = rgb.r * 0.272 + rgb.g * 0.534 + rgb.b * 0.131;
	sepia.r = min_value(255, sepia.r);
	sepia.g = min_value(255, sepia.g);
	sepia.b = min_value(255, sepia.b);
	return (((int)sepia.r << 24)\
		| ((int)sepia.g << 16)\
		| ((int)sepia.b << 8)\
		| (color & 0xFF));
}
