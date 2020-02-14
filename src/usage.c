/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   usage.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 19:11:52 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 17:11:17 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

void    usage(char *error)
{
    ft_strcmp(error, "") != 0 ? ft_putendl(error) : 0;
    ft_putendl("\nusage:\n./rt [-f file] [-w width] [-h height] [--help]");
    ft_putendl("\noptions:");
    ft_putendl("-f <file_path> choose your file.");
	ft_putendl("-w <width>     set your window's width.");
	ft_putendl("-h <height>    set your window's height.");
	ft_putendl("--help         show help.\n");
	exit(0);
}

void    check_options(t_env *v, int argc, char **argv)
{
    int     i;

    i = 0;
    while (++i < argc)
    {
        !ft_strcmp(argv[i], "--help") ? usage("") : 0;
		if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
        {
			i + 1 < argc ? v->w = ft_atoi(argv[i + 1]) : 0;
        }
		else if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
        {
            i + 1 < argc ? v->h = ft_atoi(argv[i + 1]) : 0;
        }
        else if (!ft_strcmp(argv[i], "-f") || !ft_strcmp(argv[i], "--file"))
        {
            i + 1 < argc ? v->file = ft_strdup(argv[i + 1]) : 0;
        }
    }
    //!ft_strcmp(v->file, "") ? v->file = "./scenes/default.yml" : 0;
    //parser_file(v);
}
