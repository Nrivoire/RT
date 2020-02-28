/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/19 11:56:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/28 15:34:30 by nrivoire    ###    #+. /#+    ###.fr     */
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
	t_color			amb_light;
	float			intensity;
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
	float			intensity;
	struct s_light	*next;
}					t_light;

typedef struct		s_lst_obj
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
	SDL_Surface		*texture;

	struct s_lst_obj*next;
}					t_lst_obj;

typedef struct		s_parsing
{
	t_scene			sc;
	t_camera		cam;
	t_light			*lg;
	t_lst_obj		*ob;
	t_color			p_col;
	t_vec			p_xyz;
	t_vec			ori;
	int				prev_r;
	int				prev_g;
	int				prev_b;
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
	float			fov_x;
	float			fov_y;
	float			fov;
}					t_cam;

typedef struct		s_tab_obj
{
	int				i;
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
	SDL_Surface		*texture;
	t_quadric		q;
	t_vec			point;
	float			dist;
}					t_tab_obj;

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
	char			*file;
	t_parsing		p;
	int				nb_o;
	int				nb_l;
	t_tab_obj		*tab_obj;
	t_vec			light_ori;
	t_cam			cam;
	t_tab_obj		*selected_obj;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

void				display(t_env *v);
int					inter_ray_quadric(t_ray r, t_quadric q,
					t_sol_2_vec *sol);

/*
** --draw_tools--
*/
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_color color);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void        		mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v, uint32_t mouse_state);
void				mouse_wheel_event(SDL_Event e, t_env *v);
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
int					closest_intersect(t_env *v, t_ray ray, t_tab_obj *closest);
void				create_lgt(t_env *v);
void				create_tab_obj(t_env *v);
t_ray				create_ray_cam(t_env *v, int x, int y);
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
int					parse_int_value(char const *s);
void				parse_color(char *s, t_env *v, t_file *file);
void				parse_color_scene(char *s, t_env *v, t_file *file);
void				hexa_value(char *s, t_env *v, char delim, t_file *file);
void				parse_xyz(char *s, t_env *v, t_file *file);
void				add_lst_obj(t_lst_obj **ob, t_lst_obj content);
void				add_lst_lgt(t_light **lg, t_light content);
int					check_bracket(t_file *file);
int					read_line(t_file *file);
char				*my_strcat(char *s1, char *s2);
void				error_parser(char *error, t_file *file);

/*
** --init--
*/
void				init_value(t_env *v);
void				scene_value(t_env *v);
void				restart_values(t_env *v);

#endif
