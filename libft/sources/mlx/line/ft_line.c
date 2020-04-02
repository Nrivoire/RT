/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:08:15 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:36 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_line(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	int	dx;
	int	dy;

	if (ft_line_straight(img, a, z, color))
		return ;
	dx = ft_abs(z.rl - a.rl);
	dy = ft_abs(z.im - a.im);
	dx >= dy ? ft_line_horiz(img, a, z, color) : ft_line_vert(img, a, z, color);
}
