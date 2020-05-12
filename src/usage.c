/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:56:53 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/12 03:44:34 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	atoi_clamp_usage(const char *str, int min, int max)
{
	int		value;

	value = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\v' || *str == ' ' || *str == '\f')
		str++;
	while (*str != '\0' && value < 2000)
	{
		*str >= '0' && *str <= '9' ? value = value * 10 + *str - '0' : 0;
		str++;
	}
	value > max ? value = max : 0;
	value < min ? value = max : 0;
	return (value);
}

void		usage(char *error, int run)
{
	ft_strcmp(error, "") ? ft_putendl_fd(error, 2) : 0;
	ft_putendl("\nusage:\n./rt [-f file] [-w width] [-h height] [--help]");
	ft_putendl("\noptions:");
	ft_putendl("-f <file_path>		choose your file.");
	ft_putendl("-w <width [100-960]>	set your window's width.");
	ft_putendl("-h <height [100-720]>	set your window's height.");
	ft_putendl("filter:	--greyscale | --sepia | --negative | --celshading");
	ft_putendl("--help			show help.\n");
	!run ? exit(0) : 0;
}

static void	option_filter(t_env *v, char *option)
{
	!ft_strcmp(option, "--greyscale") ? v->p.sc.filter = 1 : 0;
	!ft_strcmp(option, "--sepia") ? v->p.sc.filter = 2 : 0;
	!ft_strcmp(option, "--negative") ? v->p.sc.filter = 3 : 0;
	!ft_strcmp(option, "--celshading") ? v->p.sc.filter = 4 : 0;
}

void		check_options(t_env *v, int argc, char **argv)
{
	int		i;
	char	*default_map;

	i = 0;
	default_map = ft_strdup("scenes/default.rt");
	v->file = default_map;
	while (++i < argc)
	{
		!ft_strcmp(argv[i], "--help") ? usage("", 1) : 0;
		if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
		{
			if (i + 1 < argc)
				v->w = atoi_clamp_usage(argv[i + 1], 100, 960);
		}
		else if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
		{
			if (i + 1 < argc)
				v->h = atoi_clamp_usage(argv[i + 1], 100, 720);
		}
		else if (!ft_strcmp(argv[i], "-f") || !ft_strcmp(argv[i], "--file"))
			i + 1 < argc ? v->file = ft_strdup(argv[i + 1]) : 0;
		option_filter(v, argv[i]);
	}
	ft_strdel(&default_map);
}
