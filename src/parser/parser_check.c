/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:57:51 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/20 14:56:03 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
** Check if the object as a type &
** check if the 3 points of a plane are different.
*/

void	check_fix(t_lst_obj *content)
{
	if (content->dir.x == content->fix.x
		&& content->dir.y == content->fix.y
		&& content->dir.z == content->fix.z)
		{
			content->fix.x = content->fix.x + 0.5;
			if (content->fix.x > 1)
				content->fix.x =content->fix.x - 1;
		}
}

void	check_points_and_type(t_lst_obj *content, t_file *file)
{
	if (content->type == 0)
		error_parser("Bad file: your must precise the type of object", file);
	if (content->type == 2)
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
	check_fix(content);
}
