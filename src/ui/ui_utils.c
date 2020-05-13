/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:25:42 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/12 19:58:12 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			get_hex_menu(int r, int g, int b)
{
	return ((r << 24) | (g << 16) | (b << 8));
}

void		pixel_put_menu(t_env *v, int x, int y, t_color color)
{
	if (x >= v->ui.m_w || y >= v->ui.m_h || x < 0 || y < 0)
		return ;
	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(color.r * 255, \
			color.g * 255, color.b * 255);
}

void		put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y)
{
	SDL_Color	col;
	int			x;
	int			y;

	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
		{
			SDL_GetRGBA(get_pixel(sur, x, y),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put_menu(v, x + s_x, y + s_y,
						(t_color){col.r, col.g, col.b});
		}
	}
	SDL_FreeSurface(sur);
}
