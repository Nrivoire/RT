/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2d_line_in_seg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:46:42 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:29:30 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	point_2d_line_in_seg(t_real p, t_2d_seg s)
{
	return (((p.x >= s.a.x && p.x <= s.b.x) 		\
				|| (p.x >= s.b.x && p.x <= s.a.x)) 	\
			&& ((p.y >= s.a.y && p.y <= s.b.y) 		\
				|| (p.y >= s.b.y && p.y <= s.a.y)));
}
