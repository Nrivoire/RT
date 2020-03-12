/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:56:50 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/11 19:10:34 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
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
# include "../SDL_include/SDL_mixer.h"
# include <stdio.h>

# define SPHERE 1
# define PLAN 2
# define CONE 3
# define CYLINDER 4

# define POINT 10
# define DIRECTIONAL 11
# define SPOT 12

# define PERLIN 1
# define WOOD 2
# define MARBLE 3

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
	int				filter;
}					t_scene;

typedef struct		s_camera
{
	t_vec			pos;
	t_vec			dir;
	int				fov;
}					t_camera;

typedef struct		s_lst_lgt
{
	int				type;
	t_vec			pos;
	t_vec			dir;
	t_color			color;
	float			intensity;
	struct s_lst_lgt*next;
}					t_lst_lgt;

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
	int				procedural;
	SDL_Surface		*texture;
	struct s_lst_obj*next;
}					t_lst_obj;

typedef struct		s_parsing
{
	t_scene			sc;
	t_camera		cam;
	t_lst_lgt		*lg;
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
	short			type;
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
	int				procedural;
	SDL_Surface		*texture;
	t_quadric		q;
	t_vec			point;
	float			dist;
	t_vec			normale;
}					t_tab_obj;

typedef struct		s_mapping
{
	double			start1;
	double			stop1;
	double			start2;
	double			stop2;
}					t_mapping;

/*
** -----------------------------POST-PROCESS----------------------------
*/

typedef struct		s_ppc
{
	int				render_key;
	int				render_mouse;
	int				active_rpx;
	int				render_size;
	int				ssp;
}					t_ppc;

typedef struct		s_stats
{
	clock_t			current;
	clock_t			last;
	clock_t			frame_start;
	double			frame;
	int				fps;
}					t_stats;

/*
** ---------------------------------PERLIN--------------------------------
*/

typedef struct		s_noise
{
	int				xi;
	int				yi;
	int				zi;
	float			u;
	float			v;
	float			w;
}					t_noise;

/*
** -----------------------------ENVIRONNEMENT----------------------------
*/

typedef struct		s_ui
{
	SDL_Window		*m_win;
	SDL_Renderer	*m_ren;
	SDL_Texture		*m_tex;
	Uint32			*m_pixels;
	int				m_w;
	int				m_h;
}					t_ui;

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
	t_ppc			ppc;
	t_stats			stats;
	t_ui			ui;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

void				display(t_env *v);
t_vec				quadric_normal(t_quadric q, t_vec p, t_vec r);
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
void				mouse_button_event(SDL_Event event, t_env *v);
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
** --textures--
*/
void				generate_texture(t_tab_obj *closest);
void				make_texture_sphere(t_tab_obj *obj);
void				make_texture_plan(t_tab_obj *obj);
void            	make_texture_cone(t_tab_obj *obj);
void    	        make_texture_cylindre(t_tab_obj *obj);

/*
** --procedural_textures--
*/
float				noise(float x, float y, float z);
void				create_texture_procedural(t_tab_obj *obj);

/*
** --rays--
*/
int					closest_intersect(t_env *v, t_ray ray, t_tab_obj *closest);
void				create_tab_obj(t_env *v);
t_ray				create_ray(t_env *v, int x, int y);
void				bouclette(t_env *v);
void				bouclette_event(t_env *v);

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
void				init_value_obj(t_lst_obj *content);
void				init_value_light(t_lst_lgt *content);
float				parse_value(char const *s);
int					parse_int_value(char const *s);
void				parse_color(char *s, t_env *v, t_file *file);
void				parse_color_scene(char *s, t_env *v, t_file *file);
void				hexa_value(char *s, t_env *v, char delim, t_file *file);
void				parse_xyz(char *s, t_env *v, t_file *file);
void				add_lst_obj(t_lst_obj **ob, t_lst_obj content);
void				add_lst_lgt(t_lst_lgt **lg, t_lst_lgt content);
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
void				put_icon(t_env *v);

/*
** --post_process--
*/
int					cel_shading(int color);
int					negative(int color);
int					sepia(int color);
int					greyscale(int color);
void				supersampling(t_env *v);

/*
** --bonus_tools--
*/
void				screenshot(t_env *v);
void				display_stats(t_env *v);


/*
** --menu--
*/
void				menu(t_env *v);
void				load_menu(t_env *v);
void				menu_bouton(t_env *v, int x, int y);
void				menu_bouton_text(t_env *v);
void				selected_sphere(t_env *v);
void				selected_plan(t_env *v);
void				selected_cone(t_env *v);
void				selected_cylinder(t_env *v);
SDL_Surface			*write_text_stats(char *text, int size_font);
SDL_Surface			*write_text_menu(char *text, int size_font);
SDL_Surface			*write_text_menu2(char *text, int size_font);
int					get_hex_menu(int r, int g, int b, int a);
void				put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y);

#endif
