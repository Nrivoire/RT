/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:03:46 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/02 19:33:32 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

float			diffuse_light(t_env *v, t_tab_obj px, t_vec pos_light)
{
	float		dot;
	t_vec		norm;
	t_vec		light;

	norm = vec_normalize(vec_sub(px.pos, px.point));
	light = vec_normalize(vec_sub(px.point, pos_light));
	dot = vec_scale_product(light, norm);
	return (dot);
}

void			calc_light(t_env *v, t_tab_obj closest, t_color *px_color)
{
	t_lst_lgt	*tmp;
	float		dot_diffuse_light;

	dot_diffuse_light = 0;
	float intensity = 0;
	tmp = v->p.lg;
	while (tmp)
	{
		if ((dot_diffuse_light = diffuse_light(v, closest, tmp->pos)) > 0)
		{
			intensity = dot_diffuse_light * tmp->intensity;
			px_color->r += tmp->color.r * intensity;
			px_color->g += tmp->color.g * intensity;
			px_color->b += tmp->color.b * intensity;
		}
		tmp = tmp->next;
	}
	px_color->r = (px_color->r + v->p.sc.amb_light.r) * closest.color.r;
	px_color->g = (px_color->g + v->p.sc.amb_light.g) * closest.color.g;
	px_color->b = (px_color->b + v->p.sc.amb_light.b) * closest.color.b;
	if (v->selected_obj && v->selected_obj->i == closest.i)
	{
		px_color->r *= 2;
		px_color->g *= 1.5;
		px_color->b *= 2.5;
	}
}

void		    bouclette(t_env *v)
{
	int		    x;
	int		    y;
	t_ray	    ray;
	t_tab_obj	closest;
	t_color		px_color;

	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
			if (closest_intersect(v, ray, &closest))
			{
				px_color = (t_color) {0, 0, 0, 255};
				if (closest.texture)
					generate_texture(&closest);
				calc_light(v, closest, &px_color);
				pixel_put(v, x, y, px_color);
			}
		}
	}
}
