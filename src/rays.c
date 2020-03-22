/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 19:03:46 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 19:54:54 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray				create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	cam;
	t_ray			ray;

	ray.o = v->cam.ori;
	ray.d.x = v->cam.fov_x * (2. * x / v->w - 1);
	ray.d.y = v->cam.fov_y * (2. * y / v->h - 1);
	ray.d.z = -1;
	matrix_rotation(v->cam.angle_x, v->cam.angle_y, 0, cam);
	ray.d = matrix_mult_vec(cam, ray.d);
	ray.o = matrix_mult_vec(cam, v->cam.ori);
	return (ray);
}

static void			big_pixel(t_env *v, int x, int y, t_color px_color)
{
	pixel_put(v, x, y, px_color);
	pixel_put(v, x, y + 1, px_color);
	pixel_put(v, x, y + 2, px_color);
	pixel_put(v, x, y + 3, px_color);
	pixel_put(v, x + 1, y, px_color);
	pixel_put(v, x + 2, y, px_color);
	pixel_put(v, x + 3, y, px_color);
	pixel_put(v, x + 1, y + 1, px_color);
	pixel_put(v, x + 2, y + 1, px_color);
	pixel_put(v, x + 3, y + 1, px_color);
	pixel_put(v, x + 1, y + 2, px_color);
	pixel_put(v, x + 2, y + 2, px_color);
	pixel_put(v, x + 3, y + 2, px_color);
	pixel_put(v, x + 1, y + 3, px_color);
	pixel_put(v, x + 2, y + 3, px_color);
	pixel_put(v, x + 3, y + 3, px_color);
}

void				bouclette(t_env *v)
{
	int				x;
	int				y;
	t_ray			ray;
	t_tab_obj		closest;
	t_color			px_color;

	y = 0;
	while (y <= v->h)
	{
		x = 0;
		while (x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (closest_intersect(v, ray, &closest))
			{
				px_color = (t_color) {0, 0, 0, 255};
				if (closest.texture)
					generate_texture(&closest);
				if (closest.procedural)
					create_texture_procedural(&closest);
				calc_light(v, closest, &px_color);
				if (v->ppc.render_size == 1)
					pixel_put(v, x, y, px_color);
				else if (v->ppc.render_size == 4)
					big_pixel(v, x, y, px_color);
			}
			x = x + v->ppc.render_size;
		}
		y = y + v->ppc.render_size;
	}
	v->stats.fps++;
}
