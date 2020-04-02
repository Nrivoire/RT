/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:14:14 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:34:56 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == c)
		i++;
	while (s[j] == c)
		j--;
	if (i > j)
		return ((ft_strdup("")));
	if (!(new = (char*)malloc(sizeof(*new) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		new[k++] = s[i++];
	new[k] = '\0';
	return (new);
}
