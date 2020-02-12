/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 15:57:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 18:35:53 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

t_ray		create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	rot;
	t_ray			ray;

	matrix_rotation((x - v->w * .5) * v->angle_ratio * M_PI / 180,
					(y - v->h * .5) * v->angle_ratio * M_PI / 180, 0, rot);
	ray.ori = (t_vec){0, 0, 0};
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	return (ray);
}

void		bouclette(t_env *v)
{
	int		x;
	int		y;
	t_ray	ray;

	v->angle_ratio = (float)v->fov / (float)v->w;
	// ray = create_ray(v, 0, 0);
	// printf("DemiDroite((%f, %f, %f),Vecteur((%f, %f, %f)))\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// ray = create_ray(v, 1280, 0);
	// printf("DemiDroite((%f, %f, %f),Vecteur((%f, %f, %f)))\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// ray = create_ray(v, 0, 720);
	// printf("DemiDroite((%f, %f, %f),Vecteur((%f, %f, %f)))\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// ray = create_ray(v, 1280, 720);
	// printf("DemiDroite((%f, %f, %f),Vecteur((%f, %f, %f)))\n\n", ray.ori.x, ray.ori.y, ray.ori.z, ray.dir.x, ray.dir.y, ray.dir.z);
	// return ;
	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
		{
			ray = create_ray(v, x, y);
		}
	}
}
