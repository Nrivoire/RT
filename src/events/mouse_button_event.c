/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/27 14:11:16 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 19:14:19 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

void		mouse_button_event(SDL_Event e, t_env *v)
{
	t_tab_obj	tmp;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{

			if (closest_intersect(v, create_ray_cam(v, e.button.x, e.button.y), &tmp))
			{
				if (v->selected_obj && v->selected_obj->i == tmp.i)
					v->selected_obj = NULL;
				else
				{
					v->selected_obj = &v->tab_obj[tmp.i];
					v->selected_obj->i = tmp.i;
				}
			}
			else
				v->selected_obj = NULL;
		}
	}
}
