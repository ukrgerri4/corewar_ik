/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:06:31 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 20:17:50 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	out_map(t_struct *pl)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	wmove(g_out.map, 0, 0);
	while (i < MEM_SIZE)
	{
		while (i < j * 64)
		{
			if (i < MEM_SIZE)
			{
				wattron(g_out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
				wprintw(g_out.map, "%02x", pl->map[i]);
				wattroff(g_out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
			}
			if (i != j * 64 - 1)
				wprintw(g_out.map, " ");
			i++;
		}
		wprintw(g_out.map, "\n");
		j++;
	}
}

void	out_info1_1(t_struct *pl)
{
	int i;
	int j;

	i = 0;
	j = 9;
	while (i < pl->num_pl)
	{
		mvwprintw(g_out.info1, j, 2, "Player[%d] ",
				(int)pl->players[i]->player_number);
		wattron(g_out.info1, COLOR_PAIR(i + 1));
		wprintw(g_out.info1, "\"%s\":", pl->players[i]->name);
		mvwprintw(g_out.info1, j + 1, 4, "live in current period - [%d]",
				pl->players[i]->count_live);
		wattroff(g_out.info1, COLOR_PAIR(i + 1));
		j += 4;
		i++;
	}
}

void	out_info1(t_struct *pl)
{
	werase(g_out.info1);
	wattron(g_out.info1, A_BOLD);
	mvwprintw(g_out.info1, 0, 24, "Status info:");
	wattroff(g_out.info1, A_BOLD);
	mvwprintw(g_out.info1, 4, 2, "Cycle = ");
	wattron(g_out.info1, A_BOLD | COLOR_PAIR(6));
	wprintw(g_out.info1, "%d", pl->current_cycle++);
	wattroff(g_out.info1, A_BOLD | COLOR_PAIR(6));
	out_info1_1(pl);
	mvwprintw(g_out.info1, 30, 2, "Winner: ");
	wattron(g_out.info1, A_BOLD |
			COLOR_PAIR(pl->number_last_live_player * -1));
	wprintw(g_out.info1, "[%d]", pl->number_last_live_player);
	wattroff(g_out.info1, A_BOLD |
			COLOR_PAIR(pl->number_last_live_player * -1));
	wrefresh(g_out.info1);
}

void	out_info2(t_struct *pl)
{
	werase(g_out.info2);
	wattron(g_out.info2, A_BOLD);
	mvwprintw(g_out.info2, 0, 22, "Additional info:");
	wattroff(g_out.info2, A_BOLD);
	mvwprintw(g_out.info2, 2, 2, "CYCLE_TO_DIE = %d", pl->glob_cycles);
	mvwprintw(g_out.info2, 4, 2, "NBR_LIVE = %d", pl->nbr_live);
	mvwprintw(g_out.info2, 6, 2, "MAX_CHECKS = %d", pl->max_checks);
	wrefresh(g_out.info2);
}

void	out_info3(t_struct *pl)
{
	werase(g_out.info3);
	wattron(g_out.info3, A_BOLD);
	mvwprintw(g_out.info3, 0, 25, "Help info:");
	wattroff(g_out.info3, A_BOLD);
	mvwprintw(g_out.info3, 2, 1, "- press +/- to control speed: ");
	wattron(g_out.info3, A_BOLD | COLOR_PAIR(6));
	wprintw(g_out.info3, "%d", 51 - pl->speed / 2000);
	wattroff(g_out.info3, A_BOLD | COLOR_PAIR(6));
	mvwprintw(g_out.info3, 3, 1, "- press \"spase\" to stop VM");
	mvwprintw(g_out.info3, 4, 1,
			"- when VM stoped, press any key to go 1 cycle");
	wrefresh(g_out.info3);
}
