/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:10:09 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/18 16:10:14 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		parse_material_lgt(t_env *v, char *tmp, t_light content)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v);
		content.r = v->p.p_col.r;
		content.g = v->p.p_col.g;
		content.b = v->p.p_col.b;
	}
	if (!ft_strncmp(tmp, "\tintensity=", 11))
		content.intensity = parse_value(tmp);
}

static void		parse_xyz_lgt(t_env *v, char *tmp, t_light content)
{
	if (!ft_strncmp(tmp, "\tpos=", 5))
	{
		parse_xyz(tmp, v);
		content.pos.x = v->p.p_xyz.x;
		content.pos.y = v->p.p_xyz.y;
		content.pos.z = v->p.p_xyz.z;
	}
	if (!ft_strncmp(tmp, "\tdir=", 5))
	{
		parse_xyz(tmp, v);
		content.dir.x = v->p.p_xyz.x;
		content.dir.y = v->p.p_xyz.y;
		content.dir.z = v->p.p_xyz.z;
	}
}

void			parse_light(t_env *v, t_file *file)
{
	char		*tmp;
	t_light		content;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0)
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\ttype=", 6))
		{
			ft_strstr(tmp, "POINT") ? content.type = POINT : 0;
			ft_strstr(tmp, "DIRECTIONAL") ? content.type = DIRECTIONAL : 0;
			ft_strstr(tmp, "SPOT") ? content.type = SPOT : 0;
		}
		parse_xyz_lgt(v, tmp, content);
		parse_material_lgt(v, tmp, content);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	add_lst_lgt(&v->p.lg, content);
}
