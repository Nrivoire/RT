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
	res > 255.0 ? res = 255.0 : 0;
	res < 0.0 ? res = 0.0 : 0;
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
	// printf("%s %lu\n", s, strlen(s));
	// printf("===> i est egale a '%d'\n",i);
	// if (i != 8)
	// {
	// 	ft_putendl("Bad file: color hexa must be -> 'RRGGBBAA'");
	// 	ft_putendl(my_strcat("> line ", ft_itoa(file->nb_line)));
	// 	exit(1);
	// }
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

static void		hexa_value(char s[], t_env *v, char delim, t_file *file)
{
	int		i;
	char	*res;
	char	*hexa;

	res = NULL;
	hexa = NULL;
	// hexa = ft_memalloc(sizeof(char));
	i = 0;
	res = ft_strtok(s, &delim);
	while (res != NULL)
	{
		i == 1 ? hexa = ft_strtrim(res) : 0;
		res = ft_strtok(NULL, &delim);
		i++;
	}
	v->p.prev_r = get_hexa(hexa, file) >> 24 & 0xFF;
	v->p.prev_g = get_hexa(hexa, file) >> 16 & 0xFF;
	v->p.prev_b = get_hexa(hexa, file) >> 8 & 0xFF;
	v->p.p_col.r = (float)v->p.prev_r / 255;
	v->p.p_col.g = (float)v->p.prev_g / 255;
	v->p.p_col.b = (float)v->p.prev_b / 255;
	v->p.p_col.a = get_hexa(hexa, file) & 0xFF;
	free(hexa);
}

void			parse_color(char s[], t_env *v, t_file *file)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (ft_strstr(s, "0x"))
		hexa_value(s, v, 'x', file);
	else if (ft_strstr(s, "#"))
		hexa_value(s, v, '#', file);
	else
	{
		res = ft_strtok(s, ",");
		while (res != NULL)
		{
			i == 0 ? v->p.p_col.r = color_value(res) : 0;
			i == 1 ? v->p.p_col.g = color_value(res) : 0;
			i == 2 ? v->p.p_col.b = color_value(res) : 0;
			i == 3 ? v->p.p_col.a = color_int_value(res) : 0;
			res = ft_strtok(NULL, ",");
			i++;
		}
	}
}
