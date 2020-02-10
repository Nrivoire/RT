/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/12 13:46:28 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:09:23 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_bressen	init_bresen(t_point m1, t_point m2)
{
	t_bressen		b;

	b.dx = ft_absolu(m2.x - m1.x);
	b.dy = ft_absolu(m2.y - m1.y);
	b.sx = (m1.x < m2.x ? 1 : -1);
	b.sy = (m1.y < m2.y ? 1 : -1);
	b.err = (b.dx > b.dy ? b.dx : -b.dy) / 2;
	return (b);
}

void				drawline(t_point m1, t_point m2, t_rgb color, t_env *v)
{
	t_bressen		b;

	if ((m1.x < 0 && m1.y < 0 && m2.y < 0 && m2.x < 0) ||
			(m1.x > v->w && m1.y > v->h && m2.y > v->h && m2.x > v->w))
		return ;
	b = init_bresen(m1, m2);
	while (1)
	{
		pixel_put(v, m1.x, m1.y, color);
		if (m1.x == m2.x && m1.y == m2.y)
			break ;
		b.e2 = b.err;
		if (b.e2 > -b.dx)
		{
			b.err -= b.dy;
			m1.x += b.sx;
		}
		if (b.e2 < b.dy)
		{
			b.err += b.dx;
			m1.y += b.sy;
		}
	}
}
