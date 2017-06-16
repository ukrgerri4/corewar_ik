/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 18:50:00 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/26 16:53:34 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_init_st(t_struct *pl)
{
	pl->fl_dump = -1;
	pl->fl_n = -1;
	pl->num_pl = 0;
	pl->glob_cycles = CYCLE_TO_DIE;
	pl->number_last_live_player = 0;
	pl->nbr_live = 0;
	pl->max_checks = MAX_CHECKS;
	pl->players = NULL;
	pl->first = NULL;
	pl->last = NULL;
	if (!(pl->map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		exit(1);
	ft_bzero(pl->map, MEM_SIZE);
	if (!(pl->color = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
		exit(1);
	ft_bchar(pl->color, MEM_SIZE, 8);
	pl->current_cycle = 0;
	pl->fl_v = 0;
	pl->speed = 2000;
}

void	init_pc(t_struct *pl, unsigned char *ptr, int i)
{
	t_pc *tmp;

	if (!(tmp = (t_pc*)malloc(sizeof(t_pc))))
		exit(1);
	tmp->pc_ptr = ptr;
	tmp->owner = i;
	tmp->live = 0;
	tmp->cycles = 0;
	tmp->carry = 0;
	ft_fill_int(tmp->r, 17, 0);
	if (pl->first)
	{
		pl->first->prev = tmp;
		tmp->next = pl->first;
	}
	else
		tmp->next = NULL;
	pl->first = tmp;
	if (pl->last == NULL)
		pl->last = tmp;
	tmp->prev = NULL;
}

void	delete_pc(t_struct *pl, t_pc **del)
{
	if (*del == pl->first && *del == pl->last)
	{
		pl->first = NULL;
		pl->last = NULL;
	}
	else if (*del == pl->first && *del != pl->last)
	{
		(*del)->next->prev = NULL;
		pl->first = (*del)->next;
	}
	else if (*del != pl->first && *del == pl->last)
	{
		(*del)->prev->next = NULL;
		pl->last = (*del)->prev;
	}
	else
	{
		(*del)->prev->next = (*del)->next;
		(*del)->next->prev = (*del)->prev;
	}
	free(*del);
}

void	init_function(void)
{
	g_fun[1] = live;
	g_fun[2] = ld;
	g_fun[3] = st;
	g_fun[4] = add;
	g_fun[5] = sub;
	g_fun[6] = and;
	g_fun[7] = or;
	g_fun[8] = xor;
	g_fun[9] = zjmp;
	g_fun[10] = ldi;
	g_fun[11] = sti;
	g_fun[12] = my_fork;
	g_fun[13] = lld;
	g_fun[14] = lldi;
	g_fun[15] = lfork;
	g_fun[16] = aff;
}
