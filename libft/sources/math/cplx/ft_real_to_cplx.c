/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_to_cplx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:13:59 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:41:10 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_cplx	ft_real_to_cplx(t_real xy)
{
	t_cplx	r;

	r.rl = xy.x;
	r.im = xy.y;
	return (r);
}
