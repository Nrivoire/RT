/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:52:42 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:55:04 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_menu(t_env *v, int scale)
{
	if (!(v->ui.m_win = SDL_CreateWindow("menu", v->w + scale,
			SDL_WINDOWPOS_CENTERED, v->ui.m_w, v->ui.m_h, 0)))
		ft_error("Could not create the window");
	if (!(v->ui.m_ren = SDL_CreateRenderer(v->ui.m_win, -1, \
						SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
	if (!(v->ui.m_tex = SDL_CreateTexture(v->ui.m_ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, v->ui.m_w, v->ui.m_h)))
		ft_error("Could not create a texture");
	if (!(v->ui.m_pixels = malloc(sizeof(uint32_t) * (v->ui.m_h * v->ui.m_w))))
		ft_error("Pixels malloc error");
}
