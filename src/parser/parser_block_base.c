/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_block_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:52:08 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/12 19:25:59 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Allows to bring a value between two lower and upper limits,
** and to assign the upper limit if the value exceeds.
*/

static int	ft_clamp_to_max(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = max : 0;
	return (value);
}

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
			v->w = ft_clamp_to_max(parse_int_value(tmp), 100, 960);
		else if (!ft_strncmp(tmp, "\theight=", 8))
			v->h = ft_clamp_to_max(parse_int_value(tmp), 100, 720);
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
		{
			parse_xyz(tmp, v, file);
			v->p.cam.angle_x = ft_deg_to_rad(v->p.p_xyz.x);
			v->p.cam.angle_y = ft_deg_to_rad(v->p.p_xyz.y);
			v->p.cam.angle_z = ft_deg_to_rad(v->p.p_xyz.z);
		}
		!ft_strncmp(tmp, "\tfov=", 5) ? v->p.cam.fov = parse_int_value(tmp) : 0;
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}
