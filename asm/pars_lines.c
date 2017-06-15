/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:51:26 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/15 14:53:52 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_link(char *link, t_line *lines)
{
	link++;
	while (lines->next)
	{
		if (ft_strnequ(link, lines->line, ft_strlen(link))
				&& lines->line[ft_strlen(link)] == LABEL_CHAR)
			return ;
		lines = lines->next;
	}
	link--;
	exit_notice("invalid link ", link);
}

void	check_links(char **params, t_line *lines)
{
	char	*s;

	if ((s = ft_strchr(params[0], LABEL_CHAR)))
		check_link(s, lines);
	if (params[1] && (s = ft_strchr(params[1], LABEL_CHAR)))
		check_link(s, lines);
	if (params[1] && params[2] && (s = ft_strchr(params[2], LABEL_CHAR)))
		check_link(s, lines);
}

void	parse3(char **tab, char **params, t_line *lines)
{
	char	a1;
	char	a2;
	char	a3;
	int		i;

	check_label_name(tab[0]);
	set_args(&a1, &a2, &a3, params);
	i = get_instruction(tab[1]);
	check_arguments(a1, a2, a3, i);
	check_links(params, lines);
	del_tab(params);
}

void	parse2(char **tab, char **params, t_line *lines)
{
	char	a1;
	char	a2;
	char	a3;
	int		i;

	set_args(&a1, &a2, &a3, params);
	i = get_instruction(tab[0]);
	check_arguments(a1, a2, a3, i);
	check_links(params, lines);
	del_tab(params);
}

void	ft_parse_lines(t_line *str)
{
	char	**tab;
	t_line	*start;

	start = str;
	while (str->next)
	{
		if (str->line[ft_strlen(str->line) - 1] == SEPARATOR_CHAR
				|| ft_strstr(str->line, ",,"))
			exit_notice("Syntax error at token ", str->line);
		tab = ft_strsplit(str->line, ' ');
		if (tab[0] && tab[1] && tab[2] && !tab[3])
			parse3(tab, ft_strsplit(tab[2], SEPARATOR_CHAR), start);
		else if (tab[0] && tab[1] && !tab[2])
			parse2(tab, ft_strsplit(tab[1], SEPARATOR_CHAR), start);
		else if (tab[0] && !tab[1])
			check_label_name(tab[0]);
		else
			exit_notice("invalid instruction ", str->line);
		del_tab(tab);
		str = str->next;
	}
}
