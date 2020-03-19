/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:54:32 by nrivoire          #+#    #+#             */
/*   Updated: 2020/03/12 20:05:12 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		quit(t_env *v)
{
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyRenderer(v->ui.m_ren);
	SDL_DestroyWindow(v->win);
	SDL_DestroyWindow(v->ui.m_win);
	SDL_Quit();
	TTF_Quit();
}

void			draw_pro_frame(t_env *v)
{
	clear_pixels(v);
	create_tab_obj(v);
	if (v->ppc.active_rpx == 1)
	{
		if (v->ppc.render_key > 0 || v->ppc.render_mouse > 0)
			v->ppc.render_size = 4;
		else
			v->ppc.render_size = 1;
	}
	bouclette(v);
	v->ppc.ssp == 1 ? supersampling(v) : 0;
}

void			display_two(t_env *v)
{
	v->stats.frame_start = clock();
	draw_pro_frame(v);
	v->stats.frame = (clock() - v->stats.frame_start) / (float)CLOCKS_PER_SEC;
	menu(v);
	SDL_UpdateTexture(v->tex, NULL, v->pixels, sizeof(uint32_t) * v->w);
	SDL_UpdateTexture(v->ui.m_tex, NULL, v->ui.m_pixels, sizeof(uint32_t) *
			v->ui.m_w);
	SDL_RenderCopy(v->ren, v->tex, NULL, NULL);
	SDL_RenderCopy(v->ui.m_ren, v->ui.m_tex, NULL, NULL);
	SDL_RenderPresent(v->ren);
	SDL_RenderPresent(v->ui.m_ren);
}

void			event_management(SDL_Event e, t_env *v, const Uint8 *key_state,
		uint32_t mouse_state)
{
	if (e.type == SDL_KEYDOWN)
		key_event(v, key_state);
	if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
		mouse_button_event(e, v);
	if (e.type == SDL_MOUSEMOTION)
		if (SDL_GetMouseFocus() == v->win)
			mouse_motion_event(e, v, mouse_state);
		else if (SDL_GetMouseFocus() == v->ui.m_win)
			over_a_button(v, e);
	if (e.type == SDL_MOUSEWHEEL)
		mouse_wheel_event(e, v);
}

void			display(t_env *v)
{
	SDL_Event		e;
	const Uint8		*keyboard_state;
	uint32_t		mouse_state;

	put_icon(v);
	while (1)
	{
		keyboard_state = SDL_GetKeyboardState(NULL);
		mouse_state = SDL_GetMouseState(NULL, NULL);
		while (SDL_PollEvent(&e))
			event_management(e, v, keyboard_state, mouse_state);
		if (e.type == SDL_WINDOWEVENT &&
			e.window.event == SDL_WINDOWEVENT_CLOSE)
			if (SDL_GetWindowID(v->win) == e.window.windowID ||
			SDL_GetWindowID(v->ui.m_win) == e.window.windowID)
				break ;
		if (e.type == SDL_QUIT || key_event(v, keyboard_state))
			break ;
		display_two(v);
	}
	quit(v);
}
