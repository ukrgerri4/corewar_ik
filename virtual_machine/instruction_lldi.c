/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_lldi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:30:04 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/01 17:30:06 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	overwrite_t_ind_lldi(long int *arg, t_struct *data, unsigned char *point)
{
	*arg = cast_if_negative(*arg);
	move_ptr(data, &point, *arg);
	*arg = get_argument(data, &point, 4);
}

int 	lldi(t_struct *data, t_pc *p)
{
	long int 		arg[3];
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	move_ptr(data, &p->pc_ptr, 1);
	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	if (!ft_choose_arg(data, &p->pc_ptr, args, 9))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	get_len_write(args, args_len, 2);
	if (((arg[2] = get_argument(data, &point, args_len[0])) > 16) ||
		((arg[0] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG) ||
		((arg[1] = get_argument(data, &point, args_len[2])) > 16 && args[2] == T_REG))
		return (free_for_functions(args, args_len, 0));
	if (args[0] == T_IND)
		overwrite_t_ind_lldi(&arg[0], data, p->pc_ptr - 1);
	else if (args[0] == T_REG)
		arg[0] = p->r[arg[0]];
	if (args[1] == T_REG)
		arg[1] = p->r[arg[1]];
	point = p->pc_ptr - 1;
	move_ptr(data, &point, arg[0] + arg[1]);
	arg[0] = get_argument(data, &point, 4);
	p->r[arg[2]] = arg[0];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	change_carry(p, p->r[arg[2]]);
	return (free_for_functions(args, args_len, 1));
}