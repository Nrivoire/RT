/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:54:55 by slopez            #+#    #+#             */
/*   Updated: 2020/04/12 21:29:29 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			ft_atof(const char *str)
{
	float	res;
	char	*c;

	c = (char *)str;
	while (*c && *c != '.')
		c++;
	*c == '.' ? c++ : 0;
	res = (float)ft_atoi(c) / pow(10, ft_strlen(c));
	return ((float)ft_atoi(str) + ((*str == '-') ? -res : res));
}
