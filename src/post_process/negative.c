/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:33:59 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/05 19:34:00 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"
#include "pp.h"

/*
** Apply a filter to each pixel: negative.
*/

int		negative(int color)
{
	int		r;
	int		g;
	int		b;

	r = (255 - ((color >> 24) & 0xFF)) << 24;
	g = (255 - ((color >> 16) & 0xFF)) << 16;
	b = (255 - ((color >> 8) & 0xFF)) << 8;
	return (r | g | b | (color & 0xFF));
}
