/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:58:38 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 15:40:52 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		mouse_motion_event(SDL_Event event, t_env *v)
{
    if (v->button_left == 1)
    {
		//if (event.motion.xrel > 0)
		//	v->p.ori.x = matrix_rotation();
		//if (event.motion.xrel < 0)
		//	v->p.ori.x -= 0.5;
		//if (event.motion.yrel > 0)
		//	v->p.ori.y += 0.5;
		//if (event.motion.yrel < 0)
		//	v->p.ori.y -= 0.5;
    }
}
