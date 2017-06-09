/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:23:44 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/30 17:23:46 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	ld(t_struct *data, t_pc *p)
{
	long int 		arg;
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	move_ptr(data, &p->pc_ptr, 1);
	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	if (!ft_choose_arg(data, &p->pc_ptr, args, 1))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	get_len_write(args, args_len, 4);
	arg = get_argument(data, &point, args_len[0]);
	if ((reg = get_argument(data, &point, args_len[1])) > 16)
		return (free_for_functions(args, args_len, 0));
	if (args[0] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg = cast_if_negative(arg);
		arg = arg % IDX_MOD;
		move_ptr(data, &point, arg);
		arg = get_argument(data, &point, 4);
	}
	p->r[reg] = arg;
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	change_carry(p, p->r[reg]);
	return (free_for_functions(args, args_len, 1));
}
