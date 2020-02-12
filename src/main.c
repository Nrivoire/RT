/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:49:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:44:14 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		init_sdl(t_env *v)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(v->win = SDL_CreateWindow("editeur", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, v->w, v->h, 0)))
		ft_error("Could not create the window");
	if (!(v->ren = SDL_CreateRenderer(v->win, -1, SDL_RENDERER_SOFTWARE)))
		ft_error("Could not create a renderer");
	if (!(v->tex = SDL_CreateTexture(v->ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, v->w, v->h)))
		ft_error("Could not create a texture");
	if (!(v->pixels = malloc(sizeof(uint32_t) * (v->h * v->w))))
		ft_error("Pixels malloc error");
	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
}

int        main(int argc, char **argv)
{
    t_env   *v;

    argc = 1;
	(void)argv;
    if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
    v->w = 1280;
    v->h = 720;
	v->fov = 45;
	init_sdl(v);
	display(v);
    return (0);
}
