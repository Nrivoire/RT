/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:19 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/21 18:53:22 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		parse_material_lgt(t_env *v, char *tmp, t_light *c, t_file *f)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v, f);
		c->color = (t_color){v->p.p_col.r, v->p.p_col.g, v->p.p_col.b};
	}
	else if (!ft_strncmp(tmp, "\tintensity=", 11))
		c->intensity = parse_value(tmp);
}

static void		parse_xyz_lgt(t_env *v, char *tmp, t_light *content)
{
	if (!ft_strncmp(tmp, "\tpos=", 5))
	{
		parse_xyz(tmp, v);
		content->pos = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tdir=", 5))
	{
		parse_xyz(tmp, v);
		content->dir = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
}

void			parse_light(t_env *v, t_file *file)
{
	char		*tmp;
	t_light		content;

	ft_strdel(&file->line);
	while (read_line(file) > 0 && ft_strncmp(file->line, "}", 1) != 0 &&\
			!check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\ttype=", 6))
		{
			ft_strstr(tmp, "POINT") ? content.type = POINT : 0;
			ft_strstr(tmp, "DIRECTIONAL") ? content.type = DIRECTIONAL : 0;
			ft_strstr(tmp, "SPOT") ? content.type = SPOT : 0;
		}
		parse_xyz_lgt(v, tmp, &content);
		parse_material_lgt(v, tmp, &content, file);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	add_lst_lgt(&v->p.lg, content);
}
