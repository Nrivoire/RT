#include "../includes/rt.h"

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

float  parse_value(char const *s)
{
    int     i;
    float   res;

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
    char    *res = NULL;
	
	i = 0;
	res = ft_strtok(s, ",");
	while (res != NULL)
	{
		if (i == 0)
			v->p_xyz.x = parse_value(res);
		else if (i == 1)
			v->p_xyz.y = parse_value(res);
		else if (i == 2)
			v->p_xyz.z = parse_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
}
