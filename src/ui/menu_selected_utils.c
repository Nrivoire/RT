/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_selected_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:34:36 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/06 19:07:09 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	selected_dir(t_env *v)
{
	char	*info;

	info = ft_ftoa(v->selected_obj->dir.x, 3);
	put_text(v, write_text_menu2("dir x =", 21), 190, 380);
	put_text(v, write_text_menu2(info, 21), 262, 380);
	free(info);
	info = ft_ftoa(v->selected_obj->dir.y, 3);
	put_text(v, write_text_menu2("dir y =", 21), 190, 400);
	put_text(v, write_text_menu2(info, 21), 262, 400);
	free(info);
	info = ft_ftoa(v->selected_obj->dir.z, 3);
	put_text(v, write_text_menu2("dir z =", 21), 190, 420);
	put_text(v, write_text_menu2(info, 21), 262, 420);
	free(info);
}

void	selected_pos(t_env *v)
{
	char	*info;

	info = ft_ftoa(v->selected_obj->pos.x, 3);
	put_text(v, write_text_menu2("pos x =", 21), 25, 380);
	put_text(v, write_text_menu2(info, 21), 100, 380);
	free(info);
	info = ft_ftoa(v->selected_obj->pos.y, 3);
	put_text(v, write_text_menu2("pos y =", 21), 25, 400);
	put_text(v, write_text_menu2(info, 21), 100, 400);
	free(info);
	info = ft_ftoa(v->selected_obj->pos.z, 3);
	put_text(v, write_text_menu2("pos z =", 21), 25, 420);
	put_text(v, write_text_menu2(info, 21), 100, 420);
	free(info);
}
