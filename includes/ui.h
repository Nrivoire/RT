#ifndef UI_H
# define UI_H

// typedef struct		s_ui
// {
// 	SDL_Window		*m_win;
// 	SDL_Renderer	*m_ren;
// 	SDL_Texture		*m_tex;
// 	Uint32			*m_pixels;
// 	int				m_w;
// 	int				m_h;
// }					t_ui;

/*
** --utils--
*/
SDL_Surface			*write_text_stats(char *text, int size_font);
SDL_Surface			*write_text_menu(char *text, int size_font);
SDL_Surface			*write_text_menu2(char *text, int size_font);

// void				put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y);
int					get_hex_menu(int r, int g, int b, int a);

#endif
