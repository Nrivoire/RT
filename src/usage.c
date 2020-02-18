#include "../includes/rt.h"

void		usage(char *error)
{
	ft_strcmp(error, "") != 0 ? ft_putendl(error) : 0;
	ft_putendl("\nusage:\n./rt [-f file] [-w width] [-h height] [--help]");
	ft_putendl("\noptions:");
	ft_putendl("-f <file_path>		choose your file.");
	ft_putendl("-w <width [0-1280]>	set your window's width.");
	ft_putendl("-h <height [0-720]>	set your window's height.");
	ft_putendl("--help			show help.\n");
	exit(0);
}

static int	ft_clamp(int value, int min, int max)
{
	value > max ? value = max : 0;
	value < min ? value = min : 0;
	return (value);
}

void		check_options(t_env *v, int argc, char **argv)
{
	int		i;

	i = 0;
	v->file = ft_strdup("./scenes/first.test");
	while (++i < argc)
	{
		!ft_strcmp(argv[i], "--help") ? usage("") : 0;
		if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
			i + 1 < argc ? v->w = ft_clamp(ft_atoi(argv[i + 1]), 100, 1280): 0;
		else if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
			i + 1 < argc ? v->h = ft_clamp(ft_atoi(argv[i + 1]), 100, 720) : 0;
		else if (!ft_strcmp(argv[i], "-f") || !ft_strcmp(argv[i], "--file"))
			i + 1 < argc ? v->file = ft_strdup(argv[i + 1]) : 0;
	}
}
