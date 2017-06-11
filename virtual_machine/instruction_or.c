/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_or.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:26 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int			or(t_struct *data, t_pc *p)
{
	long int		arg[3];
	long int		*tmp_arg;
	unsigned char	*args;
	unsigned char	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	move_ptr(data, &p->pc_ptr, 1);
//	point = p->pc_ptr;
	if (!ft_choose_arg(data, &p->pc_ptr, args, 6))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	get_len_write(args, args_len, 4);
	if (((arg[0] = get_argument(data, &point, args_len[0])) > 16 && args[0] == T_REG)
		|| ((arg[1] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG)
		|| ((arg[2] = get_argument(data, &point, args_len[2])) > 16 && args[2] == T_REG))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr - 1;//нужно выносить?????
//	arg = ft_for_and_or_xor(data, p, arg, args);
	tmp_arg = arg;
	ft_for_and_or_xor(data, p, &tmp_arg, args);
	p->r[tmp_arg[2]] = tmp_arg[0] | tmp_arg[1];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	change_carry(p, p->r[tmp_arg[2]]);
	return (free_for_functions(args, args_len, 1));
}