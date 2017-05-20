/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:41:07 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 10:41:33 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		make_line(t_asm *file)
{
	t_line	*line;
	t_line	*p;

	line = malloc(sizeof(t_line));
	line->line = NULL;
	line->next = NULL;
	if (!file->code)
		file->code = line;
	else
	{
		p = file->code;
		while (p && p->next)
			p = p->next;
		p->next = line;
	}
}

void		read_filename(int fd, char *filename, t_asm	*file)
{
	char 	*line;

	check_filename(file, filename);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == COMMENT_CHAR || line[0] == '\0')
			continue;
		else if (ft_strnequ(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			init_name(fd, file, line);
		else if (ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			init_comment(fd, file, line);
		else
			ft_error(ft_strjoin("\ninvalid instruction : ", line));
		if (file->name && file->comment)
			break ;
		ft_strdel(&line);
	}
	if (!file->filename || !file->comment || !file->name)
		ft_error("invalid file");
}

void		read_file(int fd, t_asm *file)
{
	char 	*line;

	make_line(file);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0' || line[0] == COMMENT_CHAR)
			free(line);
		else if (ft_strchr(LABEL_CHARS, line[0])
				 || line[0] == ' ' || line[0] == '\t')
		{
			trim_line(line, file);
			make_line(file);
		}
		else
			ft_error(ft_strjoin("\ninvalid instruction : ", line));
	}
}
