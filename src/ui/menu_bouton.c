/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bouton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/02 14:17:25 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		menu_bouton(t_env *v, int x, int y)
{
	if (y < 260 && y > 220 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[0];
	else if (y < 310 && y > 270 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[1];
	else if (y < 360 && y > 320 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[2];
	else if (y < 410 && y > 370 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[3];
}

void		menu_bouton_text(t_env *v)
{
	put_text(v, write_text_menu2(">    ADD SPHERE", 20), 190, 225);
	put_text(v, write_text_menu2(">    ADD CYLINDER", 20), 190, 275);
	put_text(v, write_text_menu2(">    ADD CONE", 20), 190, 325);
	put_text(v, write_text_menu2(">    ADD PLAN", 20), 190, 375);
}

int			mouse_location(SDL_Event e, t_between b)
{
	if (e.motion.x > b.min_x && e.motion.x < b.max_x &&
			e.motion.y > b.min_y && e.motion.y < b.max_y)
		return (1);
	return (0);
}

void		over_a_button(t_env *v, SDL_Event e)
{
	if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 220, 260}))
		v->hover[0] = get_hex_menu(255, 100, 114);
	else
		v->hover[0] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 270, 310}))
		v->hover[1] = get_hex_menu(255, 100, 114);
	else
		v->hover[1] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 320, 360}))
		v->hover[2] = get_hex_menu(255, 100, 114);
	else
		v->hover[2] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 370, 410}))
		v->hover[3] = get_hex_menu(255, 100, 114);
	else
		v->hover[3] = get_hex_menu(218, 112, 214);
}


void		is_it_a_button(t_env *v, SDL_Event e)
{
	if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 220, 260}))
		printf("function add a sphere\n");
	else if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 270, 310}))
		printf("function add a cylinder\n");
	else if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 320, 360}))
		printf("function add a cone\n");
	else if (mouse_location(e, (t_between){140, v->ui.m_w - 20, 370, 410}))
		printf("function add a plane\n");
}
