/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:09:10 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/18 16:09:14 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	parse_scene(t_env *v, t_file *file)
{
	char	*tmp;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0)
	{
		tmp = ft_strdup(file->line);
		!ft_strncmp(tmp, "\twidth=", 7) ? v->w = parse_value(tmp) : 0;
		!ft_strncmp(tmp, "\theight=", 8) ? v->h = parse_value(tmp) : 0;
		if (!ft_strncmp(tmp, "\tambient-light=", 15))
			v->sc.amb_light = parse_value(tmp);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

void	parse_cam(t_env *v, t_file *file)
{
	char	*tmp;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0)
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\tpos=", 5))
		{
			parse_xyz(tmp, v);
			v->cam.pos.x = v->p_xyz.x;
			v->cam.pos.y = v->p_xyz.y;
			v->cam.pos.z = v->p_xyz.z;
		}
		if (!ft_strncmp(tmp, "\tdir=", 5))
		{
			parse_xyz(tmp, v);
			v->cam.dir.x = v->p_xyz.x;
			v->cam.dir.y = v->p_xyz.y;
			v->cam.dir.z = v->p_xyz.z;
		}
		!ft_strncmp(tmp, "\tfov=", 5) ? v->cam.fov = parse_value(tmp) : 0;
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}
