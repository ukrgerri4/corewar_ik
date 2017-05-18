/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:51:26 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/17 20:51:37 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char 		type_arg(char *arg)
{
	if (arg[0] == 'r' && ft_isdigit(arg[1]))
		return (T_REG);
	

}

void		parse3(char **tab, t_line *str)
{

}

void		parse2(char **tab, t_line *str)
{
	char 	**params;

	params = ft_strsplit(tab[1], SEPARATOR_CHAR);

}

void		parse1(char **tab, t_line *str)
{
	check_label_name(tab[0]);
}

void 		ft_parse_lines(t_line *str)
{
	char 	**tab;
	t_line	*start;

	start = str;
	while (str->next->next)
	{
		tab = ft_strsplit(str->line, ' ');
		if (tab[0] && tab[1] && tab[2] && !tab[3])
			parse3(tab, start);
		else if (tab[0] && tab[1] && !tab[2])
			parse2(tab, start);
		else if (tab[0] && !tab[1])
			parse1(tab, start);
		else
			ft_error(ft_strjoin("\ninvalid instruction : ", str->line));
		del_tab(tab);
		str = str->next;
	}
}