/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f12_lld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:23:41 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/30 17:23:49 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		lld(t_struct *data, t_pc *p)
{
	t_fun_arg	arg;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 12);
	if (!ft_check_arguments(arg.type_and_len[0], 12))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	get_last_long_value(data, &arg, 0, p);
	p->r[arg.args[1]] = (unsigned int)arg.args[0];
	change_carry(p, p->r[arg.args[1]]);
	return (exit_with_move(data, arg.type_and_len, p, 1));
}
