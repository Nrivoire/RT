/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_pixel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 13:56:43 by nrivoire     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 18:24:20 by nrivoire    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/rt.h"

Uint32			get_pixel(SDL_Surface *surface, int x, int y)
{
	int			bpp;
	Uint8		*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16 *)p);
	else if (bpp == 3)
		return (p[0] | p[1] << 8 | p[2] << 16);
	else if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
	//natacha
}
