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
	file->magic = COREWAR_EXEC_MAGIC;
	file->code = NULL;
	file->prog_size = 0;
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

void	init_name(int fd, t_asm *file, char *line)
{
	char *p;
	int len;

	len = 0;
	file->name = ft_strnew(PROG_NAME_LENGTH);
	p = line;
	p = point_jump(p);
	p += 5;
	p = point_jump(p);
	if (*p != '"')
		ft_error("invalid name");
	p++;
	ft_strncpy(file->name, p, com_len(p, &len));
	if (!ft_strchr(line, '"'))
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_strncat(file->name, line, com_len(line, &len));
			if (ft_strchr(line, '"'))
				break ;
		}
	}
	if (len > PROG_NAME_LENGTH)
		ft_error("name is very long");
}

void	init_comment(int fd, t_asm *file, char *line)
{
	char *p;
	int len;

	len = 0;
	file->comment = ft_strnew(COMMENT_LENGTH);
	p = line;
	p = point_jump(p);
	p += 8;
	p = point_jump(p);
	if (*p != '"')
		ft_error("invalid comment");
	p++;
	ft_strncpy(file->comment, p, com_len(p, &len));
	if (!ft_strchr(line, '"'))
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_strncat(file->comment, line, com_len(line, &len));
			if (ft_strchr(line, '"'))
				break ;
		}
	}
	if (len > COMMENT_LENGTH)
		ft_error("comment is very long");
}

char 		**separate_line(char *line, int i, int l)
{
	char 	**tab;
	char 	*str;

	str = ft_strnew(ft_strlen(line) + 8);
	str[l] = line[i];
	while (line[i])
	{
		str[++l] = line[++i];
		if (line[i] == LABEL_CHAR && line[i - 1] != DIRECT_CHAR
			&& line[i - 1] != ' ' && line[i - 1] != SEPARATOR_CHAR)
			str[++l] = ' ';
		if (line[i] == DIRECT_CHAR
			|| (line[i] == '-' && ft_isdigit(line[i + 1])
				&& line[i - 1] != DIRECT_CHAR))
		{
			str[l + 1] = str[l];
			str[l++] = ' ';
		}
		if (str[l] == SEPARATOR_CHAR && str[l - 1] == ' ')
		{
			while (str[l - 1] == ' ')
				l--;
			str[l] = SEPARATOR_CHAR;
		}
	}
	tab = ft_strsplit(str, ' ');
	free(str);
	return (tab);
}

void		trim_line(char *line, t_asm *file)
{
	char 	**tab;
	int 	i;
	t_line	*s;

	i = 0;
	convert_tabs(line);
	s = file->code;
	while (s->next)
		s = s->next;
	s->line = ft_strnew(ft_strlen(line));
	tab = separate_line(line, 0, 0);
	ft_strcpy(s->line, tab[0]);
	while (tab[++i])
	{
		if (s->line[ft_strlen(s->line) - 1] != SEPARATOR_CHAR)
			s->line[ft_strlen(s->line)] = ' ';
		ft_strcat(s->line, tab[i]);
	}
	free(line);
	line = ft_strchr(s->line, COMMENT_CHAR);
	ft_strclr(line);
	if (s->line[ft_strlen(s->line) - 1] == ' ')
		s->line[ft_strlen(s->line) - 1] = '\0';
	del_tab(tab);
}








































































