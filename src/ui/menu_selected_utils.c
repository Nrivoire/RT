/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:34:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/04/12 21:22:50 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	selected_dir(t_env *v)
{
	char	*info;

	info = ft_ftoa(v->selected_obj->dir.x, 3);
	put_text(v, write_text_menu2("dir x =", 20), 250, 530);
	put_text(v, write_text_menu2(info, 20), 330, 530);
	free(info);
	info = ft_ftoa(v->selected_obj->dir.y, 3);
	put_text(v, write_text_menu2("dir y =", 20), 250, 550);
	put_text(v, write_text_menu2(info, 20), 330, 550);
	free(info);
	info = ft_ftoa(v->selected_obj->dir.z, 3);
	put_text(v, write_text_menu2("dir z =", 20), 250, 570);
	put_text(v, write_text_menu2(info, 20), 330, 570);
	free(info);
}

void	selected_pos(t_env *v)
{
	char	*info;

	info = ft_ftoa(v->selected_obj->pos.x, 3);
	put_text(v, write_text_menu2("pos x =", 20), 50, 530);
	put_text(v, write_text_menu2(info, 20), 140, 530);
	free(info);
	info = ft_ftoa(v->selected_obj->pos.y, 3);
	put_text(v, write_text_menu2("pos y =", 20), 50, 550);
	put_text(v, write_text_menu2(info, 20), 140, 550);
	free(info);
	info = ft_ftoa(v->selected_obj->pos.z, 3);
	put_text(v, write_text_menu2("pos z =", 20), 50, 570);
	put_text(v, write_text_menu2(info, 20), 140, 570);
	free(info);
}
