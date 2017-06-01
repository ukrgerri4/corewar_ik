/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_zjmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:06:56 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 14:07:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	zjmp(t_struct *data, t_pc *p)
{
	long int 		arg;
	unsigned char	*point;
	unsigned char	*start;

	if (p->carry == 0)
		return (0);
	start = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	arg = get_argument(data, &point, 2);
	arg = cast_if_negative(arg);
	arg = arg % IDX_MOD;
	p->pc_ptr = start;
	move_ptr(data, &p->pc_ptr, arg);
	return (1);
}
