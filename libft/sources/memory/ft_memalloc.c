/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 20:08:09 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:37:42 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = (void*)malloc(sizeof(*new) * size)))
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
