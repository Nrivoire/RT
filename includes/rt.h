/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:56:50 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/07 18:48:08 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"

# define SPHERE 1
# define PLAN 2
# define CONE 3
# define CYLINDER 4

# define POINT 1
# define DIRECTIONAL 2
# define SPOT 3

# define CELSHADING 30

/*
** -----------------------------PARSING----------------------------
*/

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
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
	float			shininess;
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
	float			shininess;
	t_quadric		q;
	int				i;
}					t_tab_obj;

typedef struct		s_tab_lights
{
	t_vec			pos;
	t_color			color;
}					t_tab_lights;

typedef struct		s_between
{
	int				min_x;
	int				max_x;
	int				min_y;
	int				max_y;
}					t_between;

typedef struct		s_unit
{
	float			u;
	float			v;
}					t_unit;

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
	t_color			ssaa[5];
	t_color			blur[21];
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
	t_tab_lights	*tab_lights;
	t_vec			light_ori;
	t_cam			cam;
	t_tab_obj		*selected_obj;
	t_ppc			ppc;
	t_stats			stats;
	t_ui			ui;
	float			sc_m;
	Uint32			hover[4];
	int				reflect;
	int				print;
	int				thread_index;
	pthread_mutex_t	mutex;
	int				width_thread;
}					t_env;

/*
** ----------------------------------------------------------------------
*/

/*
** --init--
*/
void				init_value(t_env *v);
void				scene_value(t_env *v);
void				restart_values(t_env *v);
void				put_icon(t_env *v);
void				create_first_tab_obj(t_env *v);
void				create_first_tab_lgt(t_env *v);
void				init_sdl(t_env *v);
void				init_menu(t_env *v, int scale);

/*
** --quadric--
*/
t_vec				quadric_normal(t_quadric q, t_vec p);
int					inter_ray_quadric(t_ray r, t_quadric q, t_sol_2_vec *sol);
int					inter_seg_quadric(t_seg s, t_quadric q, t_sol_2_vec *sol);

/*
** --draw_tools--
*/
void				clear_pixels(t_env *v);
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
void				pixel_put(t_env *v, int x, int y, t_color color);
void				display(t_env *v);

/*
** --events--
*/
void				button_down(SDL_Event e, t_env *v);
void				mouse_button_event(SDL_Event event, t_env *v);
void				mouse_motion_event(SDL_Event event, t_env *v,
					uint32_t mouse_state);
void				mouse_wheel_event(SDL_Event e, t_env *v);
int					key_event(t_env *v, const Uint8 *keyboard_state);
void				obj_event(t_env *v, const Uint8 *keyboard_state,
		float scale);
void				plane_event(t_env *v, const Uint8 *keyboard_state,
		float scale);
t_vec				rot_axe_x(t_vec point, float angle, char dir);
t_vec				rot_axe_y(t_vec point, float angle, char dir);
t_vec				rot_axe_z(t_vec point, float angle, char dir);
void				plane_rotate(t_env *v, const Uint8 *keyboard_state);
void				render_obj(t_env *v, const Uint8 *keyboard_state);
void				render_plane(t_env *v, const Uint8 *keyboard_state);

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
void				make_tab_obj(t_env *v);
t_ray				create_ray(t_env *v, int x, int y);
void				multi_thread_with_loop(t_env *v);
int					select_obj(t_env *v, t_ray ray, t_tab_obj *obj,
		t_color *light);
t_color				ray_tracer(t_env *v, t_tab_obj *obj,
		t_vec point, t_vec ray);
t_color				color_ratio(t_color color, float ratio);
t_color				color_op(t_color c1, char op, t_color c2);
t_color				limit_color(t_color color);

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
void				check_points_and_type(t_lst_obj *content, t_file *file);

/*
** --post_process--
*/
int					cel_shading(int color);
int					negative(int color);
int					sepia(int color);
int					greyscale(int color);
void				supersampling(t_env *v);
void				blur(t_env *v);
int					blur_calc_r(t_env *v);
int					blur_calc_g(t_env *v);
int					blur_calc_b(t_env *v);
int					blur_calc_a(t_env *v);
t_color				color_ssp(Uint32 pixel);
int					get_hex(int r, int g, int b);

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
void				selected_pos(t_env *v);
void				selected_dir(t_env *v);
SDL_Surface			*write_text_stats(char *text, int size_font);
SDL_Surface			*write_text_menu(char *text, int size_font);
SDL_Surface			*write_text_menu2(char *text, int size_font);
int					get_hex_menu(int r, int g, int b);
void				put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y);
void				is_it_a_button(SDL_Event e);
void				over_a_button(t_env *v, SDL_Event e);

#endif
