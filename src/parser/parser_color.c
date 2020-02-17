#include "../includes/rt.h"

static int	color_value(char const *s)
{
    int     i;
    int		res;

    i = 0;
    while (!ft_isdigit(s[i]))
        i++;
    if (s[i - 1] == '-')
        i -= 1;
    res = ft_atof(&s[i]);
    res > 255 ? res = 255 : 0;
	res< 0 ? res = 0 : 0;
    return (res);
}

void	parse_color(char *s, t_env *v)
{
	int		i;
    char    *res = NULL;
	
	i = 0;
	res = ft_strtok(s, ",");
	while (res != NULL && i == 0)
	{
		v->p_col.r = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 1)
	{
		v->p_col.g = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 2)
	{
		v->p_col.b = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
}
/*
int		parse_color(char *s)
{
	int		r;
	int		g;
	int		b;
	int		i;
    char    *res = NULL;

	i = 0;
	res = ft_strtok(s, ",");
	while (res != NULL && i == 0)
	{
		r = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 1)
	{
		g = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 2)
	{
		b = color_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	printf("%d %d %d color\n", r,g,b);
	return({.r = r, .g = g, .b = b});
}*/
