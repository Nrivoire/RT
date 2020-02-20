/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_color.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/18 15:32:05 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/19 15:23:26 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../includes/rt.h"

static int		color_value(char const *s)
{
	int		i;
	int		res;

	i = 0;
	while (!ft_isdigit(s[i]))
		i++;
	if (s[i - 1] == '-')
		i -= 1;
	res = ft_atof(&s[i]);
	res > 255 ? res = 255 : 0;
	res < 0 ? res = 0 : 0;
	return (res);
}

static int		get_hexa(char *s)
{
	int		i;
	int		content;
	int		res;

	i = ft_strlen(s);
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

static void		hexa_value(char s[], t_env *v)
{
	int		i;
	char	*res;
	char	*hexa;

	res = NULL;
	hexa = NULL;
	i = 0;
	res = ft_strtok(s, "x");
	while (res != NULL)
	{
		i == 1 ? hexa = ft_strtrim(res) : 0;
		res = ft_strtok(NULL, "x");
		i++;
	}
	//printf("hexa '%s'\n\n", hexa);
	v->p_col.r = get_hexa(hexa) >> 16 & 0xFF;
	v->p_col.g = get_hexa(hexa) >> 8 & 0xFF;
	v->p_col.b = get_hexa(hexa) & 0xFF;
}

void			parse_color(char s[], t_env *v)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (ft_strstr(s, "0x"))
		hexa_value(s, v);
	else
	{
		res = ft_strtok(s, ",");
		while (res != NULL)
		{
			i == 0 ? v->p_col.r = color_value(res) : 0;
			i == 1 ? v->p_col.g = color_value(res) : 0;
			i == 2 ? v->p_col.b = color_value(res) : 0;
			res = ft_strtok(NULL, ",");
			i++;
		}
	}
	//printf("r '%d'\n", v->p_col.r);
	//printf("g '%d'\n", v->p_col.g);
	//printf("b '%d'\n", v->p_col.b);
}
