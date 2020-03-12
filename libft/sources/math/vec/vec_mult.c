/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:53:38 by slopez            #+#    #+#             */
/*   Updated: 2020/03/12 19:39:01 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_mult_float(t_vec vec, float f)
{
	vec.x *= f;
	vec.y *= f;
	vec.z *= f;
	return (vec);
}
