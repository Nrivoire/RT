/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:21:14 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/14 14:54:23 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		selected_menu(t_env *v)
{
	if (v->selected_obj)
	{
		put_text(v, write_text_stats("Object menu:", 18), 10, 180);
		put_text(v, write_text_stats("W +SPACE: move +y", 19), 130, 180);
		put_text(v, write_text_stats("S +SPACE: move -y", 19), 130, 200);
		put_text(v, write_text_stats("A +SPACE: move -x", 19), 130, 220);
		put_text(v, write_text_stats("D +SPACE: move +x", 19), 130, 240);
		put_text(v, write_text_stats("E +SPACE: move +z", 19), 130, 260);
		put_text(v, write_text_stats("Q +SPACE: move -z", 19), 130, 280);
		if (v->selected_obj->type == SPHERE)
			selected_sphere(v);
		if (v->selected_obj->type == PLAN)
			selected_plan(v);
		if (v->selected_obj->type == CONE)
			selected_cone(v);
		if (v->selected_obj->type == CYLINDER)
			selected_cylinder(v);
	}
	else
		put_text(v, write_text_stats("click an object to select", 18), 10, 180);
}

static void	menu_text_2(t_env *v)
{
	char	*info[3];

	info[0] = ft_ftoa(ft_rad_to_deg(v->cam.angle_x), 3);
	info[1] = ft_ftoa(ft_rad_to_deg(v->cam.angle_y), 3);
	info[2] = ft_ftoa(ft_rad_to_deg(v->cam.angle_z), 3);
	put_text(v, write_text_menu2("angle x:", 22), 199, 62);
	put_text(v, write_text_menu2(info[0], 24), 280, 62);
	put_text(v, write_text_menu2("angle y:", 22), 199, 97);
	put_text(v, write_text_menu2(info[1], 24), 280, 97);
	put_text(v, write_text_menu2("angle z:", 22), 199, 132);
	put_text(v, write_text_menu2(info[2], 24), 280, 132);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	if (v->ppc.render_size == 4)
		put_text(v, write_text_menu("Loading...", 22), 260, 165);
}

void		menu_text(t_env *v)
{
	char	*info[3];

	put_text(v, write_text_menu2("scene :", 20), 20, 17);
	put_text(v, write_text_menu2(v->file, 20), 95, 17);
	info[0] = ft_ftoa(v->cam.ori.x, 3);
	info[1] = ft_ftoa(v->cam.ori.y, 3);
	info[2] = ft_ftoa(v->cam.ori.z, 3);
	put_text(v, write_text_menu2("x:", 22), 20, 62);
	put_text(v, write_text_menu2(info[0], 24), 45, 62);
	put_text(v, write_text_menu2("y:", 22), 20, 97);
	put_text(v, write_text_menu2(info[1], 24), 45, 97);
	put_text(v, write_text_menu2("z:", 22), 20, 132);
	put_text(v, write_text_menu2(info[2], 24), 45, 132);
	free(info[0]);
	free(info[1]);
	free(info[2]);
	menu_text_2(v);
	display_stats(v);
	selected_menu(v);
}

static void	menu_2(t_env *v, int x, int y)
{
	if (y < (v->ui.m_h - 10) && y > 310 && x > 10 && x < v->ui.m_w - 10)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 40 && y > 10 && x > 10 && x < v->ui.m_w - 10)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 85 && y > 55 && x > 10 && x < (v->ui.m_w / 2) - 2)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 85 && y > 55 && x > (v->ui.m_w / 2) + 2 \
			&& x < v->ui.m_w - 10)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 120 && y > 90 && x > 10 && x < (v->ui.m_w / 2) - 2)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 120 && y > 90 && x > (v->ui.m_w / 2) + 2 \
			&& x < v->ui.m_w - 10)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 155 && y > 125 && x > 10 && x < (v->ui.m_w / 2) - 2)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else if (y < 155 && y > 125 && x > (v->ui.m_w / 2) + 2 \
			&& x < v->ui.m_w - 10)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(0, 0, 0);
	else
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(255, 255, 255);
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
