/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:41:07 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/17 14:06:39 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_no_code(char *line)
{
	int	i;

	i = 0;
	if (line[0] == COMMENT_CHAR)
		return (1);
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			return (1);
		if (line[i] != '\t' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	create_filename_fd(t_asm *file)
{
	char	*f_name;

	if (!(f_name = ft_strjoin(file->filename, ".cor")))
		exit(1);
	file->fd_filename = open(f_name, O_WRONLY | O_TRUNC |
			O_CREAT, S_IREAD | S_IWRITE);
	ft_strdel(&f_name);
}

void	read_filename(int fd, char *filename, t_asm *file)
{
	char	*line;

	check_filename(file, filename);
	while (get_next_line(fd, &line) > 0)
	{
		if (is_no_code(line))
			line[0] = '\0';
		else if (ft_strstr(line, NAME_CMD_STRING))
			init_name(fd, file, line);
		else if (ft_strstr(line, COMMENT_CMD_STRING))
			init_comment(fd, file, line);
		else
			exit_notice("invalid instruction ", line);
		ft_strdel(&line);
		if (file->name && file->comment)
			break ;
	}
	if (!file->filename || !file->comment || !file->name)
		ft_error("invalid file");
	create_filename_fd(file);
}

void	check_end_file(int fd)
{
	char	*line;
	long	position;
	size_t	i;

	position = lseek(fd, -1L, SEEK_END);
	if (position == -1L || position >= 65535)
		ft_error("invalid file");
	line = ft_strnew((size_t)position);
	lseek(fd, 0L, SEEK_SET);
	if (read(fd, line, 65535) == -1)
		ft_error("no empty line in end of the file");
	i = ft_strlen(line) - 1;
	while (i > 0 && (line[i] == ' ' || line[i] == '\t'))
		i--;
	if (line[i] != '\n')
		ft_error("no empty line in end of the file");
	free(line);
}

void	read_file(int fd, t_asm *file)
{
	char	*line;

	make_line(file);
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] == '\0' || is_no_code(line))
			free(line);
		else if (ft_strchr(LABEL_CHARS, line[0]) ||
				line[0] == ' ' || line[0] == '\t')
		{
			trim_line(line, file);
			make_line(file);
		}
		else
			exit_notice("invalid instruction ", line);
	}
	free(line);
	check_end_file(fd);
	if (!file->code->line)
		ft_error("no code");
}
