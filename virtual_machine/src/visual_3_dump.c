/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_3_dump.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 20:18:42 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 20:19:30 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	out_dump(t_struct *pl)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < pl->num_pl)
	{
		ft_printf("Player %d, \"%s\"\n",
				pl->players[i]->player_number * -1,
				pl->players[i]->name);
		i++;
	}
	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("0x%04x :", i);
		while (i < j * 64)
		{
			if (i < MEM_SIZE)
				ft_printf(" %02x", pl->map[i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}
