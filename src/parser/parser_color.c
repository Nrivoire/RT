/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:06:19 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:19:34 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Retrieve the RGB values ​​of object & light block.
*/

static float	color_value(char const *s)
{
	int		i;
	float	res;
	float	result;
	char	*empty;

	i = 0;
	empty = ft_strtrim(s);
	if (ft_strcmp(empty, "") == 0)
		return (0);
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atof(&s[i]);
	res > 255.0 ? res = 255.0 : 0;
	res < 0.0 ? res = 0.0 : 0;
	result = res / 255.0;
	free(empty);
	return (result);
}

void			parse_color(char *s, t_env *v, t_file *file)
{
	int		i;
	char	**res;

	i = 0;
	res = NULL;
	if (ft_strstr(s, "0x"))
		hexa_value(s, v, 'x', file);
	else if (ft_strstr(s, "#"))
		hexa_value(s, v, '#', file);
	else
	{
		if (!(res = ft_strsplit(s, ',')))
			error_parser("Bad file: error in rgba", file);
		while (res[++i] != NULL)
		{
			i == 1 ? v->p.p_col.r = color_value(res[i - 1]) : 0;
			i == 1 ? v->p.p_col.g = color_value(res[i]) : 0;
			i == 2 ? v->p.p_col.b = color_value(res[i]) : 0;
		}
		if (i != 3)
			error_parser("Bad file: rgb must be -> '{r,g,b}' [0-255]", file);
		while (i >= 0)
			ft_strdel(&res[i--]);
		free(res);
	}
}

/*
** Retrieve the RGB values ​​of scene block.
*/

static float	color_value_scene(char const *s)
{
	int		i;
	float	res;
	float	result;
	char	*empty;

	i = 0;
	empty = ft_strtrim(s);
	if (ft_strcmp(empty, "") == 0)
		return (0);
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atof(&s[i]);
	res > 1.0 ? res = 1.0 : 0;
	res < 0.0 ? res = 0.0 : 0;
	result = res;
	free(empty);
	return (result);
}

void			parse_color_scene(char *s, t_env *v, t_file *file)
{
	int		i;
	char	**res;

	i = 0;
	res = NULL;
	if (!(res = ft_strsplit(s, ',')))
		error_parser("Bad file: error in rgb", file);
	while (res[++i] != NULL)
	{
		i == 1 ? v->p.p_col.r = color_value_scene(res[i - 1]) : 0;
		i == 1 ? v->p.p_col.g = color_value_scene(res[i]) : 0;
		i == 2 ? v->p.p_col.b = color_value_scene(res[i]) * 10 : 0;
	}
	if (i != 3)
		error_parser("Bad file: ambient rgb must be -> '{r,g,b}' [0-1]", file);
	while (i >= 0)
		ft_strdel(&res[i--]);
	free(res);
}
