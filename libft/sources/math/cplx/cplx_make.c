/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx_make.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 07:38:17 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:41:43 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_make_cplx(float rl, float im)
{
	t_cplx r;

	r.rl = rl;
	r.im = im;
	return (r);
}
