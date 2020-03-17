/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process.c                                     :+:      :+:    :+:   */
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
** Apply anti-alising supersampling / SSAA.
*/

static int		get_hex(int r, int g, int b, int a)
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

void			supersampling(t_env *v)
{
	t_color		c_ssp[4];
	t_color		ssp;
	int			x;
	int			y;

	y = -1;
	while (++y < v->h - 1)
	{
		x = -1;
		while (++x < v->w)
		{
			c_ssp[0] = color_ssp(v->pixels[y * v->w + x]);
			c_ssp[1] = color_ssp(v->pixels[y * v->w + (x + 1)]);
			c_ssp[2] = color_ssp(v->pixels[(y + 1) * v->w + x]);
			c_ssp[3] = color_ssp(v->pixels[(y + 1) * v->w + (x + 1)]);
			ssp.r = (c_ssp[0].r + c_ssp[1].r + c_ssp[2].r + c_ssp[3].r) * 0.25;
			ssp.g = (c_ssp[0].g + c_ssp[1].g + c_ssp[2].g + c_ssp[3].g) * 0.25;
			ssp.b = (c_ssp[0].b + c_ssp[1].b + c_ssp[2].b + c_ssp[3].b) * 0.25;
			ssp.a = (c_ssp[0].a + c_ssp[1].a + c_ssp[2].a + c_ssp[3].a) * 0.25;
			v->pixels[y * v->w + x] = get_hex(ssp.r, ssp.g, ssp.b, ssp.a);
		}
	}
}
