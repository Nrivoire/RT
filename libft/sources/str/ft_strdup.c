/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 16:29:26 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:02 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!s1 || !(cpy = (char*)malloc(sizeof(*cpy) * (ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}
