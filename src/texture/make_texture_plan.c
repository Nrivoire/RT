/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texture_plan.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:17:20 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/21 06:11:16 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				resolv_equation(t_vec u, t_vec v, t_vec vp,
	t_sys_sol_2var_deg1 *res)
{
	t_equ_2var_deg1		equ1;
	t_equ_2var_deg1		equ2;

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
	if (!sys_solve_2equ_2var_deg1(equ1, equ2, res))
		return (0);
	return (1);
}

void			make_texture_plan(t_tab_obj *obj, t_vec point)
{
	SDL_Color			col;
	t_vec				u;
	t_vec				v;
	t_vec				vp;
	t_sys_sol_2var_deg1	res;

	col = (SDL_Color){0, 0, 0, 255};
	u = vec_sub(obj->b, obj->a);
	v = vec_sub(obj->c, obj->a);
	vp = vec_sub(point, obj->a);
	resolv_equation(u, v, vp, &res);
	SDL_GetRGB(get_pixel(obj->texture,
		(int)(fabs(res.x) * obj->texture->w) % obj->texture->w,
		(int)(fabs(res.y) * obj->texture->h) % obj->texture->h),
		obj->texture->format, &col.r, &col.g, &col.b);
	obj->color = (t_color){col.r / 255.0, col.g / 255.0, col.b / 255.0};
}
