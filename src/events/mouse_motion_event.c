/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_motion_event.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:58:38 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/19 17:44:37 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		mouse_motion_event(SDL_Event event, t_env *v)
{
	t_matrix_3_3	rot;

    if (v->button_left == 1)
    {
		if (event.motion.xrel > 0 || event.motion.xrel < 0)
			v->cam_angle_x = event.motion.yrel * 0.1 * (M_PI / 180);
		if (event.motion.yrel > 0 || event.motion.yrel < 0)
			v->cam_angle_y = event.motion.xrel * 0.1 * (M_PI / 180);
		matrix_rotation(event.motion.yrel * 0.1 * M_PI / 180, event.motion.xrel * 0.1 * M_PI / 180, 0, rot);
		v->cam_ori = matrix_mult_vec(rot, v->cam_ori);
		SDL_SetRelativeMouseMode(SDL_TRUE);
    }
}
