/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:34:26 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/05 19:34:27 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "pp.h"

int		sepia(int color)
{
	t_color				rgb;
	t_color				sepia;

	rgb.r = (color >> 24 & 0xFF);
	rgb.g = (color >> 16 & 0xFF);
	rgb.b = (color >> 8 & 0xFF);
	sepia.r = rgb.r * 0.393 + rgb.g * 0.769 + rgb.b * 0.189;
	sepia.g = rgb.r * 0.349 + rgb.g * 0.686 + rgb.b * 0.168;
	sepia.b = rgb.r * 0.272 + rgb.g * 0.534 + rgb.b * 0.131;
	sepia.r = MIN(255, sepia.r);
	sepia.g = MIN(255, sepia.g);
	sepia.b = MIN(255, sepia.b);
	return (((int)sepia.r << 24)\
		| ((int)sepia.g << 16)\
		| ((int)sepia.b << 8)\
		| (color & 0xFF));
}
