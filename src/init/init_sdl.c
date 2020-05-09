/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 14:51:14 by natachaNata       #+#    #+#             */
/*   Updated: 2020/05/07 14:51:42 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		init_sdl(t_env *v)
{
	int		scale;

	scale = (1920 - (v->w + v->ui.m_w)) / 2;
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(v->win = SDL_CreateWindow("rt", scale,
			SDL_WINDOWPOS_CENTERED, v->w, v->h, 0)))
		ft_error("Could not create the window");
	if (!(v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
	if (!(v->tex = SDL_CreateTexture(v->ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, v->w, v->h)))
		ft_error("Could not create a texture");
	if (!(v->pixels = malloc(sizeof(uint32_t) * (v->h * v->w))))
		ft_error("Pixels malloc error");
	init_menu(v, scale);
	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
}
