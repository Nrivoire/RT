/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 15:41:49 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:34:53 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	nb;

	nb = 0;
	while (*s && ((ft_strchr(reject, *s++) == NULL)))
		nb++;
	return (nb);
}
