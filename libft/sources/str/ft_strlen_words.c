/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:39:27 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:27 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strlen_words(const char *s, char c)
{
	int	nb;

	nb = 0;
	while (*s)
		if (*s++ != c)
			nb++;
	return (nb);
}
