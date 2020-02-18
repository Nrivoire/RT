/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/18 18:45:48 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/18 18:46:12 by nrivoire    ###    #+. /#+    ###.fr     */
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

int				main(int argc, char **argv)
{
	t_env	*v;

	//argc = 1;
	(void)argv;
	// argc < 2 || !ft_strcmp(argv[1], "--help") ? usage("") : 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	v->w = 1280;
	v->h = 720;
	v->fov = 60;
	
	//init list
	v->ob = NULL;
	v->lg = NULL;
	v->obj.x = 1;
	v->obj.y = 1;
	v->obj.z = 1;
	v->button_left = 0;

	/* -- a changer par les valeurs prises dans le parsing */
	v->p.ori.x = 0;
	v->p.ori.y = 0;
	v->p.ori.z = -50;

	check_options(v, argc, argv);
	parser_file(v);
	init_sdl(v);
	display(v);
	return (0);
}
