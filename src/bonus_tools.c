#include "../includes/rt.h"

/*
** Take a screenshot of the window.
*/

void			screenshot(t_env *v)
{
	long		id;
	char		*name;
	char		*open;
	SDL_Surface	*save;

	if (!(save = malloc(sizeof(SDL_Surface *) * v->w * v->h + 1)))
		return ;
	id = time(NULL);
	id = id - 1583000000;
	name = my_strcat("screenshot/sshot_", ft_itoa(id));
	name = my_strcat(name, ".png");
	save = SDL_GetWindowSurface(v->win);
	IMG_SavePNG(save, name);
	system(open = my_strcat("open ", name));
	SDL_FreeSurface(save);
	free(open);
}

/*
** 
*/

/*
void			music(t_env *v)
{
	Mix_Chunk		*son;

	Mix_AllocateChannels(2);
	Mix_Volume(1, MIX_MAX_VOLUME/2);
	son = Mix_LoadWAV("star_wars_imperial_march.wav");
	Mix_VolumeChunk(son, MIX_MAX_VOLUME/2);
	Mix_PlayChannel(1, son, 0);
	Mix_FreeChunk(son);
}*/