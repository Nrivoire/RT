/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_clamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/18 13:14:22 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Allows to bring a value between two lower and upper limits,
** and to assign the upper limit if the value exceeds.
*/

int		ft_clamp(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}

float	ft_clampf(float value, float min, float max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}
