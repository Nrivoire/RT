/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_occur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:56:08 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:33:23 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_occur(const char *str, const char c)
{
	int	nb;

	nb = 0;
	if (*str == c)
		nb++;
	while (*++str)
		if (*str == c)
			nb++;
	return (nb);
}
