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

#include "vm.h"

int 	lldi(t_struct *data, t_pc *p)
{
	t_fun_arg       arg;
	int 			addr;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 13);
	if (!ft_check_arguments(arg.type_and_len[0], 13))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	get_last_value(data, &arg, 0, p);
	get_last_value(data, &arg, 1, p);
	addr = arg.args[0] + arg.args[1];
	move_ptr(data, &arg.start_point, addr);
	p->r[arg.args[2]] = get_argument(data, &arg.start_point, 4);
	change_carry(p, p->r[arg.args[2]]);
	return (exit_with_move(data, arg.type_and_len, p, 1));
}