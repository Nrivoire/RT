/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 17:43:23 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:36:29 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!(new = (char*)malloc(sizeof(*new) * (len + 1))) || !s)
		return (NULL);
	ft_strncpy(new, (char *)s + start, len);
	new[len] = '\0';
	return (new);
}
