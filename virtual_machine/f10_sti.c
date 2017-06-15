/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f10_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:26 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		sti(t_struct *data, t_pc *p)
{
	t_fun_arg	arg;
	int			addr;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 10);
	if (!ft_check_arguments(arg.type_and_len[0], 10))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	get_last_value(data, &arg, 1, p);
	get_last_value(data, &arg, 2, p);
	addr = arg.args[1] + arg.args[2];
	addr = addr % IDX_MOD;
	move_ptr(data, &arg.start_point, addr);
	set_arguments(data, p->r[arg.args[0]], arg.start_point, p->owner + 1);
	return (exit_with_move(data, arg.type_and_len, p, 1));
}
