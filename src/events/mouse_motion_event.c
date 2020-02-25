/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:58:38 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/25 15:34:28 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		mouse_motion_event(SDL_Event event, t_env *v, uint32_t mouse_state)
{
    if (mouse_state == 1)
    {
		if (abs(event.motion.xrel) > abs(event.motion.yrel))
			v->cam.angle_y -= (event.motion.xrel * 0.1) * (M_PI / 180);
		else
			v->cam.angle_x += (event.motion.yrel * 0.1) * (M_PI / 180);
		SDL_SetRelativeMouseMode(SDL_TRUE);
    }
	if (mouse_state == 4)
    {
		if (event.motion.xrel > 0 || event.motion.xrel < 0)
			v->cam.ori.x += event.motion.xrel * 0.05;
		if (event.motion.yrel > 0 || event.motion.yrel < 0)
			v->cam.ori.y -= event.motion.yrel * 0.05;
    }
}
