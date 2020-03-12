/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgb_to_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:11:44 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:11 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_color_rgb_to_hex(t_rgb rgb)
{
	char	*color;
	char	*hex;

	if (!(color = (char*)malloc(sizeof(*color) * 7)))
		ft_error("error");
	hex = "0123456789ABCDEF";
	color[0] = hex[rgb.r / 16];
	color[1] = hex[rgb.r % 16];
	color[2] = hex[rgb.g / 16];
	color[3] = hex[rgb.g % 16];
	color[4] = hex[rgb.b / 16];
	color[5] = hex[rgb.b % 16];
	return (color);
}
