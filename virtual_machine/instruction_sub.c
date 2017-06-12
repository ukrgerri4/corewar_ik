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
	t_fun_arg       arg;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 4);
	if (!ft_check_arguments(arg.type_and_len[0], 4))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	p->r[arg.args[2]] = p->r[arg.args[0]] - p->r[arg.args[1]];
	change_carry(p, p->r[arg.args[2]]);
	return (exit_with_move(data, arg.type_and_len, p, 1));
}
