/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_fork.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:36:19 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 17:36:20 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	my_fork(t_struct *data, t_pc *p)
{
	unsigned char	*start;
	short int		value;
	int 			i;

	start = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	value = (short int)get_argument(data, &p->pc_ptr, 2);
	value = (short int)(value % IDX_MOD);
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
