/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:33:59 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:20:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
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
