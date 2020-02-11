/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   usage.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/11 19:11:52 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 20:22:14 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

void    usage(char *error)
{
    error == NULL ? ft_putendl(ft_strcat("Error: ", error)) : 0;
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
    int     fd;

    i = 0;
    while (++i < argc)
    {
        !ft_strcmp(argv[i], "--help") ? usage("") : 0;
		if (!ft_strcmp(argv[i], "-w") || !ft_strcmp(argv[i], "--width"))
			if (i + 1 < argc)
                v->w = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp(argv[i], "-h") || !ft_strcmp(argv[i], "--height"))
            if (i + 1 < argc)
			    v->h = ft_atoi(argv[i + 1]);
        else if (!ft_strcmp(argv[i], "-f") || !ft_strcmp(argv[i], "--file"))
            if (i + 1 < argc)
                v->file = ft_strdup(argv[i + 1]);
    }
    v->file == NULL ? usage("") : 0;
    // check if the file is good ? 0 : usage("bad file");
    (fd = open(v->file, O_RDWR)) == -1 ? usage("bad file") : 0;
    close(fd) == -1 ? usage("can't close fd") : 0;
}
