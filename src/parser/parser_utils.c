/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/21 18:53:39 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	error_parser(char *error, t_file *file)
{
	ft_putendl(error);
	ft_putendl(my_strcat("> line ", ft_itoa(file->nb_line)));
	exit(1);
}

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
		ft_strdel(&res[i]);
		ft_strdel(&res[i - 1]);
	}
	free(res);
}
