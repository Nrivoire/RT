/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:05 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/20 19:58:43 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Parse the values ​​of the objects in the file.
*/

static void		parse_tex_pro(char *tmp, t_lst_obj *c)
{
	if (!ft_strncmp(tmp, "\ttexture-procedural=", 20))
	{
		ft_strstr(tmp, "PERLIN") ? c->procedural = PERLIN : 0;
		ft_strstr(tmp, "WOOD") ? c->procedural = WOOD : 0;
		ft_strstr(tmp, "MARBLE") ? c->procedural = MARBLE : 0;
		if (ft_strstr(tmp, "WAVES"))
		{
			c->procedural = WAVES;
			c->tx_pertu = 0 + ft_clamp(parse_int_value(tmp), 0, 100);
			if (c->tx_pertu == 0)
				c->tx_pertu = 10;
		}
		ft_strstr(tmp, "GRADIENT") ? c->procedural = GRAD : 0;
		if (ft_strstr(tmp, "BUMP"))
		{
			c->bump = BUMP;
			c->tx_pertu = 0 + ft_clamp(parse_int_value(tmp), 0, 100);
			if (c->tx_pertu == 0)
				c->tx_pertu = 50;
		}
	}
}

static void		parse_texture_obj(char *tmp, t_lst_obj *c, t_file *f)
{
	int		i;
	char	**tex_path;

	i = 0;
	tex_path = NULL;
	if (!ft_strncmp(tmp, "\ttexture=", 9))
	{
		if (!(tex_path = ft_strsplit(tmp, '"')))
			error_parser("Bad file: can't find the quotation marks", f);
		while (tex_path[++i] != NULL)
		{
			if (i == 1)
			{
				if (!(c->texture = IMG_Load(tex_path[i])))
					error_parser(my_strcat("Bad file: can't find the file ",\
								tex_path[i]), f);
			}
		}
		while (i >= 0)
			ft_strdel(&tex_path[i--]);
		free(tex_path);
	}
	parse_tex_pro(tmp, c);
}

static void		parse_material_obj(t_env *v, char *tmp, t_lst_obj *c, t_file *f)
{
	if (!ft_strncmp(tmp, "\tcolor=", 7))
	{
		parse_color(tmp, v, f);
		c->color = (t_color){v->p.p_col.r, v->p.p_col.g, v->p.p_col.b};
	}
	else if (!ft_strncmp(tmp, "\treflect=", 9))
		c->reflect = ft_clampf(parse_value(tmp), 0.0, 1.0);
	else if (!ft_strncmp(tmp, "\trefract=", 9))
		c->refract = ft_clampf(parse_value(tmp), 0.0, 1.0);
	else if (!ft_strncmp(tmp, "\ttransparency=", 14))
		c->transparency = ft_clampf(parse_value(tmp), 0.0, 1.0);
	else if (!ft_strncmp(tmp, "\tshininess=", 11))
		c->shininess = ft_clampf(parse_value(tmp), 0.0, 1.0);
	else if (!ft_strncmp(tmp, "\tfix=", 5))
	{
		parse_xyz(tmp, v, f);
		c->fix = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
	}
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
		parse_xyz_dir(tmp, v, f);
		c->dir = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z * 10};
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
			ft_strstr(tmp, "SPHERE") ? content.type = 1 : 0;
			ft_strstr(tmp, "PLANE") ? content.type = 2 : 0;
			ft_strstr(tmp, "CONE") ? content.type = 3 : 0;
			ft_strstr(tmp, "CYLINDER") ? content.type = 4 : 0;
		}
		if (!ft_strncmp(tmp, "\tradius=", 8))
			content.radius = ft_clampf(parse_value(tmp), 0, 10000);
		parse_xyz_obj(v, tmp, &content, file);
		parse_material_obj(v, tmp, &content, file);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
	check_points_and_type(&content, file);
	add_lst_obj(&v->p.ob, content);
}
