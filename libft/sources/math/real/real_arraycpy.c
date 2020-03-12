/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_arraycpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:13:55 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:39:54 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	treal_arraycpy(t_real *src, t_real *dest, unsigned int nb)
{
	unsigned int	i;

	i = -1;
	while (++i < nb)
	{
		dest[i].x = src[i].x;
		dest[i].y = src[i].y;
	}
}
