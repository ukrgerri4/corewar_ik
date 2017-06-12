/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 12:41:20 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/11 12:41:31 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char 		**separate_line(char *line, int i, int l, char 	*str)
{
	char 	**tab;

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
	tab = separate_line(line, 0, 0, ft_strnew(ft_strlen(line) + 8));
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

