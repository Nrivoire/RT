/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:52:08 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/21 18:52:14 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_clamp_to_max(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = max : 0;
	return (value);
}

void		parse_scene(t_env *v, t_file *file)
{
	char	*tmp;

	ft_strdel(&file->line);
	while (read_line(file) > 0 && ft_strncmp(file->line, "}", 1) != 0 &&\
			!check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		if (ft_strncmp(tmp, "\twidth=", 7))
			v->w = ft_clamp_to_max(parse_int_value(tmp), 100, 1280);
		else if (ft_strncmp(tmp, "\theight=", 8))
			v->h = ft_clamp_to_max(parse_int_value(tmp), 100, 720);
		else if (!ft_strncmp(tmp, "\tambient-light=", 15))
		{
			parse_color(tmp, v, file);
			v->p.sc.amb_light = (t_color){v->p.p_col.r, v->p.p_col.g, v->p.p_col.b, 255};
		}
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

void		parse_cam(t_env *v, t_file *file)
{
	char	*tmp;

	ft_strdel(&file->line);
	while (read_line(file) > 0 && ft_strncmp(file->line, "}", 1) != 0 &&\
			!check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\tpos=", 5))
		{
			parse_xyz(tmp, v);
			v->p.cam.pos = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
		}
		else if (!ft_strncmp(tmp, "\tdir=", 5))
		{
			parse_xyz(tmp, v);
			v->p.cam.dir = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
		}
		!ft_strncmp(tmp, "\tfov=", 5) ? v->p.cam.fov = parse_int_value(tmp) : 0;
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}
