/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_lld.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:23:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/30 17:23:49 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 				lld(t_struct *data, t_pc *p)
{
	unsigned int 	arg;
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	change_carry(p);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, &point, args, 12))
		return (free_for_functions(args, args_len, 0));
	get_len_write(args, args_len, 4);
	arg = get_argument(data, &point, args_len[0]);
	if ((reg = get_argument(data, &point, args_len[1])) > 16)
		return (free_for_functions(args, args_len, 0));
	if (args[0] == T_IND)
	{
		move_ptr(data, &point, arg);
		arg = get_argument(data, &point, args_len[0]);
	}
	p->r[reg] = arg;
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	return (free_for_functions(args, args_len, 1));
}