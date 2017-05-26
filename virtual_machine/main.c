/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:32:51 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/26 16:46:40 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void 	ft_init_st(t_struct	*pl)
{
	pl->fl_dump = -1;
	pl->fl_n = -1;
	pl->num_pl = 0;
}

int 	main(int argc, char **argv)
{
	t_struct	pl;

	ft_init_st(&pl);
	if (argc == 1)
	{
		//output info how use exec
	}
	else if (argc > 1)
	{
		ft_search_flags(argv, argc, &pl);
		ft_valid_name(argv, &pl);
		ft_parsing_file(&pl);
	}
	return (0);
}
