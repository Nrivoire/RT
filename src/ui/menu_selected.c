/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:34:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/11 14:34:39 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	selected_sphere(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("SPHERE", 22), 50, 455);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 20), 50, 500);
	put_text(v, write_text_menu2(info, 20), 140, 500);
	free(info);
	selected_pos(v);
}

void	selected_cylinder(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("CYLINDER", 22), 50, 455);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 20), 50, 500);
	put_text(v, write_text_menu2(info, 20), 140, 500);
	free(info);
	selected_pos(v);
	selected_dir(v);
}

void	selected_cone(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("CONE", 22), 50, 455);
	info = ft_ftoa(v->selected_obj->radius, 3);
	put_text(v, write_text_menu2("radius =", 20), 50, 500);
	put_text(v, write_text_menu2(info, 20), 140, 500);
	free(info);
	selected_pos(v);
	selected_dir(v);
}

void	selected_plan_2(t_env *v)
{
	char	*info;

	info = ft_ftoa(v->selected_obj->c.x, 3);
	put_text(v, write_text_menu2("point C =", 20), 250, 530);
	put_text(v, write_text_menu2(info, 20), 340, 530);
	free(info);
	info = ft_ftoa(v->selected_obj->c.y, 3);
	put_text(v, write_text_menu2(info, 20), 340, 550);
	free(info);
	info = ft_ftoa(v->selected_obj->c.z, 3);
	put_text(v, write_text_menu2(info, 20), 340, 570);
	free(info);
}

void	selected_plan(t_env *v)
{
	char	*info;

	put_text(v, write_text_menu2("PLAN", 22), 50, 455);
	info = ft_ftoa(v->selected_obj->a.x, 3);
	put_text(v, write_text_menu2("point A =", 20), 50, 530);
	put_text(v, write_text_menu2(info, 20), 140, 530);
	free(info);
	info = ft_ftoa(v->selected_obj->a.y, 3);
	put_text(v, write_text_menu2(info, 20), 140, 550);
	free(info);
	info = ft_ftoa(v->selected_obj->a.z, 3);
	put_text(v, write_text_menu2(info, 20), 140, 570);
	free(info);
	info = ft_ftoa(v->selected_obj->b.x, 3);
	put_text(v, write_text_menu2("point B =", 20), 50, 600);
	put_text(v, write_text_menu2(info, 20), 140, 600);
	free(info);
	info = ft_ftoa(v->selected_obj->b.y, 3);
	put_text(v, write_text_menu2(info, 20), 140, 620);
	free(info);
	info = ft_ftoa(v->selected_obj->b.z, 3);
	put_text(v, write_text_menu2(info, 20), 140, 640);
	free(info);
	selected_plan_2(v);
}
