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

t_asm	init_file(void)
{
	t_asm	*file;

	file = malloc(sizeof(file));
	file->name = NULL;
	file->comment = NULL;
	file->filename = NULL;
	file->magic = COREWAR_EXEC_MAGIC;
	file->code = NULL;
	return (file);
}

void	init_name(t_asm *file, char *line)
{
	char *p;
	int i;

	i = 0;
	file->name = ft_strnew(PROG_NAME_LENGTH);
	p = line;
	p += 5;
	p = point_jump(p);
	if (*p != '"')
		ft_error("invalid name");
	p++;
	while (p[i] != '"')
		i++;
	if (i > PROG_NAME_LENGTH)
		ft_error("name is very long");
	ft_strncpy(file->name, p, i);
	free(line);
}

void	init_comment(t_asm *file, char *line)
{
	char *p;
	int i;

	i = 0;
	file->comment = ft_strnew(COMMENT_LENGTH);
	p = line;
	p += 8;
	p = point_jump(p);
	if (*p != '"')
		ft_error("invalid comment");
	p++;
	while (p[i] != '"')
		i++;
	if (i > COMMENT_LENGTH)
		ft_error("comment is very long");
	ft_strncpy(file->comment, p, i);
	free(line);
}

void 		ft_parse_line(char *line, t_asm *file)
{
	char 	*p;

	// continued there
}