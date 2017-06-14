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

#include "vm.h"

void	find_flag(char *flag, char *argum, t_struct *pl)
{
	int i;

	i = 0;
	if (ft_strequ(flag, "-d") || ft_strequ(flag, "-n"))
	{
		while (argum && ft_isdigit(argum[i]))
			i++;
		if (argum && !argum[i])
		{
			if (ft_strequ(flag, "-d"))
				pl->fl_dump = ft_atoi(argum);
			else if (ft_strequ(flag, "-n"))
				pl->fl_n = ft_atoi(argum);
		}
		else if (ft_strequ(flag, "-n"))
			ft_error("flag must be with number 1-4 nothing else exemple: [-n 1 'name.cor']");
		else if (ft_strequ(flag, "-d"))
			pl->fl_dump = 0;
	}
	else if (ft_strequ(flag, "-v"))
		pl->fl_v = 1;
	else
		ft_error("bad flags input");
}

void 	ft_search_flags(char **argc, int argv, t_struct *pl)
{
	int i;

	i = 0;
	while (i < argv)
	{
		if (argc[i] && argc[i][0] == '-')
		{
			find_flag(argc[i], argc[i + 1], pl);
			if (pl->fl_n == 0 || pl->fl_n > 4)
				ft_error("flag must be with number 1-4 nothing else exemple: [-n 1 'name.cor']");
		}
		i++;
	}
}