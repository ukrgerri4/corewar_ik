/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f08_zjmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:06:56 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 14:07:05 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		zjmp(t_struct *data, t_pc *p)
{
	unsigned char	*start;
	short int		addr;

	if (p->carry == 0)
	{
		move_ptr(data, &p->pc_ptr, 3);
		return (0);
	}
	start = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	addr = (short int)get_argument(data, &p->pc_ptr, 2);
	addr = (short int)(addr % IDX_MOD);
	p->pc_ptr = start;
	move_ptr(data, &p->pc_ptr, addr);
	return (1);
}
