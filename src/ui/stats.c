/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasalome <vasalome@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:12:27 by vasalome          #+#    #+#             */
/*   Updated: 2020/05/15 11:15:43 by vasalome         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		ft_count_digit(long long int nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = (nb < 0) ? 1 : 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_lltoa(long long int nb)
{
	char	*str;
	int		i;
	int		neg;

	neg = (nb < 0) ? -1 : 1;
	i = ft_count_digit(nb);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

void			display_stats(t_env *v)
{
	long long	avant;
	long long	apres;
	long long	fps;
	char		*buffer;

	avant = (long long int)(v->stats.after.tv_sec * 1000LL\
				+ v->stats.after.tv_usec / 1000);
	apres = (long long int)(v->stats.before.tv_sec * 1000LL\
				+ v->stats.before.tv_usec / 1000);
	fps = (long long int)(1000 / (llabs((long long int)(avant - apres))));
	buffer = ft_lltoa(fps);
	put_text(v, write_text_stats("FPS:", 20), 10, 290);
	put_text(v, write_text_stats(buffer, 20), 60, 290);
	free(buffer);
}
