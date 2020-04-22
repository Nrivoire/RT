/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:05 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:19:03 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Parse the values ​​of the objects in the file.
*/

static void		parse_tex_pro(char *tmp, t_lst_obj *content)
{
	if (!ft_strncmp(tmp, "\ttexture-procedural=", 20))
	{
		ft_strstr(tmp, "PERLIN") ? content->procedural = PERLIN : 0;
		ft_strstr(tmp, "WOOD") ? content->procedural = WOOD : 0;
		ft_strstr(tmp, "MARBLE") ? content->procedural = MARBLE : 0;
		ft_strstr(tmp, "CHESS") ? content->procedural = CHESS : 0;
	}
}

static void		parse_texture_obj(char *tmp, t_lst_obj *content, t_file *file)
{
	int		i;
	char	**tex_path;

	i = 0;
	tex_path = NULL;
	if (!ft_strncmp(tmp, "\ttexture=", 9))
	{
		if (!(tex_path = ft_strsplit(tmp, '"')))
			error_parser("Bad file: can't find the quotation marks", file);
		while (tex_path[++i] != NULL)
		{
			if (i == 1)
			{
				if (!(content->texture = IMG_Load(tex_path[i])))
					error_parser(my_strcat("Bad file: can't find the file ",\
								tex_path[i]), file);
			}
		}
		while (i >= 0)
			ft_strdel(&tex_path[i--]);
		free(tex_path);
	}
	parse_tex_pro(tmp, content);
}

static void		parse_material_obj(t_env *v, char *tmp, t_lst_obj *c, t_file *f)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v, f);
		c->color = (t_color){v->p.p_col.r, v->p.p_col.g, v->p.p_col.b};
	}
	!ft_strncmp(tmp, "\treflect=", 9) ? c->reflect = parse_value(tmp) : 0;
	!ft_strncmp(tmp, "\trefract=", 9) ? c->refract = parse_value(tmp) : 0;
	if (!ft_strncmp(tmp, "\ttransparency=", 14))
		c->transparency = parse_value(tmp);
	else if (!ft_strncmp(tmp, "\tabsorbtion=", 12))
		c->absorbtion = parse_value(tmp);
	!ft_strncmp(tmp, "\tambient=", 9) ? c->ambient = parse_value(tmp) : 0;
	!ft_strncmp(tmp, "\tdiffuse=", 9) ? c->diffuse = parse_value(tmp) : 0;
	if (!ft_strncmp(tmp, "\tspecular=", 10))
		c->specular = parse_value(tmp);
	else if (!ft_strncmp(tmp, "\tshininess=", 11))
		c->shininess = parse_value(tmp);
	parse_texture_obj(tmp, c, f);
}

static void		parse_xyz_obj(t_env *v, char *tmp, t_lst_obj *c, t_file *f)
{
	if (!ft_strncmp(tmp, "\tpos=", 5))
	{
		parse_xyz(tmp, v, f);
		c->pos = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tdir=", 5))
	{
		parse_xyz(tmp, v, f);
		c->dir = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tpoint_a=", 9))
	{
		parse_xyz(tmp, v, f);
		c->a = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tpoint_b=", 9))
	{
		parse_xyz(tmp, v, f);
		c->b = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tpoint_c=", 9))
	{
		parse_xyz(tmp, v, f);
		c->c = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
}

void			parse_obj(t_env *v, t_file *file)
{
	char		*tmp;
	t_lst_obj	content;

	init_value_obj(&content);
	ft_strdel(&file->line);
	while (read_line(file) > 0 && ft_strncmp(file->line, "}", 1) != 0 &&\
			!check_bracket(file))
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
		parse_xyz_obj(v, tmp, &content, file);
		parse_material_obj(v, tmp, &content, file);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	check_points_and_type(&content, file);
	add_lst_obj(&v->p.ob, content);
}
