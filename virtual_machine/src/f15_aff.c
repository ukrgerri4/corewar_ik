/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f15_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/15 20:42:33 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		aff(t_struct *data, t_pc *p)
{
	t_fun_arg	arg;

	init_fun_arg(&arg);
	arg.start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	ft_choose_arg(&p->pc_ptr, arg.type_and_len, 15);
	if (!ft_check_arguments(arg.type_and_len[0], 15))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	if (!input_params(arg.type_and_len, arg.args, data, p))
		return (exit_with_move(data, arg.type_and_len, p, 0));
	get_last_value(data, &arg, 0, p);
	if (!data->fl_v)
		ft_printf("aff[%s]: %c\n",
				data->players[p->owner]->name, arg.args[0] % 256);
	return (exit_with_move(data, arg.type_and_len, p, 1));
}
