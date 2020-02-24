/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 18:04:50 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/24 14:51:20 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void            mouse_button_event(SDL_Event event, t_env *v)
{
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
		v->cam_mouv = 1;
    }
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		v->cam_mouv = 0;
	}
}
