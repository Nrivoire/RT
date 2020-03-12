/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:19:37 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:35:32 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strmap_display(char *str, int l, int h)
{
	int i;
	int j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < l)
			ft_putchar(str[i * h + j]);
		write(1, "\n", 1);
	}
}
