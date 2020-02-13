/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/12 14:02:00 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 14:00:09 by nrivoire    ###    #+. /#+    ###.fr     */
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

typedef struct		s_draw_circle
{
	int				x;
	int				y;
}					t_draw_circle;

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

/*
** -----------------------------DRAWLINE---------------------------------
*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_bressen
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bressen;

/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	t_draw_circle	center;
    Uint32			*pixels;
    int             w;
    int             h;
	int				fov;
	float			angle_ratio;
	t_vec			ori;
	char			*file;
	float			obj_x;
	float			obj_y;
	float			obj_z;
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
void				draw_void_circle(t_env *v, int x, int y, int radius);
void				draw_full_circle(t_env *v, int x, int y, int radius);
void				put_picture(t_env *v, t_start start, int size, SDL_Surface *sur);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
int					key_event(t_env *v, const Uint8 *keyboard_state);

/*
** --rays--
*/
void				bouclette(t_env *v);

#endif
