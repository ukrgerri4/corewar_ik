/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 12:01:52 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 12:02:15 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_asm	*init_file(void)
{
	t_asm	*file;

	file = malloc(sizeof(t_asm));
	file->name = NULL;
	file->comment = NULL;
	file->filename = NULL;
	file->code = NULL;
	file->code = NULL;
	file->header = NULL;
	file->prog = NULL;
	file->prog_len = 0;
	file->i = 0;
	file->arg_byte = 0;
	file->command_byte = 0;
	file->mark = 0;
	return (file);
}

size_t 		com_len(char *p, int *len)
{
	size_t i;

	i = 0;
	while (p[i] && p[i] != '"')
		i++;
	*len += i;
	return (i);
}

void	move_point(char *line, char **p, int dist)
{
	*p = line;
	*p = point_jump(*p);
	*p += dist;
	*p = point_jump(*p);
}

void	init_name(int fd, t_asm *file, char *line)
{
	char *p;
	int len;

	len = 0;
	file->name = ft_strnew(PROG_NAME_LENGTH);
	move_point(line, &p, 5);
	if (*p != '"')
		ft_error("invalid name");
	p++;
	ft_strncpy(file->name, p, com_len(p, &len));
	if (!ft_strchr(p, '"'))
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_strncat(file->name, line, com_len(line, &len));
			if (ft_strchr(line, '"'))
				break ;
			file->name[ft_strlen(file->name)] = '\n';
			free(line);
		}
		free(line);
	}
	if (len > PROG_NAME_LENGTH)
		ft_error("name is very long");
}

void	init_comment(int fd, t_asm *file, char *line, int len)
{
	char *p;

	file->comment = ft_strnew(COMMENT_LENGTH);
	move_point(line, &p, 8);
	if (*p != '"')
		ft_error("invalid comment");
	p++;
	ft_strncpy(file->comment, p, com_len(p, &len));
	if (!ft_strchr(p, '"'))
	{
		free(line);
		while (get_next_line(fd, &line) > 0)
		{
			ft_strncat(file->comment, line, com_len(line, &len));
			if (ft_strchr(line, '"'))
				break ;
			file->comment[ft_strlen(file->comment)] = '\n';
			free(line);
		}
	}
	free(line);
	if (len > COMMENT_LENGTH)
		ft_error("comment is very long");
}







































































