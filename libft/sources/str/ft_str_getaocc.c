/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_getaocc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:59:25 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:34:28 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*str_getaocc(char *str, char c)
{
	unsigned int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (str + i + 1);
	}
	return (NULL);
}
