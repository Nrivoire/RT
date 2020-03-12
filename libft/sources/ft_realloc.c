/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:31:29 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:33:28 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *array, size_t new_size)
{
	char	*new_array;

	if (!new_size && array)
	{
		if (!(new_array = (char *)malloc(1)))
			return (NULL);
		ft_memdel(&array);
		return (new_array);
	}
	if (!(new_array = (char *)malloc(new_size)))
		return (NULL);
	if (array)
	{
		ft_memcpy(new_array, array, new_size);
		ft_memdel(&array);
	}
	return (new_array);
}
