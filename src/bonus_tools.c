#include "../includes/rt.h"

void			screenshot(t_env *v)
{
	long		id;
	char		*name;
	char		*open;
	SDL_Surface	*save;

	id = time(NULL);
	id = id - 1582900000;
	name = my_strcat("screenshot/sshot_", ft_itoa(id));
	name = my_strcat(name, ".png");
	save = SDL_GetWindowSurface(v->win);
	IMG_SavePNG(save, name);
	system(open = my_strcat("open ", name));
	SDL_FreeSurface(save);
	free(open);
}
