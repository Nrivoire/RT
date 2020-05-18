/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:22:52 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/18 15:11:33 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		stereo_r(int color)
{
	t_color				rgb;
	t_color				stereo;

	rgb.r = (color >> 24 & 0xFF);
	rgb.g = (color >> 16 & 0xFF);
	rgb.b = (color >> 8 & 0xFF);
	stereo.r = 0.393 * rgb.r + 0.769 * rgb.g + 0.189 * rgb.b;
	stereo.g = 0;
	stereo.b = 0;
	if (stereo.r > 255)
		stereo.r = 255;
	return (((int)stereo.r << 24)\
		| ((int)stereo.g << 16)\
		| ((int)stereo.b << 8)\
		| (color & 0xFF));
}

int		stereo_b(int color)
{
	t_color				rgb;
	t_color				stereo;

	rgb.r = (color >> 24 & 0xFF);
	rgb.g = (color >> 16 & 0xFF);
	rgb.b = (color >> 8 & 0xFF);
	stereo.r = 0;
	stereo.g = 0;
	stereo.b = 0.189 * rgb.r + 0.769 * rgb.g + 0.393 * rgb.b;
	if (stereo.r > 255)
		stereo.r = 255;
	return (((int)stereo.r << 24)\
		| ((int)stereo.g << 16)\
		| ((int)stereo.b << 8)\
		| (color & 0xFF));
}
