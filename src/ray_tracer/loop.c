/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 17:47:32 by qpupier           #+#    #+#             */
/*   Updated: 2020/05/20 19:58:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		big_pixel(t_env *v, t_int c, int size, t_color color)
{
	int	i;
	int	j;

	j = -1;
	while (++j < size && (i = -1))
		while (++i < size)
			pixel_put(v, c.x + i, c.y + j, color);
}

void			calc_light(t_tab_obj obj, t_color light, t_color *px_color)
{
	px_color->r = light.r * obj.color.r;
	px_color->g = light.g * obj.color.g;
	px_color->b = light.b * obj.color.b;
}

static void		loop(t_env *v)
{
	int			x;
	int			y;
	t_tab_obj	obj;
	t_color		color;
	int			i;

	pthread_mutex_lock(&v->mutex);
	i = v->thread_index++;
	pthread_mutex_unlock(&v->mutex);
	y = -v->ppc.render_size;
	while ((y += v->ppc.render_size) <= v->h 	\
			&& (x = i * v->width_thread - v->ppc.render_size))
		while ((x += v->ppc.render_size) < ((i + 1) * v->width_thread))
		{
			color = (t_color){0, 0, 0};
			// v->reflect[y * v->w + x] = 1;
			if (select_obj(v, create_ray(v, x, y), &obj, &color))
			{
				color = limit_color(color);
				if (obj.texture)
					calc_light(obj, color, &color);
			}
			color = limit_color(color);
			if (v->ppc.render_size == 1)
				pixel_put(v, x, y, color);
			else
				big_pixel(v, (t_int){x, y}, v->ppc.render_size, color);
		}
	pthread_exit(NULL);
}

void			multi_thread_with_loop(t_env *v)
{
	pthread_t	id[8];
	int			i;

	i = -1;
	v->thread_index = 0;
	while (++i < 8)
		pthread_create(&id[i], NULL, (void*)loop, (void*)v);
	while (i--)
		pthread_join(id[i], NULL);
}
