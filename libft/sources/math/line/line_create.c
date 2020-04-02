/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:32:35 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:40:29 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	line_create_points(t_vec p1, t_vec p2)
{
	t_vec	new;

	new = vec_sub(p2, p1);
	return ((t_line){(t_line_parameter){p1.x, new.x}, 	\
			(t_line_parameter){p1.y, new.y}, (t_line_parameter){p1.z, new.z}});
}

t_line	line_create_point_vec(t_vec o, t_vec u)
{
	return ((t_line){(t_line_parameter){o.x, u.x}, 		\
			(t_line_parameter){o.y, u.y}, (t_line_parameter){o.z, u.z}});
}
