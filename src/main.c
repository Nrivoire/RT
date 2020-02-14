/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 14:00:44 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 17:11:44 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		init_sdl(t_env *v)
{
	if (SDL_Init(SDL_INIT_VIDEO))
		ft_error("Couldn't initialize SDL");
	if (!(v->win = SDL_CreateWindow("rt", SDL_WINDOWPOS_UNDEFINED,
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

    //argc = 1;
	(void)argv;
	//argc < 2 || !ft_strcmp(argv[1], "--help") ? usage("") : 0;
    if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
    v->w = 1280;
    v->h = 720;
	v->fov = 60;
	v->obj_x = 0;
	v->obj_y = 0;
	v->obj_z = 0;
	check_options(v, argc, argv);
	init_sdl(v);
	display(v);
    v->file = NULL;
    return (0);
}
