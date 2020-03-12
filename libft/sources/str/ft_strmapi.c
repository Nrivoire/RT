/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:47:46 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:43 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	i = -1;
	if (!(s && f && (new = (char*)malloc(sizeof(*new) * 	\
						(ft_strlen(s) + 1)))))
		return (NULL);
	while (s[++i])
		new[i] = f(i, s[i]);
	new[i] = '\0';
	return (new);
}
