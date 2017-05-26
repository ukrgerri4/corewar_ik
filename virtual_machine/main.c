/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:32:51 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/19 17:34:09 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void 	ft_init_st(t_struct	*pl)
{
	pl->fl_dump = -1;
	pl->fl_n = -1;
	pl->num_pl = 0;
	pl->map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);

//	pl->names_pl = NULL;
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
		int i = 0;
//		while (pl.players[i])//сиг на этом этапе был
		while (i < pl.num_pl)
		{
			ft_printf("name %s\n", pl.players[i]->file_name);
			i++;
		}
		ft_printf("-n  %d\n", pl.fl_n);
		ft_printf("-d  %d\n", pl.fl_dump);
		ft_printf("num %d\n", pl.num_pl);
	}
	return (0);
}