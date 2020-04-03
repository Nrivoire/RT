/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpupier <qpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:59:22 by nrivoire          #+#    #+#             */
/*   Updated: 2020/04/02 14:08:46 by qpupier          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int				*init_permutation(void)
{
	int	*p;
	int	i;
	int	permutation[256] = {151, 160, 137, 91, 90, 15, 131, 13, 201, 95,
		96, 53, 194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21,
		10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219,
		203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125,
		136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146,
		158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55,
		46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209,
		76, 132, 187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86,
		164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5,
		202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58,
		17, 182, 189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163
		, 70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108
		, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34
		, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249
		, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176
		, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67,
		29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180};

// A changer IMPERATIVEMENT
	if (!(p = malloc(sizeof(int) * 512)))
		ft_error("Malloc error : _init_permutation");
	i = -1;
	while (++i < 512)
		p[i] = permutation[i & 255];
	return (p);
}

float			grad(int hash, float x, float y, float z)
{
	int			h;
	float		u;
	float		v;
	float		res;

	h = hash & 15;
	u = h < 8 ? x : y;
	if (h < 4)
		v = y;
	else if (h == 12 || h == 14)
		v = x;
	else
		v = z;
	res = ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
	return (res);
}

float			lerp(float t, float a, float b)
{
	return (a + t * (b - a));
}

void			init_noise(t_noise *n, float x, float y, float z)
{
	n->xi = (int)floor(x) & 255;
	n->yi = (int)floor(y) & 255;
	n->zi = (int)floor(z) & 255;
	x -= (int)floor(x);
	y -= (int)floor(y);
	z -= (int)floor(z);
	n->u = x * x * x * (x * (x * 6 - 15) + 10);
	n->v = y * y * y * (y * (y * 6 - 15) + 10);
	n->w = z * z * z * (z * (z * 6 - 15) + 10);
}

float			noise(float x, float y, float z)
{
	t_noise		n;
	int			*p;

	init_noise(&n, x, y, z);
	x -= (int)floor(x);
	y -= (int)floor(y);
	z -= (int)floor(z);
	p = init_permutation();
	return (
		(lerp(n.w,
			lerp(n.v,
				lerp(n.u, grad(p[p[n.xi] + n.yi] + n.zi, x, y, z),
						grad(p[p[n.xi + 1] + n.yi] + n.zi, x - 1, y, z)),
				lerp(n.u, grad(p[p[n.xi] + n.yi + 1] + n.zi, x, y - 1, z),
						grad(p[p[n.xi + 1] + n.yi + 1] + n.zi, x - 1, y - 1,
								z))),
			lerp(n.v,
				lerp(n.u, grad(p[p[n.xi] + n.yi] + n.zi + 1, x, y, z - 1),
					grad(p[p[n.xi + 1] + n.yi] + n.zi + 1, x - 1, y, z - 1)),
				lerp(n.u, grad(p[p[n.xi] + n.yi + 1] + n.zi + 1, x, y - 1,
						z - 1),
					grad(p[p[n.xi + 1] + n.yi + 1] + n.zi + 1, x - 1, y - 1,
								z - 1)))) + 1) / 2);
}
