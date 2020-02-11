/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:49:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 20:17:17 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

int        main(int argc, char **argv)
{
    t_env   *v;

    //argc < 2 && !ft_strcmp(argv[1], "--help") ? usage("") : 0;
    if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
    v->w = 1280;
    v->h = 720;
    v->file = NULL;
    //check_options(&v, argc, argv);
    argc = 1;
	(void)argv;
    return (0);
}
