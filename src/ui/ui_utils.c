#include "../includes/rt.h"
#include "../includes/ui.h"

int		get_hex_menu(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

SDL_Surface		*write_text_menu2(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/OpenSans-Regular.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Blended(font, text, (SDL_Color){0, 0, 0, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

SDL_Surface		*write_text_menu(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/OpenSans-Bold.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Blended(font, text, (SDL_Color){0, 0, 0, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

SDL_Surface		*write_text_stats(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/OpenSans-Bold.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Solid(font, text, (SDL_Color){255, 255, 255, 0});
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
