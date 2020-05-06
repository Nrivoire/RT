/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:18:29 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/17 17:33:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_menu(t_env *v, int scale)
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

static void		init_sdl(t_env *v)
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

t_tab_obj		make_tab_obj(t_lst_obj *p)
{
	t_tab_obj	data;

	data.type = p->type;
	data.radius = p->radius;
	data.pos = p->pos;
	data.dir = p->dir;
	data.a = p->a;
	data.b = p->b;
	data.c = p->c;
	data.color = p->color;
	data.reflect = p->reflect;
	data.refract = p->refract;
	data.shininess = p->shininess;
	return (data);
}

t_tab_lights		make_tab_lights(t_lst_lgt *p)
{
	t_tab_lights	light;

	light.pos = p->pos;
	light.color = p->color;
	return (light);
}

int		main(int ac, char **av)
{
	t_env		*v;
	t_lst_obj	*tmp;
	int			i;

	ac > 1 && !ft_strcmp(av[1], "--help") ? usage("", 0) : 0;
	ac == 1 ? usage("\033[31m\nYou can also use options.\033[0m", 1) : 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	init_value(v);
	check_options(v, ac, av);
	parser_file(v);
	scene_value(v);
	if (!(v->tab_obj = (t_tab_obj *)malloc(sizeof(t_tab_obj) * v->nb_o)))
		return (0);
	if (!(v->tab_lights = (t_tab_lights *)malloc(sizeof(t_tab_lights) * v->nb_l)))
		return (0);
	i = 0;
	tmp = v->p.ob;
	while (tmp)
	{
		v->tab_obj[i] = make_tab_obj(tmp);
		i++;
		tmp = tmp->next;
	}
	t_lst_lgt	*tmp2;
	i = 0;
	tmp2 = v->p.lg;
	while (tmp2)
	{
		v->tab_lights[i++] = make_tab_lights(tmp2);
		tmp2 = tmp2->next;
	}
	init_sdl(v);
	display(v);
	return (0);
}
