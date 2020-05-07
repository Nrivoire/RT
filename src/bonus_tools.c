/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:17:11 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/07 14:38:05 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Take a screenshot of the window.
*/

void			screenshot(t_env *v)
{
	int			id;
	char		*name;
	char		*open;
	SDL_Surface	*save;

	if (!(save = malloc(sizeof(SDL_Surface *) * v->w * v->h + 1)))
		return ;
	id = 1;
	name = my_strcat("screenshot/sshot_", ft_itoa(id));
	name = my_strcat(name, ".png");
	while (access(name, F_OK) != -1)
	{
		name = my_strcat("screenshot/sshot_", ft_itoa(id++));
		name = my_strcat(name, ".png");
	}
	save = SDL_GetWindowSurface(v->win);
	IMG_SavePNG(save, name);
	if (!system(open = my_strcat("open ", name)))
		ft_error("Command system : Fail to open file => Screenshot fail");
	SDL_FreeSurface(save);
	free(open);
}
