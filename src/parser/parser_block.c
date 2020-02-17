#include "../includes/rt.h"

void	parse_scene(t_env *v, t_file *file)
{
    char    *tmp;

    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        !ft_strncmp(tmp, "  ambient-light=", 16) ? v->sc.amb_light = parse_value(tmp) : 0;
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
        if (ft_strncmp(tmp, "  pos=", 6))
        {
            parse_xyz(tmp, v);
            printf("x %f\n", v->p_xyz.x);
            printf("y %f\n", v->p_xyz.y);
            printf("z %f\n", v->p_xyz.z);
        }
        if (ft_strncmp(tmp, "  dir=", 6))
        {
            parse_xyz(tmp, v);
            printf("x %f\n", v->p_xyz.x);
            printf("y %f\n", v->p_xyz.y);
            printf("z %f\n", v->p_xyz.z);
        }
        !ft_strncmp(tmp, "  fov=", 6) ? v->cam.fov = parse_value(tmp) : 0;
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
        if (!ft_strncmp(tmp, "  type=", 7))
        {
            ft_strstr(tmp, "POINT") ? printf("POINT ICI\n") : 0;
            ft_strstr(tmp, "DIRECTIONAL") ? printf("DIRECTIONAL ICI\n") : 0;
            ft_strstr(tmp, "SPOT") ? printf("SPO ICI\n") : 0;
        }
        if (ft_strncmp(tmp, "  pos=", 6))
        {
            parse_xyz(tmp, v);
            printf("x %f\n", v->p_xyz.x);
            printf("y %f\n", v->p_xyz.y);
            printf("z %f\n", v->p_xyz.z);
        }
        !ft_strncmp(tmp, "  intensity=", 12) ? printf("'%f'\n", parse_value(tmp)) : 0;
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
    file->lg_n++;
}

void    parse_material(t_env *v, char *tmp)
{
    if (!ft_strncmp(tmp, "  color=", 8))
    {
        parse_color(tmp, v);
        printf("col r %d\n", v->p_col.r);
        printf("col g %d\n", v->p_col.g);
        printf("col b %d\n", v->p_col.b);
    }
    !ft_strncmp(tmp, "  reflect=", 10) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  refract=", 10) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  transparency=", 15) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  absorbtion=", 13) ? printf("'%f'\n", parse_value(tmp)): 0;
    !ft_strncmp(tmp, "  ambient=", 10) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  diffuse=", 10) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  specular=", 11) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  shininess=", 12) ? printf("'%f'\n", parse_value(tmp)) : 0;
    !ft_strncmp(tmp, "  texture=", 10) ? printf("'%s'\n", tmp) : 0;
}

void	parse_obj(t_env *v, t_file *file)
{
    char    *tmp;

    while (get_next_line(file->fd, &file->line) > 0 && ft_strncmp(file->line, "}", 1) != 0)
    {
        tmp = ft_strdup(file->line);
        //printf("test '%s'\n",file->line);
        if (!ft_strncmp(tmp, "  type=", 7))
        {
            ft_strstr(tmp, "SPHERE") ? printf("SPHERE ICI\n") : 0;
            ft_strstr(tmp, "PLAN") ? printf("PLAN ICI\n") : 0;
            ft_strstr(tmp, "CONE") ? printf("CONE ICI\n") : 0;
            ft_strstr(tmp, "CYLINDER") ? printf("CYLINDER ICI\n") : 0;
        }
        !ft_strncmp(tmp, "  radius=", 9) ? printf("'%f'\n", parse_value(tmp)) : 0;
        if (ft_strncmp(tmp, "  pos=", 6))
        {
            parse_xyz(tmp, v);
            printf("x %f\n", v->p_xyz.x);
            printf("y %f\n", v->p_xyz.y);
            printf("z %f\n", v->p_xyz.z);
        }
        if (ft_strncmp(tmp, "  dir=", 6))
        {
            parse_xyz(tmp, v);
            printf("x %f\n", v->p_xyz.x);
            printf("y %f\n", v->p_xyz.y);
            printf("z %f\n", v->p_xyz.z);
        }
        parse_material(v, tmp);
        ft_strdel(&file->line);
        ft_strdel(&tmp);
    }
    file->ob_n++;
}
