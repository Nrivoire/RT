/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/09 22:01:42 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Find the good color to each pixel on blur effect.
*/

int			blur_calc_b(t_env *v)
{
	int		b;

	b = (v->ppc.blur[0].b + v->ppc.blur[1].b + v->ppc.blur[2].b + \
		v->ppc.blur[3].b + v->ppc.blur[4].b + v->ppc.blur[5].b + \
		v->ppc.blur[6].b + v->ppc.blur[7].b + v->ppc.blur[8].b + \
		v->ppc.blur[9].b + v->ppc.blur[10].b + v->ppc.blur[11].b + \
		v->ppc.blur[12].b + v->ppc.blur[13].b + v->ppc.blur[14].b + \
		v->ppc.blur[15].b + v->ppc.blur[16].b + v->ppc.blur[17].b + \
		v->ppc.blur[18].b + v->ppc.blur[19].b + v->ppc.blur[20].b) \
		* 0.04761904761;
	return (b);
}

int			blur_calc_g(t_env *v)
{
	int			g;

	g = (v->ppc.blur[0].g + v->ppc.blur[1].g + v->ppc.blur[2].g + \
		v->ppc.blur[3].g + v->ppc.blur[4].g + v->ppc.blur[5].g + \
		v->ppc.blur[6].g + v->ppc.blur[7].g + v->ppc.blur[8].g + \
		v->ppc.blur[9].g + v->ppc.blur[10].g + v->ppc.blur[11].g + \
		v->ppc.blur[12].g + v->ppc.blur[13].g + v->ppc.blur[14].g + \
		v->ppc.blur[15].g + v->ppc.blur[16].g + v->ppc.blur[17].g + \
		v->ppc.blur[18].g + v->ppc.blur[19].g + v->ppc.blur[20].g) \
		* 0.04761904761;
	return (g);
}

int			blur_calc_r(t_env *v)
{
	int			r;

	r = (v->ppc.blur[0].r + v->ppc.blur[1].r + v->ppc.blur[2].r + \
		v->ppc.blur[3].r + v->ppc.blur[4].r + v->ppc.blur[5].r + \
		v->ppc.blur[6].r + v->ppc.blur[7].r + v->ppc.blur[8].r + \
		v->ppc.blur[9].r + v->ppc.blur[10].r + v->ppc.blur[11].r + \
		v->ppc.blur[12].r + v->ppc.blur[13].r + v->ppc.blur[14].r + \
		v->ppc.blur[15].r + v->ppc.blur[16].r + v->ppc.blur[17].r + \
		v->ppc.blur[18].r + v->ppc.blur[19].r + v->ppc.blur[20].r) \
		* 0.04761904761;
	return (r);
}
