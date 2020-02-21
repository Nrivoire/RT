/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/18 18:18:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/21 14:08:42 by nrivoire    ###    #+. /#+    ###.fr     */
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

static void		init_value(t_env *v)
{
	v->w = 1280;
	v->h = 720;
	v->fov = 60;
	
	// init list du parser pour le malloc
	v->p.ob = NULL;
	v->p.lg = NULL;
}

int				main(int argc, char **argv)
{
	t_env	*v;

	// argc < 2 || !ft_strcmp(argv[1], "--help") ? usage("", 0) : 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	argc < 2 ? v->file = ft_strdup("./scenes/default.rt") : 0; // CONDITION A SUPPRIMER A L'AVENIR POUR LA REMPLACER PAR CELLE EN COMMENTAIRE AU DESSUS
	init_value(v);

	v->obj.x = 0;
	v->obj.y = 0;
	v->obj.z = 0;
	v->cam_angle_x = 0;
	v->cam_angle_y = 0;
	v->angle_ratio = (v->fov / (float)v->w) * M_PI / 180;
	v->dist.s1 = 0;
	v->dist.s2 = 0;
	v->dist.min = 0;

	/* -- a changer par les valeurs prises dans le parsing */
	v->p.ori.x = 0;
	v->p.ori.y = 0;
	v->p.ori.z = -20;
	v->cam_ori = v->p.ori;

	check_options(v, argc, argv);
	parser_file(v);
	if (!(v->tab = (t_tab *)malloc(sizeof(t_tab) * v->nb_o)))
		return (0);
	init_sdl(v);
	display(v);
	return (0);
}
