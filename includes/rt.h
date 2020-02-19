/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/19 11:56:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/19 14:43:01 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include "../SDL_include/SDL.h"
# include "../SDL_include/SDL_ttf.h"
# include "../SDL_include/SDL_image.h"
# include <stdio.h>

# define SPHERE 1
# define PLAN 2
# define CONE 3
# define CYLINDER 4

# define POINT 5
# define DIRECTIONAL 6
# define SPOT 7

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

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_scene
{
	float			amb_light;
	// add autre params
}					t_scene;

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			dir;
	int				fov;
}					t_camera;

typedef struct		s_light
{
	int				type;
	t_vec			pos;
	t_vec			dir;
	int				r;
	int				g;
	int				b;
	// add autre params
	float			intensity;
	struct s_light	*next;
}					t_light;

typedef struct		s_object
{
	int				type;
	float			radius;
	t_vec			pos;
	t_vec			dir;
	int				r;
	int				g;
	int				b;
	float			reflect;
	float			refract;
	float			transparency;
	float			absorbtion;
	float			ambient;
	float			diffuse;
	float			specular;
	float			shininess;
	int				texture;
	struct s_object	*next;
}					t_object;

typedef struct		s_file
{
	int				fd;
	char			*line;
}					t_file;

/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	Uint32			*pixels;
	int				w;
	int				h;
	int				fov;
	float			angle_ratio;
	t_vec			ori;
	char			*file;
	t_obj			obj;
	int				button_left;
	t_parsing		p;
	t_scene			sc;
	t_camera		cam;
	t_light			*lg;
	t_object		*ob;
	t_color			p_col;
	t_point			p_xyz;
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
void				put_picture(t_env *v, t_start start, int size,
					SDL_Surface *sur);

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
void				usage(char *error, int run);

/*
** --parser--
*/
int					parser_file(t_env *v);
void				parse_scene(t_env *v, t_file *file);
void				parse_cam(t_env *v, t_file *file);
void				parse_light(t_env *v, t_file *file);
void				parse_obj(t_env *v, t_file *file);
float				parse_value(char const *s);
char				*ft_strtok(char *s, char const *delim);
void				parse_color(char s[], t_env *v);
void				parse_xyz(char s[], t_env *v);
int					add_lst_obj(t_object **ob, t_object content);
int					add_lst_lgt(t_light **lg, t_light content);

#endif
