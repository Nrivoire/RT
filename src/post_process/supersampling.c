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


static void		supersampling_calc(t_env *v, int x, int y)
{
	t_color		ssp;
	
	ssp.r = (v->ppc.ssaa[0].r + v->ppc.ssaa[1].r + v->ppc.ssaa[2].r + \
		v->ppc.ssaa[3].r + v->ppc.ssaa[4].r) * 0.2;
	ssp.g = (v->ppc.ssaa[0].g + v->ppc.ssaa[1].g + v->ppc.ssaa[2].g + \
		v->ppc.ssaa[3].g + v->ppc.ssaa[4].g) * 0.2;
	ssp.b = (v->ppc.ssaa[0].b + v->ppc.ssaa[1].b + v->ppc.ssaa[2].b + \
		v->ppc.ssaa[3].b + v->ppc.ssaa[4].b) * 0.2;
	ssp.a = (v->ppc.ssaa[0].a + v->ppc.ssaa[1].a + v->ppc.ssaa[2].a + \
		v->ppc.ssaa[3].a + v->ppc.ssaa[4].a) * 0.2;
	v->pixels[y * v->w + x] = get_hex(ssp.r, ssp.g, ssp.b, ssp.a);
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
