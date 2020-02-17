#include "../includes/rt.h"

/*
char	*p_trim(char const *s)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] <= '0' || s[i] >= '9')
		i++;
	while (s[i] <= '0' || s[i] >= '9')
		j--;
	if (i > j)
		return (ft_strdup(""));
	if (!(new = (char*)malloc(sizeof(*new) * (j - i + 2))))
		return (NULL);
	while (i <= j)
		new[k++] = s[i++];
	new[k] = '\0';
	return (new);
}*/

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

void	parse_xyz(char *s, t_env *v)
{
	int		i;
    char    *res = NULL;
	
	i = 0;
	res = ft_strtok(s, ",");
	while (res != NULL && i == 0)
	{
		v->p_xyz.x = parse_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 1)
	{
		v->p_xyz.y = parse_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
	while (res != NULL && i == 2)
	{
		v->p_xyz.z = parse_value(res);
		res = ft_strtok(NULL, ",");
		i++;
	}
}