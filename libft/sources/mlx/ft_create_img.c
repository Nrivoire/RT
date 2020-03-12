/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:57:48 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:36:43 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_create_img(void *ptr, t_mlx_img *img, int w, int h)
{
	img->ptr = mlx_new_image(ptr, w, h);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_l, &img->endian);
	img->width = w;
	img->height = h;
}
