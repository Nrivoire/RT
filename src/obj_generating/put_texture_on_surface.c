/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_texture_on_surface.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/03/02 19:11:49 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 13:35:48 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

float			dot_product(t_vec u, t_vec v)
{
	float		dot;
	float		magnitude;
	float		dot_product;

	dot = u.x * v.x + u.y * v.y + u.z * v.z;
	magnitude = sqrt(u.x * u.x + u.y * u.y + u.z * u.z) *
			sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	dot_product = dot / magnitude;
	return (dot_product);
}

void			make_texture_plan(t_tab_obj *obj)
{
	SDL_Color col = (SDL_Color){0, 0, 0, 255};
	t_vec		u;
	t_vec		v;
	t_vec		vp;
	t_equ_2var_deg1		equ1;
    t_equ_2var_deg1		equ2;
	t_sys_sol_2var_deg1     res;

	u = vec_sub(obj->b, obj->a);
	v = vec_sub(obj->c, obj->a);
	vp = vec_sub(obj->point, obj->a);
	equ1 = (t_equ_2var_deg1)
    {
        .a_x = vec_scale_product(u, u),
        .a_y = vec_scale_product(u, v),
        .b = -vec_scale_product(vp, u)
    };
    equ2 = (t_equ_2var_deg1)
    {
        .a_x = vec_scale_product(u, v),
        .a_y = vec_scale_product(v, v),
        .b = -vec_scale_product(vp, v)
    };
	if (!sys_solve_2equ_2var_deg1(equ1, equ2, &res))
        return ;
	SDL_GetRGB(get_pixel(obj->texture, (int)(fabs(res.x) * obj->texture->w) % obj->texture->w, (int)(fabs(res.y) * obj->texture->h) % obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
	obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0, 255};
}

void			make_texture_sphere(t_tab_obj *obj)
{
	t_vec	vn;
	t_vec	ve;
	float	phi;
	float	theta;
	float	u;
	float	v;
	float	precision;
	SDL_Color col = (SDL_Color){0, 0, 0, 255};

	vn = (t_vec){0, 1, 0};
	ve = (t_vec){1, 0, 0};
	phi = acos(dot_product(vn, obj->normale));
	v = phi / M_PI;
	precision = dot_product(obj->normale, ve) / sin(phi);
	if (precision <= -1)
		precision = -1.0f;
	if (precision >= 1)
		precision = 1.0f;
	theta = acos(precision) / (2 * M_PI);
	if (dot_product(vec_cross_product(vn, ve), obj->normale) > 0)
		u = theta;
	else
		u = 1 - theta;
	// t_vec		vp;
	// float		u;
	// float		v;

	// vp = vec_normalize(vec_sub(obj->point, obj->pos));
	// u = .5 + atan2(vp.z, vp.x) / M_PI * 0.5;
	// v = .5 - asin(vp.y) / M_PI;
	if (u >= 0 && v >= 0 && u <= 1 && v <= 1)
	{
		SDL_GetRGB(get_pixel(obj->texture, u * obj->texture->w, v * obj->texture->h), obj->texture->format, &col.r, &col.g, &col.b);
		obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0, 255};
	}
}

void            make_texture_cylinder(t_tab_obj *obj)
{
	t_real		rx;
	t_real		ry;
	t_real		rz;
	t_vec		dir_norm;

	dir_norm = vec_normalize(obj->dir);
	rx = (t_real){dir_norm.y, dir_norm.z};
	ry = (t_real){dir_norm.x, dir_norm.z};
	rz = (t_real){dir_norm.x, dir_norm.y};
	t_vec point = (t_vec){0,1,0};
	float ax = real_oriented_angle((t_real){point.y, point.z}, rx);
	float ay = real_oriented_angle((t_real){point.x, point.z}, ry);
	float az = real_oriented_angle((t_real){point.x, point.y}, rz);
	t_matrix_3_3 rot;
	matrix_rotation(ax, ay, az, rot);
	t_vec ref = matrix_mult_vec(rot, (t_vec){1,0,0});
	//printf("%f %f %f\n", ref.x, ref.y, ref.z);
}

void            make_texture_cone(t_tab_obj *obj)
{
    
}

void			generate_texture(t_tab_obj *closest)
{
	if (closest->type == SPHERE)
		make_texture_sphere(closest);
	if (closest->type == CYLINDER)
		make_texture_cylinder(&closest);
	if (closest->type == PLAN)
		make_texture_plan(closest);
	//if (closest->type == CONE)
	//	make_texture_cone(closest);
}
