/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_array_cpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:06:31 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:39:24 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			tvec_array_cpy(t_vec *in, t_vec *out, unsigned int nb)
{
	unsigned int	i;

	i = -1;
	while (++i < nb)
		out[i] = in[i];
}
