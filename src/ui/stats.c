/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:12:27 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/14 16:08:58 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			display_stats(t_env *v)
{
	static char	*fps;
	static int	count;
	char		*c_fps;

	count = 0;
	v->stats.current = clock();
	fps = NULL;
	if (v->stats.current - v->stats.last >= CLOCKS_PER_SEC)
	{
		v->stats.last = v->stats.current;
		fps == NULL ? fps = ft_strnew(10) : 0;
		count = v->stats.fps;
		v->stats.fps = 0;
	}
	c_fps = ft_itoa(count);
	put_text(v, write_text_stats("FPS:", 20), 10, 290);
	put_text(v, write_text_stats(c_fps, 20), 60, 290);
	free(fps);
	free(c_fps);
}
