/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:52:08 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/22 12:59:05 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Parse the values ​​of the scene in the file.
*/

static void	option_scene(t_env *v, char *tmp)
{
	if (!ft_strncmp(tmp, "\tfilter=", 8))
	{
		ft_strstr(tmp, "greyscale") ? v->p.sc.filter = 1 : 0;
		ft_strstr(tmp, "sepia") ? v->p.sc.filter = 2 : 0;
		ft_strstr(tmp, "negative") ? v->p.sc.filter = 3 : 0;
		ft_strstr(tmp, "cel-shading") ? v->p.sc.filter = 4 : 0;
		ft_strstr(tmp, "stereoscopie") ? v->p.sc.filter = 5 : 0;
	}
}

void		parse_scene(t_env *v, t_file *file)
{
	char	*tmp;

	ft_strdel(&file->line);
	while (read_line(file) > 0 && ft_strncmp(file->line, "}", 1) != 0 &&\
			!check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\twidth=", 7))
			v->w = ft_clamp(parse_int_value(tmp), 100, 1280);
		else if (!ft_strncmp(tmp, "\theight=", 8))
			v->h = ft_clamp(parse_int_value(tmp), 100, 720);
		else if (!ft_strncmp(tmp, "\tambient-light=", 15))
		{
			parse_color_scene(tmp, v, file);
			v->p.sc.amb_light = (t_color){v->p.p_col.r, v->p.p_col.g,\
										v->p.p_col.b};
		}
		option_scene(v, tmp);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

/*
** Parse the values ​​of the camera in the file.
*/

void		dir_cam(t_env *v, char *tmp, t_file *file)
{
	parse_xyz(tmp, v, file);
	if (v->p.p_xyz.x < 0)
		v->p.p_xyz.x = 360 + v->p.p_xyz.x;
	if (v->p.p_xyz.y < 0)
		v->p.p_xyz.y = 360 + v->p.p_xyz.y;
	if (v->p.p_xyz.z < 0)
		v->p.p_xyz.z = 360 + v->p.p_xyz.z;
	v->p.cam.angle_x = ft_deg_to_rad(v->p.p_xyz.x);
	v->p.cam.angle_y = ft_deg_to_rad(v->p.p_xyz.y);
	v->p.cam.angle_z = ft_deg_to_rad(v->p.p_xyz.z);
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
			parse_xyz(tmp, v, file);
			v->p.cam.pos = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
		}
		else if (!ft_strncmp(tmp, "\tdir=", 5))
			dir_cam(v, tmp, file);
		else if (!ft_strncmp(tmp, "\tfov=", 5))
			v->p.cam.fov = ft_clamp(parse_int_value(tmp), 30, 170);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}
