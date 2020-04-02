/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/05 19:37:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "pp.h"

/*
** Utils use in SSAA and Blur.
*/

int				get_hex(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

t_color			color_ssp(Uint32 pixel)
{
	int		r;
	int		g;
	int		b;
	int		a;
	t_color	color;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	a = pixel & 0xFF;
	color = (t_color){r, g, b, a};
	return (color);
}
