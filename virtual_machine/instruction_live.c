/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_live.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:21:18 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/29 13:21:26 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

t_st				*get_player_live(t_struct *data, unsigned int player_number)
{
	int 			i;

	i = 0;
	while (i < data->num_pl)
	{
		if (player_number == data->players[i]->player_number)
			return (data->players[i]);
		i++;
	}
	return (NULL);
}

int					live(t_struct *data, t_pc *p)
{
	unsigned int 	arg;
	t_st			*player;

	if ((arg = get_argument(data, p, 4)) == 0)
		return (0);
	if ((player = get_player_live(data, arg)) != NULL)
	{
		player->count_live++;
		data->number_last_live_player = player->player_number;
	}
	data->nbr_live++;
	p->live++;
	return (1);
}
