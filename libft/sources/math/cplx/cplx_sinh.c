/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_sinh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:41:23 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_sinh(t_cplx z)
{
	t_cplx r;

	r.rl = cos(z.im) * (exp(z.rl) - exp(-z.rl)) / 2;
	r.im = sin(z.im) * (exp(z.rl) + exp(-z.rl)) / 2;
	return (r);
}
