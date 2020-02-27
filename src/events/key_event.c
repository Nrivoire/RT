/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_event.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 18:05:31 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/27 19:00:50 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

int         key_event(t_env *v, const Uint8 *keyboard_state)
{
    if (keyboard_state[SDL_SCANCODE_ESCAPE])
        return (1);
    if (v->selected_obj)
    {
        if (keyboard_state[SDL_SCANCODE_UP])
            v->selected_obj->pos.y += .5;
        if (keyboard_state[SDL_SCANCODE_DOWN])
            v->selected_obj->pos.y -= .5;
        if (keyboard_state[SDL_SCANCODE_RIGHT])
            v->selected_obj->pos.x += .5;
        if (keyboard_state[SDL_SCANCODE_LEFT])
            v->selected_obj->pos.x -= .5;
    }
    if (keyboard_state[SDL_SCANCODE_KP_MINUS])
        v->cam.ori.z--;
    if (keyboard_state[SDL_SCANCODE_KP_PLUS])
        v->cam.ori.z++;
    return (0);
}
