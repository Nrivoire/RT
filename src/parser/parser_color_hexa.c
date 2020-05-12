/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 20:06:19 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/10 18:43:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Retrieve the RGB values ​​from an hexa color.
*/

static int		get_hexa(char *s, t_file *file)
{
	int		i;
	int		content;
	int		res;

	i = ft_strlen(s);
	if (i != 6)
		error_parser("Bad file: color hexa must be -> 'RRGGBB'", file);
	content = 1;
	res = 0;
	while (--i >= 0)
	{
		'0' <= s[i] && s[i] <= '0' + 15 ? res += (s[i] - '0') * content : 0;
		'A' <= s[i] && s[i] <= 'A' + 5 ? res += (s[i] - 'A' + 10) * content : 0;
		'a' <= s[i] && s[i] <= 'a' + 5 ? res += (s[i] - 'a' + 10) * content : 0;
		content *= 16;
	}
	return (res);
}

static char		delim_is(char *s)
{
	if (ft_strstr(s, "0x"))
		return ('x');
	else if (ft_strstr(s, "#"))
		return ('#');
	return (' ');
}

void			hexa_value(char *s, t_env *v, t_file *file)
{
	int		i;
	char	**hexa;
	char	delim;

	i = 0;
	delim = delim_is(s);
	if (!(hexa = ft_strsplit(s, delim)))
		error_parser("Bad file: Echec de lecture du format hexa", file);
	while (hexa[++i] != NULL)
	{
		if (!ft_strstr(hexa[i], &delim) && i < 2)
		{
			v->p.prev_r = get_hexa(hexa[i], file) >> 16 & 0xFF;
			v->p.prev_g = get_hexa(hexa[i], file) >> 8 & 0xFF;
			v->p.prev_b = get_hexa(hexa[i], file) & 0xFF;
			v->p.p_col.r = (float)v->p.prev_r / 255;
			v->p.p_col.g = (float)v->p.prev_g / 255;
			v->p.p_col.b = (float)v->p.prev_b / 255;
		}
	}
	while (i >= 0)
		ft_strdel(&hexa[i--]);
	free(hexa);
}
