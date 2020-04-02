/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:26:51 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:41:32 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	cplx_remove(t_cplx a, t_cplx b)
{
	t_cplx r;

	r.rl = a.rl - b.rl;
	r.im = a.im - b.im;
	return (r);
}
