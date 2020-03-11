/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:21:14 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/11 15:21:17 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		selected_menu(t_env *v)
{
	if (v->selected_obj)
	{
		if (v->selected_obj->type == SPHERE)
			selected_sphere(v);
		if (v->selected_obj->type == PLAN)
			selected_plan(v);
		if (v->selected_obj->type == CONE)
			selected_cone(v);
		if (v->selected_obj->type == CYLINDER)
			selected_cylinder(v);
	}
}

static void	menu_text_2(t_env *v)
{
	char	*info[3];

	info[0] = ft_ftoa(v->cam.angle_x, 3);
	info[1] = ft_ftoa(v->cam.angle_y, 3);
	info[2] = ft_ftoa(v->cam.fov, 0);
	put_text(v, write_text_menu2("AngleX:", 20), 320, 70);
	put_text(v, write_text_menu2(info[0], 20), 395, 70);
	put_text(v, write_text_menu2("AngleY:", 20), 320, 105);
	put_text(v, write_text_menu2(info[1], 20), 395, 105);
	put_text(v, write_text_menu2("FOV:", 20), 320, 140);
	put_text(v, write_text_menu2(info[2], 20), 370, 140);
	free(info[0]);
	free(info[1]);
	free(info[2]);
}

void		menu_text(t_env *v)
{
	char	*info[3];

	put_text(v, write_text_menu2("scene :", 18), 30, 22);
	put_text(v, write_text_menu2(v->file, 18), 112, 22);
	info[0] = ft_ftoa(v->cam.ori.x, 3);
	info[1] = ft_ftoa(v->cam.ori.y, 3);
	info[2] = ft_ftoa(v->cam.ori.z, 3);
	put_text(v, write_text_menu2("X:", 20), 150, 70);
	put_text(v, write_text_menu2(info[0], 20), 175, 70);
	put_text(v, write_text_menu2("Y:", 20), 150, 105);
	put_text(v, write_text_menu2(info[1], 20), 175, 105);
	put_text(v, write_text_menu2("Z:", 20), 150, 140);
	put_text(v, write_text_menu2(info[2], 20), 175, 140);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	menu_text_2(v);
	selected_menu(v);
}

static void	menu_2(t_env *v, int x, int y)
{
	if (y < (v->ui.m_h - 20) && y > 450 && x > 20 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 50 && y > 20 && x > 20 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 100 && y > 70 && x > 140 && x < v->ui.m_w - 200)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 100 && y > 70 && x > (v->ui.m_w / 2) + 60 \
			&& x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 135 && y > 105 && x > 140 && x < v->ui.m_w - 200)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 135 && y > 105 && x > (v->ui.m_w / 2) + 60 \
			&& x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 170 && y > 140 && x > 140 && x < v->ui.m_w - 200)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else if (y < 170 && y > 140 && x > (v->ui.m_w / 2) + 60 \
			&& x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0, 255);
	else
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(255, 255, 255, 255);
}

void		menu(t_env *v)
{
	int		x;
	int		y;

	y = -1;
	while (++y < v->ui.m_h)
	{
		x = -1;
		while (++x < v->ui.m_w)
		{
			menu_2(v, x, y);
		}
	}
	menu_text(v);
}
