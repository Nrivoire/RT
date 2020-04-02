/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:26:40 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:31:25 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int						ft_atoi(const char *str)
{
	int		i;
	long	t;
	int		s;

	i = 0;
	t = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		t = 10 * t + str[i++] - 48;
	if (t < 0 && s < 0)
		return (0);
	if (t < 0)
		return (-1);
	return (t * s);
}

unsigned long long		ft_atoull(const char *str)
{
	int		i;
	long	t;
	int		s;

	i = 0;
	t = 0;
	s = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		t = 10 * t + str[i++] - 48;
	if (t < 0 && s < 0)
		return (0);
	if (t < 0)
		return (-1);
	return (t * s);
}
