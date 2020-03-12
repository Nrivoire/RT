/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_bouton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 20:53:06 by vasalome          #+#    #+#             */
/*   Updated: 2020/03/12 20:53:08 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		menu_bouton(t_env *v, int x, int y)
{
	if (y < 260 && y > 220 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(218, 112, 214, 255);
	else if (y < 310 && y > 270 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(218, 112, 214, 255);
	else if (y < 360 && y > 320 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(218, 112, 214, 255);
	else if (y < 410 && y > 370 && x > 140 && x < v->ui.m_w - 20)
		v->ui.m_pixels[y * v->ui.m_w + x] = get_hex_menu(218, 112, 214, 255);
}

void		menu_bouton_text(t_env *v)
{
	put_text(v, write_text_menu2(">    ADD SPHERE", 20), 190, 225);
	put_text(v, write_text_menu2(">    ADD CYLINDER", 20), 190, 275);
	put_text(v, write_text_menu2(">    ADD CONE", 20), 190, 325);
	put_text(v, write_text_menu2(">    ADD PLAN", 20), 190, 375);
}
