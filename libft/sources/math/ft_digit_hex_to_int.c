/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_hex_to_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:07:28 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:38:25 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_digit_hex_to_int(char c)
{
	if (c >= 'a')
		return (c - 'a' + 10);
	if (c >= 'A')
		return (c - 'A' + 10);
	return (c - '0');
}
