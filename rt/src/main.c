/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:49:55 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 17:56:49 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void        main(int argc, char **argv)
{
    t_env   *v;

    if (!(v = ft_memalloc(sizeof(t_env))))
		return (0);
    v->w = 1280;
    v->h = 720;
    argc = 1;
	(void)argv;
    return (0);
}