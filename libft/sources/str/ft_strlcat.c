/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:25:33 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:17 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (dst[i] && i < size)
		i++;
	while (*src && i < (size - 1))
		dst[i++] = *src++;
	if (size >= dst_len)
		dst[i] = '\0';
	else
		return (src_len + size);
	return (src_len + dst_len);
}
