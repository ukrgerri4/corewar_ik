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
	long int		arg;
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, &point, args, 2))
		return (free_for_functions(args, args_len, 0));
	get_len_write(args, args_len, 0);
	if (((reg = get_argument(data, &point, args_len[0])) > 16) ||
			((arg = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG))
		return (free_for_functions(args, args_len, 0));
	if (args[1] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg = cast_if_negative(arg);
		arg = arg % IDX_MOD;
		move_ptr(data, &point, arg);
        set_arguments(data , p->r[reg], point, p->owner + 1);
	}
	else
		p->r[arg] = p->r[reg];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	return (free_for_functions(args, args_len, 1));
}
