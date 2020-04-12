/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greyscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:34:34 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:20:41 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "pp.h"

/*
** Apply a filter to each pixel: greyscale.
*/

int		greyscale(int color)
{
	t_color			rgb;
	unsigned int	v;

	rgb.r = color >> 24 & 0xFF;
	rgb.g = color >> 16 & 0xFF;
	rgb.b = color >> 8 & 0xFF;
	v = rgb.r * 0.212671 + rgb.g * 0.715160 + rgb.b * 0.072169;
	return (((int)v << 24) | ((int)v << 16) | (int)v << 8 | (color & 0xFF));
}
