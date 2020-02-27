/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:06:19 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/20 20:06:23 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		color_int_value(char const *s)
{
	int		i;
	int		res;

	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atoi(&s[i]);
	res > 255 ? res = 255 : 0;
	res < 0 ? res = 0 : 0;
	return (res);
}

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

static int		get_hexa(char *s, t_file *file)
{
	int		i;
	int		content;
	int		res;

	i = ft_strlen(s);
	if (i != 8)
		error_parser("Bad file: color hexa must be -> 'RRGGBBAA'", file);
	content = 1;
	res = 0;
	while (--i >= 0)
	{
		'0' <= s[i] && s[i] <= '0' + 15 ? res += (s[i] - '0') * content : 0;
		'A' <= s[i] && s[i] <= 'A' + 5 ? res += (s[i] - 'A' + 10) * content : 0;
		'a' <= s[i] && s[i] <= 'a' + 5 ? res += (s[i] - 'a' + 10) * content : 0;
		content *= 16;
	}
	s[0] == '-' && 16 == 10 ? res *= -1 : 0;
	return (res);
}

static void		hexa_value(char *s, t_env *v, char delim, t_file *file)
{
	int		i;
	char	**hexa;

	i = 0;
	if(!(hexa = ft_strsplit(s, delim)))
		error_parser("Bad file: color hexa must be -> 'RRGGBBAA'", file);
	while (hexa[++i] != NULL)
	{
		if (!ft_strstr(hexa[i], &delim) && i < 2)
		{
			v->p.prev_r = get_hexa(hexa[i], file) >> 24 & 0xFF;
			v->p.prev_g = get_hexa(hexa[i], file) >> 16 & 0xFF;
			v->p.prev_b = get_hexa(hexa[i], file) >> 8 & 0xFF;
			v->p.p_col.r = (float)v->p.prev_r / 255;
			v->p.p_col.g = (float)v->p.prev_g / 255;
			v->p.p_col.b = (float)v->p.prev_b / 255;
			v->p.p_col.a = get_hexa(hexa[1], file) & 0xFF;
		}
		ft_strdel(&hexa[i]);
		ft_strdel(&hexa[i - 1]);
	}
	free(hexa);
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
		if(!(res = ft_strsplit(s, ',')))
			error_parser("Bad file: error in rgba", file);
		while (res[++i] != NULL)
		{
			i == 1 ? v->p.p_col.r = color_value(res[i-1]) : 0;
			i == 1 ? v->p.p_col.g = color_value(res[i]) : 0;
			i == 2 ? v->p.p_col.b = color_value(res[i]) : 0;
			i == 3 ? v->p.p_col.a = color_int_value(res[i]) : 0;
			ft_strdel(&res[i]);
			ft_strdel(&res[i - 1]);
		}
	}
	free(res);
}
