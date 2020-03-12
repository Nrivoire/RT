/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrivoire <nrivoire@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:57:18 by qpupier           #+#    #+#             */
/*   Updated: 2020/03/12 19:30:49 by nrivoire         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 56

# include <stdlib.h>
# include <unistd.h>
# include "../includes/libft.h"

typedef struct	s_gnl
{
	int				fd;
	char			*save;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(int fd, char **line);
#endif
