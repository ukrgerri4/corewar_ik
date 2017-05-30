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

t_op 		*init_tab(void)
{
    static t_op	tab[17] =
    {
            {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
            {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
            {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
            {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
            {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
            {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
                    "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
            {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
                    "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
            {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
                    "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
            {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
            {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
                    "load index", 1, 1},
            {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
                    "store index", 1, 1},
            {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
            {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
            {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
                    "long load index", 1, 1},
            {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
            {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
            {0, 0, {0}, 0, 0, 0, 0, 0}
    };
    return (tab);
}

void 	ft_init_st(t_struct	*pl)
{
	pl->fl_dump = -1;
	pl->fl_n = -1;
	pl->num_pl = 0;
    pl->glob_cycles = CYCLE_TO_DIE;
    pl->number_last_live_player = 0;
    pl->nbr_live = 0;
    pl->max_checks = 0;
	pl->players = NULL;
	pl->first = NULL;
	pl->last = NULL;
	if (!(pl->map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		exit(1);
    ft_bzero(pl->map, MEM_SIZE);
    pl->iterator = 1;//delete
}

int 	main(int argc, char **argv)
{
	t_struct	pl;

	init_function();
    g_tab = init_tab();
    //init_window();
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
    start_vm(&pl);
    //endwin();
	return (0);
}
