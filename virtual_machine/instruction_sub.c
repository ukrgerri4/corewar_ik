/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:53:45 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/31 14:53:46 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	sub(t_struct *data, t_pc *p)
{
	unsigned int 	reg[3];
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	change_carry(p);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, &point, args, 4))
		return (free_for_functions(args, args_len, 0));
	get_len_write(args, args_len, 0);
	if (((reg[0] = get_argument(data, &point, args_len[0])) > 16)
		|| ((reg[1] = get_argument(data, &point, args_len[1])) > 16)
		|| ((reg[2] = get_argument(data, &point, args_len[2])) > 16))
		return (free_for_functions(args, args_len, 0));
	p->r[reg[2]] = p->r[reg[0]] - p->r[reg[1]];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	return (free_for_functions(args, args_len, 1));
}
