/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/19 11:56:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 18:13:34 by nrivoire    ###    #+. /#+    ###.fr     */
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

# define POINT 10
# define DIRECTIONAL 11
# define SPOT 12

/*
** -----------------------------PARSING----------------------------
*/

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
	int				a;
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
	t_color			color;
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
	t_vec			a;
	t_vec			b;
	t_vec			c;
	t_color			color;
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

typedef struct		s_parsing
{
	t_scene			sc;
	t_camera		cam;
	t_light			*lg;
	t_object		*ob;
	t_color			p_col;
	t_vec			p_xyz;
	t_vec			ori;
}					t_parsing;

typedef struct		s_file
{
	int				fd;
	char			*line;
	int				nb_line;
}					t_file;

/*
** -----------------------------EVERYTHING-ELSE----------------------------
*/

typedef struct		s_quadric
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
}					t_quadric;

typedef struct		s_obj
{
	float			x;
	float			y;
	float			z;
}					t_obj;

typedef struct		s_tab
{
	t_quadric		q;
	t_color			color;
}					t_tab;

typedef struct		s_sol_2_vec
{
	int				s1;
	int				s2;
	t_vec			v1;
	t_vec			v2;
}					t_sol_2_vec;

typedef struct		s_cam
{
	float			angle_x;
	float			angle_y;
	t_vec			ori;
	t_vec			dir;
}					t_cam;

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
	char			*file;
	t_obj			obj;
	t_parsing		p;
	int				nb_o;
	int				nb_l;
	t_tab			*tab;
	float			intens;
	t_vec			light_ori;
	t_cam			cam;
	t_tab			selected_obj;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

int					inter_ray_quadric(t_ray r, t_quadric q,
					t_sol_2_vec *sol);

/*
** --draw_tools--
*/
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_rgb color);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v, uint32_t mouse_state);
int					key_event(t_env *v, const Uint8 *keyboard_state);

/*
** --form--
*/
t_quadric			make_sphere(t_vec center, float radius);
t_quadric			make_plan(t_vec a, t_vec b, t_vec c);
t_quadric			make_cylinder(t_vec a, t_vec v, float r);
t_quadric			make_cone(t_vec a, t_vec v, float alpha);

/*
** --rays--
*/
void				create_lgt(t_env *v);
t_tab				*create_obj(t_env *v);
void				bouclette(t_env *v, t_tab *tab_obj);

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
int					parse_int_value(char const *s);
char				*ft_strtok(char *s, char const *delim);
void				parse_color(char s[], t_env *v);
void				parse_xyz(char s[], t_env *v);
void				add_lst_obj(t_object **ob, t_object content);
void				add_lst_lgt(t_light **lg, t_light content);
int					check_bracket(t_file *file);
int					read_line(t_file *file);

/*
** --init--
*/
void				init_value(t_env *v);
void				scene_value(t_env *v);
void				restart_values(t_env *v);

#endif
