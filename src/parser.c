/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 15:09:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/14 17:17:10 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

int     value_obj(t_file *file, int arg)
{
    int     i;
    int     count;
    int     ret;

    i = file->i;
    count = 0;
    ret = 0;
    arg--;
    while (count != arg)
        file->line[i++] == ',' ? count++ : 0;
    while (file->line[i] < '0' && file->line[i] > '9')
        i++;
    while (file->line[i] >= '0' && file->line[i] <= '9')
    {
        ret *= 10;
        ret += file->line[i] - 48;
        i++;
    }
    return (ret);
}

int     parse_obj(t_env *v, t_file *file)
{
    if (ft_strstr(file->line, "type:"))
    //  v-> type[arg] = value_obj(file, arg)
    else if (ft_strstr(file->line, "radius:"))
    //  v-> radius[arg] = value_obj(file, arg)
    else if (ft_strstr(file->line, "pos:"))
    //  v-> pos[arg] = value_obj(file, arg)
    else if (ft_strstr(file->line, "dir:"))
    //  v-> dir[arg] = value_obj(file, arg)


    while (file->line[file->i] != '}')
        file->i++;
    file->arg++;
    return (0);
}

int     parsing(t_env *v, t_file *file)
{
    if (ft_strstr(file->line, "scene:"))
    //    v-> = parse_scene(file->line, )
    else if (ft_strstr(file->line, "object:"))
    //    v-> = parse_obj(file->line, )
    else if (ft_strstr(file->line, "light:"))
    //    v-> = parse_obj(file->line, )
}

int     read_file(t_env *v, t_file *file)
{
    int         ret;
    static int  i;

    while ((ret = get_next_line(file->fd, &file->line)))
    {
        file->i = 0;
        while (file->line[file->i] != '\0')
        {
            if (file->line[file->i] == '{')
                parsing(v, file);
            file->i++;
        }
        ft_strdel(&file->line);
    }

    if (ret == -1)
        return (-1);
    return (0);
}

int     parser_file(t_env *v)
{
    t_file  file;

    (file.fd = open(v->file, O_RDWR)) == -1 ? ft_error("Bad file") : 0;
    read_file(v, &file) == -1 ? ft_error("Can't read the file") : 0;

    //close(fd) == -1 ? ft_error("Can't close fd") : 0;
    return (0);
}