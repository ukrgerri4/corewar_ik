/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 09:54:36 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/31 09:54:43 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	st(t_struct *data, t_pc *p)
{
	t_fun_arg       arg;
	unsigned char 	*tmp_ptr;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 2);
	if (!ft_check_arguments(arg.type_and_len[0], 2))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (arg.type_and_len[0][1] == T_IND)
	{
		tmp_ptr = arg.start_point;
		move_ptr(data, &tmp_ptr, arg.args[1]);
		set_arguments(data, p->r[arg.args[0]], tmp_ptr, p->owner + 1);
	}
	else
		p->r[arg.args[1]] = p->r[arg.args[0]];
	return (exit_with_move(data, arg.type_and_len, p, 1));
}
