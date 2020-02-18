#include "../includes/rt.h"

void	parse_scene(t_env *v, t_file *file)
{
    char    *tmp;

    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        !ft_strncmp(tmp, "\tambient-light=", 15) ? v->sc.amb_light = parse_value(tmp) : 0;
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
}

void	parse_cam(t_env *v, t_file *file)
{
    char    *tmp;

    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        // if (!ft_strncmp(tmp, "\tpos=", 5))
        // {
        //     parse_xyz(tmp, v);
        //     printf("\ndir x %f\n", v->p_xyz.x);
        //     printf("dir y %f\n", v->p_xyz.y);
        //     printf("dir z %f\n\n", v->p_xyz.z);
        // }
        // if (!ft_strncmp(tmp, "\tdir=", 5))
        // {
        //     parse_xyz(tmp, v);
        //     printf("\ndir x %f\n", v->p_xyz.x);
        //     printf("dir y %f\n", v->p_xyz.y);
        //     printf("dir z %f\n\n", v->p_xyz.z);
        // }
        !ft_strncmp(tmp, "\tfov=", 5) ? v->cam.fov = parse_value(tmp) : 0;
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
}

void	parse_light(t_env *v, t_file *file)
{
    char    *tmp;

    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        // if (!ft_strncmp(tmp, "\ttype=", 6))
        // {
        //     ft_strstr(tmp, "POINT") ? printf("POINT ICI\n") : 0;
        //     ft_strstr(tmp, "DIRECTIONAL") ? printf("DIRECTIONAL ICI\n") : 0;
        //     ft_strstr(tmp, "SPOT") ? printf("SPO ICI\n") : 0;
        // }
        // if (!ft_strncmp(tmp, "\tpos=", 5))
        // {
        //     parse_xyz(tmp, v);
        //     printf("\ndir x %f\n", v->p_xyz.x);
        //     printf("dir y %f\n", v->p_xyz.y);
        //     printf("dir z %f\n\n", v->p_xyz.z);
        // }
        !ft_strncmp(tmp, "\tintensity=", 11) ? printf("'%f'\n", parse_value(tmp)) : 0;
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
    // file->lg_n++;
}

void    parse_material(t_env *v, char *tmp, int i)
{
    if (!ft_strncmp(tmp, "\tcolor=", 7))
    {
        parse_color(tmp, v);
        printf("\ncol r %d\n", v->p_col.r);
        printf("col g %d\n", v->p_col.g);
        printf("col b %d\n\n", v->p_col.b);
    }
    // !ft_strncmp(tmp, "\treflect=", 9) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\trefract=", 9) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\ttransparency=", 14) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\tabsorbtion=", 12) ? printf("'%f'\n", parse_value(tmp)): 0;
    // !ft_strncmp(tmp, "\tambient=", 9) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\tdiffuse=", 9) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\tspecular=", 10) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\tshininess=", 11) ? printf("'%f'\n", parse_value(tmp)) : 0;
    // !ft_strncmp(tmp, "\ttexture=", 9) ? printf("'%s'\n", tmp) : 0;
}

void	parse_obj(t_env *v, t_file *file)
{
    char    *tmp;
    static int i;

    i = 0;
    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        //printf("test '%s'\n",file->line);
        if (!ft_strncmp(tmp, "\ttype=", 6))
        {
            ft_strstr(tmp, "SPHERE") ? printf("SPHERE ICI\n") : 0;
            //ft_strstr(tmp, "SPHERE") ? v->ob[i].type = "SPHERE" : 0;
            ft_strstr(tmp, "PLAN") ? printf("PLAN ICI\n") : 0;
            ft_strstr(tmp, "CONE") ? printf("CONE ICI\n") : 0;
            ft_strstr(tmp, "CYLINDER") ? printf("CYLINDER ICI\n") : 0;
            //printf("JE VEUX SAVOIR SI '%s' %d\n", v->ob[i].type, i);
        }
        
        !ft_strncmp(tmp, "\tradius=", 8) ? printf("'%f'\n", parse_value(tmp)) : 0;
        if (!ft_strncmp(tmp, "\tpos=", 5))
        {
            parse_xyz(tmp, v);
            printf("\npos x %f\n", v->p_xyz.x);
            printf("pos y %f\n", v->p_xyz.y);
            printf("pos z %f\n\n", v->p_xyz.z);
        }
        if (!ft_strncmp(tmp, "\tdir=", 5))
        {
            parse_xyz(tmp, v);
            printf("\ndir x %f\n", v->p_xyz.x);
            printf("dir y %f\n", v->p_xyz.y);
            printf("dir z %f\n\n", v->p_xyz.z);
        }
        parse_material(v, tmp, i);
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
    i++;
    // file->ob_n++;
}
