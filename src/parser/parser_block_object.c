/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:09:37 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/18 16:09:56 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	parse_material(t_env *v, char *tmp, t_object content)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v);
		content.r = v->p_col.r;
		content.g = v->p_col.g;
		content.b = v->p_col.b;
	}
	!ft_strncmp(tmp, "\treflect=", 9) ? content.reflect = parse_value(tmp) : 0;
	!ft_strncmp(tmp, "\trefract=", 9) ? content.refract = parse_value(tmp) : 0;
	if (!ft_strncmp(tmp, "\ttransparency=", 14))
		content.transparency = parse_value(tmp);
	if (!ft_strncmp(tmp, "\tabsorbtion=", 12))
		content.absorbtion = parse_value(tmp);
	!ft_strncmp(tmp, "\tambient=", 9) ? content.ambient = parse_value(tmp) : 0;
	!ft_strncmp(tmp, "\tdiffuse=", 9) ? content.diffuse = parse_value(tmp) : 0;
	if (!ft_strncmp(tmp, "\tspecular=", 10))
		content.specular = parse_value(tmp);
	if (!ft_strncmp(tmp, "\tshininess=", 11))
		content.shininess = parse_value(tmp);
	// !ft_strncmp(tmp, "\ttexture=", 9) ? content.texture = parse_value(tmp) : 0;
}

void	parse_xyz_obj(t_env *v, char *tmp, t_object content)
{
	if (!ft_strncmp(tmp, "\tpos=", 5))
	{
		parse_xyz(tmp, v);
		content.pos.x = v->p_xyz.x;
		content.pos.y = v->p_xyz.y;
		content.pos.z = v->p_xyz.z;
	}
	if (!ft_strncmp(tmp, "\tdir=", 5))
	{
		parse_xyz(tmp, v);
		content.dir.x = v->p_xyz.x;
		content.dir.y = v->p_xyz.y;
		content.dir.z = v->p_xyz.z;
	}
}

void	parse_obj(t_env *v, t_file *file)
{
	char		*tmp;
	t_object	content;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0)
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\ttype=", 6))
		{
			ft_strstr(tmp, "SPHERE") ? content.type = SPHERE : 0;
			ft_strstr(tmp, "PLAN") ? content.type = PLAN : 0;
			ft_strstr(tmp, "CONE") ? content.type = CONE : 0;
			ft_strstr(tmp, "CYLINDER") ? content.type = CYLINDER : 0;
		}
		if (!ft_strncmp(tmp, "\tradius=", 8))
			content.radius = parse_value(tmp);
		parse_xyz_obj(v, tmp, content);
		parse_material(v, tmp, content);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	add_lst_obj(&v->ob, content);
}
