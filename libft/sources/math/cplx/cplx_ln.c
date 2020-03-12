/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_ln.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:41:46 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_ln(t_cplx z)
{
	t_cplx r;

	r.rl = 0.5 * log(cplx_modul_2(z));
	r.im = atan(z.im / z.rl);
	return (r);
}
