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

void		read_filename(int fd, char *filename, t_asm	*file)
{
	char 	*line;

	check_filename(file, filename);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0')
			break ;
		else if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
			init_name(file, line);
		else if (ft_strncmp(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			init_comment(file, line);
		else if (line[0] == '#')
			free(line);
	}
	if (!file->filename || !file->comment || !file->name)
		ft_error("invalid file");
	free(line);
}

void		read_file(int fd, t_asm	*file)
{

}
