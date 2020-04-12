/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:31:41 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:20:01 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Imitates strcat function with memory allocation.
*/

char			*my_strcat(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

/*
** Check if the previous block is closed,
** before allowing the opening of the next one.
*/

int				check_bracket(t_file *file)
{
	char		*tmp;

	tmp = ft_strdup(file->line);
	if (ft_strstr(tmp, "scene{") || ft_strstr(tmp, "camera{")
			|| ft_strstr(tmp, "light{") || ft_strstr(tmp, "object{"))
	{
		ft_putendl("Bad file: missing '}' to close a block");
		ft_putendl(my_strcat("> before line ", ft_itoa(file->nb_line)));
		ft_strdel(&tmp);
		exit(1);
	}
	ft_strdel(&tmp);
	return (0);
}

/*
** Allows file reading line by line and increments the line number.
*/

int				read_line(t_file *file)
{
	file->nb_line++;
	if (get_next_line(file->fd, &file->line) > 0)
		return (1);
	else
		return (0);
}

/*
** Detects the opening of the block to be parsed.
*/

static void		read_file(t_env *v, t_file *file)
{
	char		*tmp;

	while (read_line(file) > 0)
	{
		tmp = ft_strdup(file->line);
		if (!(ft_strncmp(tmp, "scene{", 6)))
			parse_scene(v, file);
		else if (!(ft_strncmp(tmp, "camera{", 7)))
			parse_cam(v, file);
		else if (!(ft_strncmp(tmp, "light{", 6)))
		{
			v->nb_l++;
			parse_light(v, file);
		}
		else if (!(ft_strncmp(tmp, "object{", 7)))
		{
			v->nb_o++;
			parse_obj(v, file);
		}
		ft_strdel(&file->line);
		ft_strdel(&tmp);
	}
}

/*
** Allows the opening of the file passed in argument.
*/

int				parser_file(t_env *v)
{
	t_file	file;

	file.nb_line = 0;
	(file.fd = open(v->file, O_RDWR)) == -1 ? ft_error("Bad file") : 0;
	read_file(v, &file);
	close(file.fd) == -1 ? ft_error("Can't close fd") : 0;
	ft_strdel(&file.line);
	return (0);
}
