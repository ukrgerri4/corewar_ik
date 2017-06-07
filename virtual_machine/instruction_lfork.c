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
	long int 		arg;
	unsigned char	*point;

	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	arg = get_argument(data, &point, 2);
	arg = cast_if_negative(arg);
	move_ptr(data, &point, -3);
	move_ptr(data, &point, arg);
	create_pc_fork_lfork(data, p, point);
	move_ptr(data, &p->pc_ptr, 2);
	return (1);
}