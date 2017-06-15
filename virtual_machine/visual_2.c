/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:18:13 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 20:18:28 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	out_start_position(t_struct *pl)
{
	t_pc	*tmp;

	out_map(pl);
	tmp = pl->first;
	while (tmp)
	{
		mvwchgat(g_out.map, (tmp->pc_ptr - pl->map) / 64,
				((tmp->pc_ptr - pl->map) % 64) * 3,
				2, 0, 7, NULL);
		tmp = tmp->next;
	}
	wrefresh(g_out.map);
	out_info1(pl);
	out_info2(pl);
	out_info3(pl);
	if (wgetch(g_out.map) == ' ')
		set_del();
}

void	out_winner(t_struct *pl)
{
	int	row;
	int	col;

	wclear(g_out.map);
	getmaxyx(g_out.map, row, col);
	wattron(g_out.map, A_BOLD |
			COLOR_PAIR(pl->number_last_live_player * -1));
	mvwprintw(g_out.map, row / 2, (col - 22) / 2, "Winner is player N[%d]",
			(int)pl->number_last_live_player);
	wattroff(g_out.map, A_BOLD |
			COLOR_PAIR((int)((pl->number_last_live_player * -1) - 1)));
	wrefresh(g_out.map);
	halfdelay(200);
	wgetch(g_out.map);
}
