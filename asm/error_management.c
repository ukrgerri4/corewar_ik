/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 10:37:14 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/12 10:37:37 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void 	ft_error(char *str)
{
	ft_printf("ERROR : %s\n", str);
	exit(1);
}

char		*point_jump(char *p)
{
	while (*p && (*p == ' ' || *p == '\t'))
		p++;
	return (p);
}

void		del_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab[i]);
	free(tab);
}

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
		while (p->next)
			p = p->next;
		p->next = line;
	}
}

int 	correct_char(char c)
{
	if (ft_strchr(LABEL_CHARS, c)
		|| c == LABEL_CHAR || c == DIRECT_CHAR
		|| c == SEPARATOR_CHAR || c == '-'
		|| c == '+' || (c <= 'z' && c >= 'a')
		|| c == ' ' || c == '\t')
		return (1);
	else
		return (0);
}