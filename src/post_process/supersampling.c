/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/11 15:50:32 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Apply anti-alising supersampling / SSAA.
*/

static void		supersampling_calc(t_env *v, int x, int y)
{
	t_color		ssp;

	ssp.r = (v->ppc.ssaa[0].r + v->ppc.ssaa[1].r + v->ppc.ssaa[2].r + \
		v->ppc.ssaa[3].r + v->ppc.ssaa[4].r) * 0.2;
	ssp.g = (v->ppc.ssaa[0].g + v->ppc.ssaa[1].g + v->ppc.ssaa[2].g + \
		v->ppc.ssaa[3].g + v->ppc.ssaa[4].g) * 0.2;
	ssp.b = (v->ppc.ssaa[0].b + v->ppc.ssaa[1].b + v->ppc.ssaa[2].b + \
		v->ppc.ssaa[3].b + v->ppc.ssaa[4].b) * 0.2;
	v->pixels[y * v->w + x] = get_hex_rgba(ssp.r, ssp.g, ssp.b, 255);
}

void			supersampling(t_env *v)
{
	int			x;
	int			y;

	y = 0;
	while (++y < v->h - 1)
	{
		x = 0;
		while (++x < v->w - 1)
		{
			v->ppc.ssaa[0] = color_ssp(v->pixels[(y + 0) * v->w + (x + 0)]);
			v->ppc.ssaa[1] = color_ssp(v->pixels[(y - 1) * v->w + (x + 0)]);
			v->ppc.ssaa[2] = color_ssp(v->pixels[(y + 0) * v->w + (x - 1)]);
			v->ppc.ssaa[3] = color_ssp(v->pixels[(y + 0) * v->w + (x + 1)]);
			v->ppc.ssaa[4] = color_ssp(v->pixels[(y + 1) * v->w + (x + 0)]);
			supersampling_calc(v, x, y);
		}
	}
}
