/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 15:57:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:51:16 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

typedef float       t_matrix_3_3[3][3];

void	matrix_rotation_x(float angle, t_matrix_3_3 matrix)
{
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(angle);
	matrix[1][2] = -sin(angle);
	matrix[2][0] = 0;
	matrix[2][1] = sin(angle);
	matrix[2][2] = cos(angle);
}

void	matrix_rotation_y(float angle, t_matrix_3_3 matrix)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = 0;
	matrix[0][2] = sin(angle);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(angle);
	matrix[2][1] = 0;
	matrix[2][2] = cos(angle);
}

void	matrix_rotation_z(float angle, t_matrix_3_3 matrix)
{
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

void	matrix_mult_matrix(t_matrix_3_3 m1, t_matrix_3_3 m2, t_matrix_3_3 r)
{
	r[0][0] = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0] + m1[0][2] * m2[2][0];
	r[0][1] = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1] + m1[0][2] * m2[2][1];
	r[0][2] = m1[0][0] * m2[0][2] + m1[0][1] * m2[1][2] + m1[0][2] * m2[2][2];
	r[1][0] = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0] + m1[1][2] * m2[2][0];
	r[1][1] = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1] + m1[1][2] * m2[2][1];
	r[1][2] = m1[1][0] * m2[0][2] + m1[1][1] * m2[1][2] + m1[1][2] * m2[2][2];
	r[2][0] = m1[2][0] * m2[0][0] + m1[2][1] * m2[1][0] + m1[2][2] * m2[2][0];
	r[2][1] = m1[2][0] * m2[0][1] + m1[2][1] * m2[1][1] + m1[2][2] * m2[2][1];
	r[2][2] = m1[2][0] * m2[0][2] + m1[2][1] * m2[1][2] + m1[2][2] * m2[2][2];
}

void	matrix_rotation(float theta_x, float theta_y, float theta_z, 	\
		t_matrix_3_3 rot)
{
	t_matrix_3_3	x;
	t_matrix_3_3	y;
	t_matrix_3_3	z;
	t_matrix_3_3	xy;

	matrix_rotation_x(theta_x, x);
	matrix_rotation_y(theta_y, y);
	matrix_rotation_z(theta_z, z);
	matrix_mult_matrix(x, y, xy);
	matrix_mult_matrix(xy, z, rot);
}

t_vec	matrix_mult_vec(t_matrix_3_3 mat, t_vec v)
{
	return ((t_vec){mat[0][0] * v.x + mat[0][1] * v.y + mat[0][2] * v.z, 	\
			mat[1][0] * v.x + mat[1][1] * v.y + mat[1][2] * v.z, 			\
			mat[2][0] * v.x + mat[2][1] * v.y + mat[2][2] * v.z});
}

t_ray		create_ray(t_env *v, int x, int y)
{
	t_matrix_3_3	rot;
	t_ray			ray;

	v->angle_ratio = v->fov / v->w;
	matrix_rotation((x - v->w * .5) * v->angle_ratio * M_PI / 180,
					(y - v->h * .5) * v->angle_ratio * M_PI / 180, 0, rot);
	ray.dir = matrix_mult_vec(rot, (t_vec){0, 0, 1});
	return (ray);
}

void		bouclette(t_env *v)
{
	int		x;
	int		y;
	t_ray	ray;

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
