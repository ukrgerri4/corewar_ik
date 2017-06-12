/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 19:11:19 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 19:11:20 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	lfork(t_struct *data, t_pc *p)
{
	unsigned char	*start;
	short int		value;
	int 			i;

	start = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	value = (short int)get_argument(data, &p->pc_ptr, 2);
	move_ptr(data, &start, value);
	init_pc(data, start, p->owner);
	if (data->v)
		mvwchgat(map, (start - data->map) / 64,
				 ((start - data->map) % 64) * 3,
				 2, 0, 7, NULL);
	i = 0;
	while (i < 17)
	{
		data->first->r[i] = p->r[i];
		i++;
	}
	data->first->carry = p->carry;
	return (1);
}