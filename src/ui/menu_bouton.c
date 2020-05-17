/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bouton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/17 19:31:22 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		menu_bouton(t_env *v, int x, int y)
{
	Uint32	button_color_add;

	if (y < 230 && y > 190 && x > 10 && x < 185)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[0];
	else if (y < 230 && y > 190 && x > 187 + 2 && x < 365)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[1];
	else if (y < 275 && y > 235 && x > 10 && x < 185)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[2];
	else if (y < 275 && y > 235 && x > 187 + 2 && x < 365)
		v->ui.m_pixels[y * v->ui.m_w + x] = v->hover[3];
	button_color_add = get_hex_menu(50, 50, 200);
	if (v->add_new_obj == 1)
		v->hover[0] = button_color_add;
	else if (v->add_new_obj == 4)
		v->hover[1] = button_color_add;
	else if (v->add_new_obj == 3)
		v->hover[2] = button_color_add;
	else if (v->add_new_obj == 2)
		v->hover[3] = button_color_add;
}

void		menu_bouton_text(t_env *v)
{
	put_text(v, write_text_stats("Add:", 18), 10, 172);
	put_text(v, write_text_menu2("> SPHERE", 22), 30, 203);
	put_text(v, write_text_menu2("> CYLINDER", 22), 187 + 22, 203);
	put_text(v, write_text_menu2("> CONE", 22), 30, 247);
	put_text(v, write_text_menu2("> PLANE", 22), 187 + 22, 247);
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
	if (mouse_location(e, (t_between){10, 185, 190, 230}))
		v->hover[0] = get_hex_menu(255, 100, 114);
	else
		v->hover[0] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){189, 365, 190, 230}))
		v->hover[1] = get_hex_menu(255, 100, 114);
	else
		v->hover[1] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){10, 185, 235, 275}))
		v->hover[2] = get_hex_menu(255, 100, 114);
	else
		v->hover[2] = get_hex_menu(218, 112, 214);
	if (mouse_location(e, (t_between){189, 365, 235, 275}))
		v->hover[3] = get_hex_menu(255, 100, 114);
	else
		v->hover[3] = get_hex_menu(218, 112, 214);
}

int		is_it_a_button(SDL_Event e)
{
	if (mouse_location(e, (t_between){10, 185, 190, 230}))
		return (1);
	else if (mouse_location(e, (t_between){189, 365, 190, 230}))
		return (4);
	else if (mouse_location(e, (t_between){10, 185, 235, 275}))
		return (3);
	else if (mouse_location(e, (t_between){189, 365, 235, 275}))
		return (2);
	return (0);
}
