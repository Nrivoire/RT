/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/18 18:18:29 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 10:39:34 by nrivoire    ###    #+. /#+    ###.fr     */
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
	data.transparency = p->transparency;
	data.absorbtion = p->absorbtion;
	data.ambient = p->ambient;
	data.diffuse = p->diffuse;
	data.specular = p->specular;
	data.shininess = p->shininess;
	data.texture = p->texture;
	return (data);
}

int				main(int argc, char **argv)
{
	t_env	*v;


// GtkWidget *window;
// GtkWidget *button;
// gtk_init(&argc, &argv);
// window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
// button = gtk_button_new_with_label
//    ("Click Me!");
// gtk_widget_show_all(window);
// gtk_main();
// return (0);
	argc < 2 || !ft_strcmp(argv[1], "--help") ? usage("", 0) : 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	init_value(v);
	check_options(v, argc, argv);
	parser_file(v);
	scene_value(v);
	v->cam.angle_x = 0;
	v->cam.angle_y = 0;
	v->cam.fov_x = tan(v->cam.fov * M_PI / 180 * 0.5);
	v->cam.fov_y = -tan(v->h * v->cam.fov / v->w * M_PI / 180 * 0.5);
	if (!(v->tab_obj = (t_tab_obj *)malloc(sizeof(t_tab_obj) * v->nb_o)))
		return (0);
	t_lst_obj	*tmp;
	int			i = 0;
	tmp = v->p.ob;
	while (tmp)
	{
		v->tab_obj[i] = make_tab_obj(tmp);
		i++;
		tmp = tmp->next;
	}
	init_sdl(v);
	display(v);
	return (0);
}
