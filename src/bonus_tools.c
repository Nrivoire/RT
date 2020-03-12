/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:17:11 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/12 18:18:31 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
