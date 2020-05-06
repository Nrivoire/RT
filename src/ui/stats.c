/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:12:27 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/06 18:14:12 by jacket           ###   ########lyon.fr   */
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
	put_text(v, write_text_stats("NewFPS:", 20), 10, 290);
	put_text(v, write_text_stats(c_fps, 20), 90, 290);
	free(fps);
	free(c_fps);
}
