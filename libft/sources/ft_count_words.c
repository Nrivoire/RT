/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:26:11 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:31:43 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_count_words(char *s, char c)
{
	int	j;
	int	nb;

	nb = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s++ != c)
			j++;
		if (j)
			nb++;
		while (*s == c)
			s++;
	}
	return (nb);
}
