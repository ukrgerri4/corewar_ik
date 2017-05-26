/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:16:39 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/22 14:16:46 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	find_flag(char *flag, char *argum, t_struct *pl)
{
	int i;

	i = 0;
	if (ft_strequ(flag, "-d"))
	{
		while (argum && ft_isdigit(argum[i]))
			i++;
		if (argum && !argum[i])
			pl->fl_dump = ft_atoi(argum);
		else
			pl->fl_dump = 0;
	}
	else if (ft_strequ(flag, "-n"))
	{
		pl->fl_n = 1;
	}
	else
	{
		ft_error("bad flags input");
	}
}

void 	ft_search_flags(char **argc, int argv, t_struct *pl)
{
	int i;

	i = 0;
//	ft_printf("1\n");
	while (i < argv)
	{
//		ft_printf("i = %d\n", i);
		if (argc[i] && argc[i][0] == '-')
		{
//			ft_printf("in [%s]\n", argc[i]);
			find_flag(argc[i], argc[i + 1], pl);
//			ft_printf("4\n");
		}
		i++;
	}
//	ft_printf("exit flags\n");
}