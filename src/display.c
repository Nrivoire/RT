/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:54:32 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 14:02:15 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_env *v, int x, int y, t_rgb color)
{
	if (x >= v->w || y >= v->h || x < 0 || y < 0)
		return ;
	v->pixels[y * v->w + x] = get_hex_rgba(color.r, color.g, color.b, color.a);
}

static void		quit(t_env *v)
{
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyWindow(v->win);
	SDL_Quit();
	TTF_Quit();
}

void			display(t_env *v)
{
	SDL_Event	e;
	const Uint8	*keyboard_state;

	while (1)
	{
		keyboard_state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_KEYDOWN)
				key_event(keyboard_state);
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
				mouse_button_event(e, v);
			if (e.type == SDL_MOUSEMOTION)
				mouse_motion_event(e, v);
		}
		if (e.type == SDL_QUIT || key_event(keyboard_state))
			break ;
		bouclette(v);
		//draw_pro_frame(v, e);
		SDL_UpdateTexture(v->tex, NULL, v->pixels, sizeof(uint32_t) * v->w);
		SDL_RenderCopy(v->ren, v->tex, NULL, NULL);
		SDL_RenderPresent(v->ren);
	}
	quit(v);
}