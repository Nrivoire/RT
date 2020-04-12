/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:33:50 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:20:37 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "pp.h"

/*
** Apply a filter to each pixel: cel-shading / cartoon.
*/

int		cel_shading(int color)
{
	int		r;
	int		g;
	int		b;

	r = color >> 24 & 0xFF;
	g = color >> 16 & 0xFF;
	b = color >> 8 & 0xFF;
	r = (int)((r / CELSHADING) * CELSHADING << 24);
	g = (int)((g / CELSHADING) * CELSHADING << 16);
	b = (int)((b / CELSHADING) * CELSHADING << 8);
	return (r | g | b | (color & 0xFF));
}
