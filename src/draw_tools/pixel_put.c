/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:03:30 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:04:01 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			clear_pixels(t_env *v)
{
	int			x;
	int			y;

	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
			pixel_put(v, x, y, (t_color){0, 0, 0, 255});
	}
}

static int		get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_env *v, int x, int y, t_color color)
{
	if (x >= v->w || y >= v->h || x < 0 || y < 0)
		return ;
	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	if (v->p.sc.filter == 0)
		v->pixels[y * v->w + x] = get_hex_rgba(color.r * 255, color.g * 255,
				color.b * 255, color.a);
	else if (v->p.sc.filter == 1)
		v->pixels[y * v->w + x] = greyscale(get_hex_rgba(color.r * 255,
				color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 2)
		v->pixels[y * v->w + x] = sepia(get_hex_rgba(color.r * 255,
				color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 3)
		v->pixels[y * v->w + x] = negative(get_hex_rgba(color.r * 255,
				color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 4)
		v->pixels[y * v->w + x] = cel_shading(get_hex_rgba(color.r * 255,
				color.g * 255, color.b * 255, color.a));
}