/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:37:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/09 22:02:03 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Utils use in SSAA and Blur.
*/

int				get_hex(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8));
}

t_color			color_ssp(Uint32 pixel)
{
	int		r;
	int		g;
	int		b;
	t_color	color;

	r = pixel >> 24 & 0xFF;
	g = pixel >> 16 & 0xFF;
	b = pixel >> 8 & 0xFF;
	color = (t_color){r, g, b};
	return (color);
}
