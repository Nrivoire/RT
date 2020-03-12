/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_cos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:41:59 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_cos(t_cplx z)
{
	t_cplx r;

	r.rl = cos(z.rl) * (exp(z.im) + exp(-z.im)) / 2;
	r.im = -sin(z.rl) * (exp(z.im) - exp(-z.im)) / 2;
	return (r);
}
