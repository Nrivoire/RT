/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/14 15:09:04 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 19:09:12 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

int     init_parse_struct(void)
{
    // t_scene     *sc;
	// t_camera    *cam;
	t_light     *lg;
	t_object    *ob;

    // if (!(sc = ft_memalloc(sizeof(t_scene))))
	// 	return (0);
    // if (!(ob = ft_memalloc(sizeof(t_cam))))
	// 	return (0);
    if (!(lg = ft_memalloc(sizeof(t_light))))
		return (0);
    if (!(ob = ft_memalloc(sizeof(t_object))))
		return (0);
    return(0);
}

static void     read_file(t_env *v, t_file *file)
{
    char        *tmp;

    init_parse_struct();
    while (get_next_line(file->fd, &file->line) > 0)
    {
        tmp = ft_strdup(file->line);
        if (!(ft_strncmp(tmp, "scene{", 6)))
            parse_scene(v, file);
        if (!(ft_strncmp(tmp, "object{", 7)))
            parse_obj(v, file);
        if (!(ft_strncmp(tmp, "camera{", 7)))
            parse_cam(v, file);
        if (!(ft_strncmp(tmp, "light{", 6)))
            parse_light(v, file);
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }

}

int     parser_file(t_env *v)
{
    t_file  file;

    (file.fd = open(v->file, O_RDWR)) == -1 ? ft_error("Bad file") : 0;
    read_file(v, &file);

    close(file.fd) == -1 ? ft_error("Can't close fd") : 0;
    return (0);
}