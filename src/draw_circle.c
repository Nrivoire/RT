/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_circle.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 15:04:07 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:09:27 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		draw_void_circle(t_env *v, int x, int y, int radius)
{
	int		j;
	int		i;

	v->center.x = x;
	v->center.y = y;
	j = -radius - 1;
	while (++j <= radius)
	{
		i = -radius - 1;
		while (++i < radius + 1)
		{
			if (sqrt(i * i + j * j) >= radius - 1 &&
					sqrt(i * i + j * j) <= radius + 1)
				pixel_put(v, x + i, y + j, (t_rgb){153, 0, 255, 255});
		}
	}
}

void		draw_full_circle(t_env *v, int x, int y, int radius)
{
	int		j;
	int		i;

	v->center.x = x;
	v->center.y = y;
	j = -radius - 1;
	while (++j <= radius)
	{
		i = -radius - 1;
		while (++i < radius)
		{
			if (sqrt(i * i + j * j) <= radius)
				pixel_put(v, x + i, y + j, (t_rgb){153, 0, 255, 255});
		}
	}
}
