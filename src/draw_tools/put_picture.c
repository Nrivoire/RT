/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_picture.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:57:26 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:57:34 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void			put_picture(t_env *v, t_start s, int size, SDL_Surface *sur)
{
	SDL_Color	col;
	int			x;
	int			y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			SDL_GetRGBA(get_pixel(sur, x * sur->w / size, y * sur->h / size),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put(v, s.x + x, s.y + y, (t_rgb){col.r, col.g, col.b,
						col.a});
		}
	}
}
