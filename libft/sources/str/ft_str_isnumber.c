/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isnumber.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:55:44 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:34:32 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		str_isnumber(char *str)
{
	while (*str)
	{
		if (*str == '-' || *str == '.')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		str_isnumbern(char *str, int n)
{
	int		i;

	i = -1;
	while (*str && (++i < n))
	{
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
