/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:32:12 by vasalome          #+#    #+#             */
/*   Updated: 2020/02/18 15:32:15 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		add_lst_obj(t_object **ob, t_object content)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (0);
	new->type = content.type;
	new->radius = content.radius;
	new->pos = content.pos;
	new->dir = content.dir;
	new->r = content.r;
	new->g = content.g;
	new->b = content.b;
	new->reflect = content.reflect;
	new->refract = content.refract;
	new->transparency = content.transparency;
	new->absorbtion = content.absorbtion;
	new->ambient = content.ambient;
	new->diffuse = content.diffuse;
	new->specular = content.specular;
	new->shininess = content.shininess;
	new->texture = content.texture;
	new->next = (!*ob) ? NULL : *ob;
	*ob = new;
	return (0);
}

int		add_lst_lgt(t_light **lg, t_light content)
{
	t_light		*new;

	if (!(new = malloc(sizeof(t_light))))
		return (0);
	new->type = content.type;
	new->pos = content.pos;
	new->dir = content.dir;
	// autres variables ?
	new->next = (!*lg) ? NULL : *lg;
	*lg = new;
	return (0);
}

char	*ft_strtok(char *s, char const *delim)
{
	static char *res;
	int			i;

	if (s)
		res = s;
	if (!res || !*res)
		return (NULL);
	i = 0;
	while (!ft_strchr(delim, res[i]))
		i++;
	s = res;
	res = &res[i];
	if (!i)
		return (ft_strtok(res + 1, delim));
	if (s[i])
		res += 1;
	s[i] = '\0';
	return (s);
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
	//ajout gestion d'erreur?
	return (res);
}

void	parse_xyz(char s[], t_env *v)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	res = ft_strtok(s, ",");
	while (res != NULL)
	{
		if (i == 0)
			v->p.p_xyz.x = parse_value(res);
		else if (i == 1)
			v->p.p_xyz.y = parse_value(res);
		else if (i == 2)
			v->p.p_xyz.z = parse_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
}
