/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_rgb_random.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:01:45 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:09 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_rgb	ft_color_rgb_random(void)
{
	t_rgb	color;

	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.a = 0;
	return (color);
}
