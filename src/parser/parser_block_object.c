/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:05 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/21 18:53:12 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		parse_material_obj(t_env *v, char *tmp, t_object *c, t_file *f)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v, f);
		c->color = (t_color){v->p.p_col.r, v->p.p_col.g, v->p.p_col.b, v->p.p_col.a};
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
	// if (!ft_strncmp(tmp, "\ttexture=", 9))
	// 	c.texture = parse_value(tmp); changer de fonction de recup valeur (maybe tableau)
}

static void		parse_point_plan(t_env *v, char *tmp, t_object *content)
{
	if (!ft_strncmp(tmp, "\tpoint_a=", 9))
	{
		parse_xyz(tmp, v);
		content->a = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tpoint_b=", 9))
	{
		parse_xyz(tmp, v);
		content->b = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
	else if (!ft_strncmp(tmp, "\tpoint_c=", 9))
	{
		parse_xyz(tmp, v);
		content->c = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
}

static void		parse_xyz_obj(t_env *v, char *tmp, t_object *content)
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

void			parse_obj(t_env *v, t_file *file)
{
	char		*tmp;
	t_object	content;

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
		else if (!ft_strncmp(tmp, "\tradius=", 8))
			content.radius = parse_value(tmp);
		parse_xyz_obj(v, tmp, &content);
		parse_point_plan(v, tmp, &content);
		parse_material_obj(v, tmp, &content, file);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	add_lst_obj(&v->p.ob, content);
}
