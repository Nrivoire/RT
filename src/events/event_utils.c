/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:35:49 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/19 12:36:25 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				cooldown(t_env *v, int seconds)
{
	int		tmp;

	tmp = clock() / CLOCKS_PER_SEC;
	if (tmp - v->cooldown > seconds)
	{
		v->cooldown = clock() / CLOCKS_PER_SEC;
		return (1);
	}
	return (0);
}
