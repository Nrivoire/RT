/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_block_base.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/18 16:09:10 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/20 18:17:30 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../includes/rt.h"

void	parse_scene(t_env *v, t_file *file)
{
	char	*tmp;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0 && !check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		!ft_strncmp(tmp, "\twidth=", 7) ? v->w = parse_value(tmp) : 0;
		!ft_strncmp(tmp, "\theight=", 8) ? v->h = parse_value(tmp) : 0;
		if (!ft_strncmp(tmp, "\tambient-light=", 15))
			v->p.sc.amb_light = parse_value(tmp);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

void	parse_cam(t_env *v, t_file *file)
{
	char	*tmp;

	while (get_next_line(file->fd, &file->line) > 0 &&\
			ft_strncmp(file->line, "}", 1) != 0 && !check_bracket(file))
	{
		tmp = ft_strdup(file->line);
		if (!ft_strncmp(tmp, "\tpos=", 5))
		{
			parse_xyz(tmp, v);
			v->p.cam.pos = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
		}
		if (!ft_strncmp(tmp, "\tdir=", 5))
		{
			parse_xyz(tmp, v);
			v->p.cam.dir = (t_vec){v->p.p_xyz.x, v->p.p_xyz.y, v->p.p_xyz.z};
		}
		!ft_strncmp(tmp, "\tfov=", 5) ? v->p.cam.fov = parse_int_value(tmp) : 0;
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}
