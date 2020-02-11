/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:50:24 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 15:51:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITEUR_H
# define EDITEUR_H

# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../SDL_include/SDL.h"
# include "../SDL_include/SDL_ttf.h"
# include "../SDL_include/SDL_image.h"

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

/*
** -----------------------------DRAWLINE---------------------------------
*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
	int				a;
}					t_rgb;

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
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --draw_tools--
*/
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_rgb color);
void				drawline(t_point m1, t_point m2, t_rgb color, t_env *v);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v);
int					key_event(const Uint8 *keyboard_state);

/*
** --draw_form--
*/
void				draw_void_circle(t_env *v, int x, int y, int radius);
void				draw_full_circle(t_env *v, int x, int y, int radius);
void				put_picture(t_env *v, t_start start, int size, SDL_Surface *sur);

#endif
