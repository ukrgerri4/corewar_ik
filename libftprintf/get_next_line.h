/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:47:11 by apoplavs          #+#    #+#             */
/*   Updated: 2017/01/27 13:31:34 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"

typedef struct	s_fd
{
	int			fd;
	char		*str;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);
#endif
