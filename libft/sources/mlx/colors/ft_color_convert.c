/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_convert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:19:20 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:37:02 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb			hex_to_rgb(unsigned int color)
{
	t_rgb c;

	c.a = color >> 24 & 0xFF;
	c.g = color >> 16 & 0xFF;
	c.b = color >> 8 & 0xFF;
	c.r = color & 0xFF;
	return (c);
}

unsigned int	rgb_to_hex(t_rgb c)
{
	return ((c.a << 24) | (c.g << 16) | (c.b << 8) | (c.r));
}
