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

#include "vm.h"



int 	main(int argc, char **argv)
{
	t_struct	pl;

	init_function();
    g_tab = init_tab();
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
    if (pl.fl_v)
        init_window(&pl);
    start_vm(&pl);
	if (pl.fl_v)
    	endwin();
	return (0);
}
