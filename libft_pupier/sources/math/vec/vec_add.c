/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vec_add.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qpupier <qpupier@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/22 19:31:44 by qpupier      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 12:06:45 by qpupier     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

inline t_vec	vec_add(t_vec u, t_vec v)
{
	u.x += v.x;
	u.y += v.y;
	u.z += v.z;
	return (u);
}
