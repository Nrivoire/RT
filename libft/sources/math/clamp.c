/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:00:16 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:38:06 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fclamp(float *curr, float min, float max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}

void		iclamp(intmax_t *curr, int min, int max)
{
	if (*curr <= min)
		*curr = min;
	if (*curr >= max)
		*curr = max;
}
