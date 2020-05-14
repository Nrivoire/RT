/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:18:29 by nrivoire          #+#    #+#             */
/*   Updated: 2020/05/14 14:59:51 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int				main(int ac, char **av)
{
	t_env		*v;

	ac > 1 && !ft_strcmp(av[1], "--help") ? usage("", 0) : 0;
	ac == 1 ? usage("\033[31m\nYou can also use options.\033[0m", 1) : 0;
	if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
	init_value(v);
	check_options(v, ac, av);
	parser_file(v);
	scene_value(v);
	create_first_tab_obj(v);
	create_first_tab_lgt(v);
	init_sdl(v);
	display(v);
	return (0);
}
