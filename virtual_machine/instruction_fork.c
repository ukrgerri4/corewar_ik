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

t_pc	*create_pc_fork_lfork(t_struct *data, t_pc *p, unsigned char *point)
{
	t_pc	*p_new;
	int i;

	i = 0;
	p_new = p;
	init_pc(data, point, p->owner);
	while (i < 17) {
		data->first->r[i] = p->r[i];
		i++;
	}
//	data->first->cycles = p->cycles;//????
	data->first->carry = p->carry;
	return (p_new);
}

int 	my_fork(t_struct *data, t_pc *p)
{
	long int 		arg;
	unsigned char	*point;
	t_pc 			*p_new;

	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	arg = get_argument(data, &point, 2);
	arg = cast_if_negative(arg);
	arg = arg % IDX_MOD;
	move_ptr(data, &point, arg);
	p_new = create_pc_fork_lfork(data, p, point);
	move_ptr(data, &p->pc_ptr, 2);
	return (1);
}
