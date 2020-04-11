/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/11 18:14:53 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

/*
** Displays an error message related to the file and the corresponding line.
*/

void	error_parser(char *error, t_file *file)
{
	ft_putendl(error);
	ft_putendl(my_strcat("> line ", ft_itoa(file->nb_line)));
	exit(1);
}

/*
** Parse the necessary values ​​in int or float.
*/

int		parse_int_value(char const *s)
{
	int		i;
	int		res;

	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atoi(&s[i]);
	return (res);
}

float	parse_value(char const *s)
{
	int		i;
	float	res;

	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atof(&s[i]);
	return (res);
}

/*
** Used to recover xyz coordinates.
*/

void	parse_xyz(char *s, t_env *v, t_file *file)
{
	int		i;
	char	**res;

	i = 0;
	res = NULL;
	if (!(res = ft_strsplit(s, ',')))
		error_parser("Bad file: error in xyz", file);
	while (res[++i] != NULL)
	{
		i == 1 ? v->p.p_xyz.x = parse_value(res[i - 1]) : 0;
		i == 1 ? v->p.p_xyz.y = parse_value(res[i]) : 0;
		i == 2 ? v->p.p_xyz.z = parse_value(res[i]) : 0;
	}
	if (i != 3)
		error_parser("Bad file: must be -> '{x,y,z}'", file);
	while (i >= 0)
		ft_strdel(&res[i--]);
	free(res);
}

/*
** Check if the object as a type &
** check if the 3 points of a plane are different.
*/

void	check_points_and_type(t_lst_obj *content, t_file *file)
{
	if (content->type == 0)
		error_parser("Bad file: your must precise the type of object", file);
	if (content->type == PLAN)
	{
		if (content->a.x == content->b.x && content->b.x == content->c.x
				&& content->a.y == content->b.y && content->b.y == content->c.y
				&& content->a.z == content->b.z && content->b.z == content->c.z)
			error_parser("Bad file: the points need to be different", file);
		else if (content->a.x == content->b.x && content->a.y == content->b.y
				&& content->a.z == content->b.z)
			error_parser("Bad file: points [a][b] need to be different", file);
		else if (content->b.x == content->c.x && content->b.y == content->c.y
				&& content->b.z == content->c.z)
			error_parser("Bad file: points [b][c] need to be different", file);
		else if (content->a.x == content->c.x && content->a.y == content->c.y
				&& content->a.z == content->c.z)
			error_parser("Bad file: points [a][c] need to be different", file);
	}
}