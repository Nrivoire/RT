/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:53:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/16 04:00:57 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
** Allows to bring a value between two lower and upper limits,
** and to assign the upper limit if the value exceeds.
*/

int		ft_clamp(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}

float	ft_clampf(float value, float min, float max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}
