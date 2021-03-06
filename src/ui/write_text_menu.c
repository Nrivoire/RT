/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_text_menu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacket <jacket@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:43:53 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/06 17:58:17 by jacket           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Surface		*write_text_menu2(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/forced-square.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Blended(font, text, (SDL_Color){255, 255, 255, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

SDL_Surface		*write_text_menu(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/forced-square.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Blended(font, text, (SDL_Color){0, 0, 0, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}

SDL_Surface		*write_text_stats(char *text, int size_font)
{
	TTF_Font	*font;
	SDL_Surface	*sur;

	if (TTF_Init() == -1)
		ft_error("Initialisation error of TFT_Init");
	font = NULL;
	font = TTF_OpenFont("./src/ui/ttf/forced-square.ttf", size_font);
	if (!font)
		ft_error("font error");
	sur = TTF_RenderText_Blended(font, text, (SDL_Color){0, 0, 0, 0});
	TTF_CloseFont(font);
	TTF_Quit();
	return (sur);
}
