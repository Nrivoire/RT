/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 21:21:34 by qpupier           #+#    #+#             */
/*   Updated: 2020/04/12 21:21:49 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"





// EXEMPLE TROUVÉ / INSPIRATION
/*void		checkboard(t_tab_obj obj)
{
	int		xStep, yStep, zStep, sumStep;

	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			for (int z = 0; z < texDepth; z++)
			{
				xStep = (x/10) % 2;
				yStep = (y/10) % 2;
				zStep = (z/10) % 2;
				sumStep = xStep + yStep + zStep;
				if ((sumStep % 2) == 0)
					tex3Dpattern[x][y][z] = 0.0;
				else
					tex3Dpattern[x][y][z] = 1.0;
			}
		}
	}
}*/
