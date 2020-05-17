/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cel_shading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:33:50 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/17 18:24:23 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	r = (int)((r / ft_clamp(CELSHADING, 2, 60))\
		* ft_clamp(CELSHADING, 2, 60) << 24);
	g = (int)((g / ft_clamp(CELSHADING, 2, 60))\
		* ft_clamp(CELSHADING, 2, 60) << 16);
	b = (int)((b / ft_clamp(CELSHADING, 2, 60))\
		* ft_clamp(CELSHADING, 2, 60) << 8);
	return (r | g | b | (color & 0xFF));
}
