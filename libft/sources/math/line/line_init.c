/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:41:03 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:40:24 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_line	line_init(void)
{
	return ((t_line){(t_line_parameter){0, 0}, (t_line_parameter){0, 0}, 	\
			(t_line_parameter){0, 0}});
}
