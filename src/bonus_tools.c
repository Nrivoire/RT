#include "../includes/rt.h"

void			screenshot(t_env *v)
{
	long		id;
	char		*name;
	char		*open;
	SDL_Surface	*save;

	if (v->p.sc.filter == 0)
	{
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
	else
		ft_putendl("Screenshot only without filter");
}
//PERMETTRE LE SCREENSHOT AVEC FILTER A L'AVENIR