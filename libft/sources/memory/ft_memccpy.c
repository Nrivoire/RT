/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 18:31:34 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:38:00 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src++;
		if (*(unsigned char*)dst == (unsigned char)c)
			return ((unsigned char*)dst + 1);
		dst++;
	}
	return (NULL);
}
