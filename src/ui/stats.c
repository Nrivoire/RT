#include "../includes/rt.h"

SDL_Surface		*write_text_stats(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/DS-DIGIT.TTF", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Shaded(font, text, (SDL_Color){255, 255, 255, 0},
		(SDL_Color){0, 0, 0, 255});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

void			put_text(t_env *v, SDL_Surface *sur, int s_x, int s_y)
{
	SDL_Color	col;
	int			x;
	int			y;

	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
		{
			SDL_GetRGBA(get_pixel(sur, x, y),
					sur->format, &col.r, &col.g, &col.b, &col.a);
			if (col.a != 0)
				pixel_put(v, x + s_x, y + s_y,
						(t_color){col.r, col.g, col.b, col.a});
		}
	}
	SDL_FreeSurface(sur);
}

void			display_stats(t_env *v)
{
	static char	*fps;
	static int	count = 0;
	char		*c_fps = ft_itoa(count);

	v->stats.current = clock();
	fps = NULL;
	if (v->stats.current - v->stats.last >= CLOCKS_PER_SEC)
	{
		v->stats.last = v->stats.current;
		fps == NULL ? fps = ft_strnew(10) : 0;
		count = v->stats.fps;
		v->stats.fps = 0;
	}
	put_text(v, write_text_stats(" fps: ", 18), 10, 10);
	put_text(v, write_text_stats(c_fps, 18), 50, 10);
	free(fps);
	free(c_fps);
}
