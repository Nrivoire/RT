/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_horiz.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:03:43 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:22 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_line_horiz(t_mlx_img img, t_cplx a, t_cplx z, t_rgb color)
{
	float	x1;
	float	y1;
	float	b;
	float	dx;
	float	dy;

	if (a.rl > z.rl)
		cplx_swap(&a, &z);
	x1 = a.rl;
	y1 = a.im;
	dx = z.rl - x1;
	dy = z.im - y1;
	b = y1 - x1 * dy / dx;
	while (z.rl - x1 > 0)
	{
		ft_pixel_put_rgb(img, x1, x1 * dy / dx + b, color);
		x1 <= z.rl ? x1++ : x1--;
	}
}
