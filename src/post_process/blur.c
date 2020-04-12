/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:20:22 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "pp.h"

/*
** Apply blur effect.
*/

static void		blur_effect(t_env *v, int x, int y)
{
	v->ppc.blur[0] = color_ssp(v->pixels[(y + 0) * v->w + (x + 0)]);
	v->ppc.blur[1] = color_ssp(v->pixels[(y - 1) * v->w + (x - 1)]);
	v->ppc.blur[2] = color_ssp(v->pixels[(y - 1) * v->w + (x + 0)]);
	v->ppc.blur[3] = color_ssp(v->pixels[(y - 1) * v->w + (x + 1)]);
	v->ppc.blur[4] = color_ssp(v->pixels[(y + 0) * v->w + (x - 1)]);
	v->ppc.blur[5] = color_ssp(v->pixels[(y + 0) * v->w + (x + 1)]);
	v->ppc.blur[6] = color_ssp(v->pixels[(y + 1) * v->w + (x - 1)]);
	v->ppc.blur[7] = color_ssp(v->pixels[(y + 1) * v->w + (x + 0)]);
	v->ppc.blur[8] = color_ssp(v->pixels[(y + 1) * v->w + (x + 1)]);
	v->ppc.blur[9] = color_ssp(v->pixels[(y - 2) * v->w + (x - 1)]);
	v->ppc.blur[10] = color_ssp(v->pixels[(y - 2) * v->w + (x + 0)]);
	v->ppc.blur[11] = color_ssp(v->pixels[(y - 2) * v->w + (x + 1)]);
	v->ppc.blur[12] = color_ssp(v->pixels[(y - 1) * v->w + (x - 2)]);
	v->ppc.blur[13] = color_ssp(v->pixels[(y + 0) * v->w + (x - 2)]);
	v->ppc.blur[14] = color_ssp(v->pixels[(y + 1) * v->w + (x - 2)]);
	v->ppc.blur[15] = color_ssp(v->pixels[(y - 1) * v->w + (x + 2)]);
	v->ppc.blur[16] = color_ssp(v->pixels[(y + 0) * v->w + (x + 2)]);
	v->ppc.blur[17] = color_ssp(v->pixels[(y + 1) * v->w + (x + 2)]);
	v->ppc.blur[18] = color_ssp(v->pixels[(y + 2) * v->w + (x - 1)]);
	v->ppc.blur[19] = color_ssp(v->pixels[(y + 2) * v->w + (x + 0)]);
	v->ppc.blur[20] = color_ssp(v->pixels[(y + 2) * v->w + (x + 1)]);
}


void			blur(t_env *v)
{
	int			x;
	int			y;
	t_color		blr;

	y = 1;
	while (++y < v->h - 2)
	{
		x = 1;
		while (++x < v->w - 2)
		{
			blur_effect(v, x, y);
			blr.r = blur_calc_r(v);
			blr.g = blur_calc_g(v);
			blr.b = blur_calc_b(v);
			v->pixels[y * v->w + x] = get_hex(blr.r, blr.g, blr.b);
		}
	}
}
