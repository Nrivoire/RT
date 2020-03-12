/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:39:13 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:50 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!len)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i--)
			((char*)dst)[i] = ((char*)src)[i];
		return (dst);
	}
	i = -1;
	while (++i < len)
		((char*)dst)[i] = ((char*)src)[i];
	return (dst);
}
