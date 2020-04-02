/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 17:19:01 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:46 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2 && n--)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
