/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 17:54:32 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/03/05 13:43:57 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rt.h"

static int		get_hex_rgba(int r, int g, int b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | (a));
}

void			pixel_put(t_env *v, int x, int y, t_color color)
{
	if (x >= v->w || y >= v->h || x < 0 || y < 0)
		return ;

	if (color.r > 1)
		color.r = 1;
	if (color.g > 1)
		color.g = 1;
	if (color.b > 1)
		color.b = 1;
	if (v->p.sc.filter == 0)
		v->pixels[y * v->w + x] = get_hex_rgba(color.r * 255, color.g * 255, color.b * 255, color.a);
	else if (v->p.sc.filter == 1)
		v->pixels[y * v->w + x] = greyscale(get_hex_rgba(color.r * 255, color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 2)
		v->pixels[y * v->w + x] = sepia(get_hex_rgba(color.r * 255, color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 3)
		v->pixels[y * v->w + x] = negative(get_hex_rgba(color.r * 255, color.g * 255, color.b * 255, color.a));
	else if (v->p.sc.filter == 4)
		v->pixels[y * v->w + x] = cel_shading(get_hex_rgba(color.r * 255, color.g * 255, color.b * 255, color.a));
}

static void		quit(t_env *v)
{
	SDL_DestroyRenderer(v->ren);
	SDL_DestroyRenderer(v->ui.m_ren);
	SDL_DestroyWindow(v->win);
	SDL_DestroyWindow(v->ui.m_win);
	SDL_Quit();
	TTF_Quit();
}

void			clear_pixels(t_env *v)
{
	int			x;
	int			y;

	y = -1;
	while (++y <= v->h)
	{
		x = -1;
		while (++x <= v->w)
			pixel_put(v, x, y, (t_color){0, 0, 0, 255});
	}
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
		{
			if (e.type == SDL_KEYDOWN)
				key_event(v, keyboard_state);
			if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
				mouse_button_event(e, v);
			if (e.type == SDL_MOUSEMOTION)
				mouse_motion_event(e, v, mouse_state);
			if (e.type == SDL_MOUSEWHEEL)
				mouse_wheel_event(e, v);
		}
		if (e.type == SDL_QUIT || key_event(v, keyboard_state))
			break ;
		// if (e.type == SDL_WINDOWEVENT)
		// 	close_by_cross(v, e);   TRY TO CLOSE WITH CROSS - MULTIPLE WINDOWS
		v->stats.frame_start = clock();
		draw_pro_frame(v);
		display_stats(v);
		v->stats.frame = (clock() - v->stats.frame_start) / (float)CLOCKS_PER_SEC;
		menu(v);
		SDL_UpdateTexture(v->tex, NULL, v->pixels, sizeof(uint32_t) * v->w);
		SDL_UpdateTexture(v->ui.m_tex, NULL, v->ui.m_pixels, sizeof(uint32_t) * v->ui.m_w);
		SDL_RenderCopy(v->ren, v->tex, NULL, NULL);
		SDL_RenderCopy(v->ui.m_ren, v->ui.m_tex, NULL, NULL);
		SDL_RenderPresent(v->ren);
		SDL_RenderPresent(v->ui.m_ren);
	}
	quit(v);
}
