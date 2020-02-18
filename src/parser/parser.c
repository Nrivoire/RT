/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:31:41 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/18 15:31:45 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		read_file(t_env *v, t_file *file)
{
	char		*tmp;

	while (get_next_line(file->fd, &file->line) > 0)
	{
		tmp = ft_strdup(file->line);
		if (!(ft_strncmp(tmp, "scene{", 6)))
			parse_scene(v, file);
		if (!(ft_strncmp(tmp, "object{", 7)))
			parse_obj(v, file);
		if (!(ft_strncmp(tmp, "camera{", 7)))
			parse_cam(v, file);
		if (!(ft_strncmp(tmp, "light{", 6)))
			parse_light(v, file);
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

int				parser_file(t_env *v)
{
	t_file	file;

	(file.fd = open(v->file, O_RDWR)) == -1 ? ft_error("Bad file") : 0;
	read_file(v, &file);
	close(file.fd) == -1 ? ft_error("Can't close fd") : 0;
	return (0);
}
