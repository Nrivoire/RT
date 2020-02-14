/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 19:04:28 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 19:04:29 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITEUR_H
# define EDITEUR_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../SDL_include/SDL.h"
# include "../SDL_include/SDL_ttf.h"
# include "../SDL_include/SDL_image.h"
#include "stdio.h"

typedef struct		s_start
{
	int				x;
	int				y;
}					t_start;

typedef struct		s_ray
{
	t_vec			ori;
	t_vec			dir;
}					t_ray;

typedef struct		s_quadratic
{
	float			a;
	float			b;
	float			c;
	float			d;
	float			e;
	float			f;
	float			g;
	float			h;
	float			i;
	float			j;
}					t_quadratic;

typedef struct		s_obj
{
	float			x;
	float			y;
	float			z;
}					t_obj;

typedef struct		s_parsing
{
	t_vec			ori;
}					t_parsing;

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
}					t_point;

/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_file
{
	int				fd;
	char			*line;
	int				i;
	int				arg;
}					t_file;

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
    Uint32			*pixels;
    int             w;
    int             h;
	int				fov;
	float			angle_ratio;
	t_vec			ori;
	char			*file;
	t_obj			obj;
	int				button_left;
	t_parsing		p;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

int					inter_line_quadratic(t_line l, t_quadratic q,
					t_sys_sol_1var_deg2 *result);

/*
** --draw_tools--
*/
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_rgb color);
void				put_picture(t_env *v, t_start start, int size, SDL_Surface *sur);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
int					key_event(t_env *v, const Uint8 *keyboard_state);

/*
** --form--
*/
t_quadratic			make_sphere(t_vec center, float radius);
t_quadratic			make_plan(t_point a, t_point b, t_point c);

/*
** --rays--
*/
void				bouclette(t_env *v);

/*
** --usage--
*/
void				check_options(t_env *v, int argc, char **argv);
void				usage(char *error);

#endif
