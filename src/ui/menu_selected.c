/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:34:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/06 19:32:23 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	selected_sphere(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("SPHERE", 22), 30, 325);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 21), 25, 460);
	put_text(v, write_text_menu2(info, 20), 100, 460);
	free(info);
	selected_pos(v);
}

void	selected_cylinder(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("CYLINDER", 22), 30, 325);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 21), 25, 460);
	put_text(v, write_text_menu2(info, 20), 100, 460);
	free(info);
	selected_pos(v);
	selected_dir(v);
}

void	selected_cone(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("CONE", 22), 30, 325);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 21), 25, 460);
	put_text(v, write_text_menu2(info, 20), 100, 460);
	free(info);
	selected_pos(v);
	selected_dir(v);
}

void	selected_plan_2(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("point c", 21), 25, 460);
	info = ft_ftoa(v->selected_obj->c.x, 3);
	put_text(v, write_text_menu2(info, 21), 100, 460);
	free(info);
	info = ft_ftoa(v->selected_obj->c.y, 3);
	put_text(v, write_text_menu2(info, 21), 100, 480);
	free(info);
	info = ft_ftoa(v->selected_obj->c.z, 3);
	put_text(v, write_text_menu2(info, 21), 100, 500);
	free(info);
}

void	selected_plan(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("PLAN", 22), 30, 325);
	put_text(v, write_text_menu2("point a", 21), 25, 380);
	info = ft_ftoa(v->selected_obj->a.x, 3);
	put_text(v, write_text_menu2(info, 21), 100, 380);
	free(info);
	info = ft_ftoa(v->selected_obj->a.y, 3);
	put_text(v, write_text_menu2(info, 21), 100, 400);
	free(info);
	info = ft_ftoa(v->selected_obj->a.z, 3);
	put_text(v, write_text_menu2(info, 21), 100, 420);
	free(info);
	put_text(v, write_text_menu2("point b", 21), 190, 380);
	info = ft_ftoa(v->selected_obj->b.x, 3);
	put_text(v, write_text_menu2(info, 21), 262, 380);
	free(info);
	info = ft_ftoa(v->selected_obj->b.y, 3);
	put_text(v, write_text_menu2(info, 21), 262, 400);
	free(info);
	info = ft_ftoa(v->selected_obj->b.z, 3);
	put_text(v, write_text_menu2(info, 21), 262, 420);
	free(info);
	selected_plan_2(v);
}
