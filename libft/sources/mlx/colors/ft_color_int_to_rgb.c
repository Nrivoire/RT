/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_int_to_rgb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:11:21 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:06 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_color_int_to_rgb(int nb)
{
	t_rgb	rgb;

	rgb.r = nb / 65536;
	rgb.g = nb / 256 % 256;
	rgb.b = nb % 256;
	rgb.a = 0;
	return (rgb);
}
