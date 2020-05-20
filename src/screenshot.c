/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:17:11 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/20 04:56:00 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Take a screenshot of the window.
*/

static void		save_screen(t_env *v, char *full)
{
	SDL_Surface	*save;

	if (!(save = malloc(sizeof(SDL_Surface *) * v->w * v->h + 1)))
		return ;
	save = SDL_GetWindowSurface(v->win);
	if (IMG_SavePNG(save, full) != 0)
		ft_putendl("Error : screenshot couldn't be saved.");
	SDL_FreeSurface(save);
}

void			screenshot(t_env *v, int id)
{
	char		*name;
	char		*full;
	char		*id_c;

	name = my_strcat("screenshot/sshot_", "1");
	full = my_strcat(name, ".png");
	while (access(full, F_OK) != -1)
	{
		free(name);
		free(full);
		id_c = ft_itoa(id++);
		name = my_strcat("screenshot/sshot_", id_c);
		full = my_strcat(name, ".png");
		free(id_c);
	}
	save_screen(v, full);
	free(full);
	free(name);
}
