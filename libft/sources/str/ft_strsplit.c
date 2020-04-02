/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:01:00 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:36:22 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	char	*new;

	if (!(s && (str = (char**)malloc(sizeof(*str) * 	\
						(ft_count_words((char*)s, c) + 1))) && c))
		return (NULL);
	new = ft_strctrim(s, c);
	ft_strtrimsplit(str, new, c);
	free(new);
	return (str);
}
