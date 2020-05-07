/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:17:18 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/07 14:28:47 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_quadric		make_plan(t_vec a, t_vec b, t_vec c)
{
	t_quadric	res;
	t_vec		ab;
	t_vec		ac;
	t_vec		cross;

	ab = (t_vec){b.x - a.x, b.y - a.y, b.z - a.z};
	ac = (t_vec){c.x - a.x, c.y - a.y, c.z - a.z};
	cross = vec_cross_product(ab, ac);
	res.a = 0;
	res.b = 0;
	res.c = 0;
	res.d = 0;
	res.e = 0;
	res.f = 0;
	res.g = cross.x;
	res.h = cross.y;
	res.i = cross.z;
	res.j = -cross.x * a.x - cross.y * a.y - cross.z * a.z;
	return (res);
}
