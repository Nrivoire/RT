/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:12:27 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:15:17 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			display_stats(t_env *v)
{
	static char	*fps;
	static int	count = 0;
	char		*c_fps;

	v->stats.current = clock();
	fps = NULL;
	c_fps = ft_itoa(count);
	if (v->stats.current - v->stats.last >= CLOCKS_PER_SEC)
	{
		v->stats.last = v->stats.current;
		fps == NULL ? fps = ft_strnew(10) : 0;
		count = v->stats.fps;
		v->stats.fps = 0;
	}
	put_text(v, write_text_menu(" FPS:       ", 18), 30, 70);
	put_text(v, write_text_menu(c_fps, 18), 80, 70);
	free(fps);
	free(c_fps);
}
