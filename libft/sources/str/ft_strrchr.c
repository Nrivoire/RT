/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 18:41:13 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:36:18 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	if (!c)
		return ((char*)s + ft_strlen(s));
	if (!*s)
		return (NULL);
	i = ft_strlen(s);
	while (s[--i] != c)
		if (!i)
			return (NULL);
	return ((char *)&s[i]);
}
