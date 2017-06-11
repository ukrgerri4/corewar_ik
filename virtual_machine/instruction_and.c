/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:04:25 by dsemench          #+#    #+#             */
/*   Updated: 2017/06/01 14:04:26 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

void	ft_for_and_or_xor(t_struct *data, t_pc *p, long int **arg, unsigned char *args)
{
	unsigned char	*point;

	point = p->pc_ptr - 1;
	if (args[1] == T_IND)
	{
		//		point = p->pc_ptr - 1;
		arg[0][0] = cast_if_negative(arg[0][0]);
		arg[0][0] = arg[0][0] % IDX_MOD;
		move_ptr(data, &point, arg[0][0]);
		arg[0][0] = get_argument(data, &point, 4);
	}
	else if (args[1] == T_REG)
		arg[0][0] = p->r[arg[0][0]];
	if (args[2] == T_IND)
	{
		//		point = p->pc_ptr - 1;//обнулять поинтер не нужно?????
		arg[0][1] = cast_if_negative(arg[0][1]);
		arg[0][1] = arg[0][1] % IDX_MOD;
		move_ptr(data, &point, arg[0][1]);
		arg[0][1] = get_argument(data, &point, 4);
	}
	else if (args[2] == T_REG)
		arg[0][1] = p->r[arg[0][1]];
}

int			and(t_struct *data, t_pc *p)
{
	long int		arg[3];
	long int		*tmp_arg;
	unsigned char	*args;
	unsigned char	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	move_ptr(data, &p->pc_ptr, 1);
	if (!ft_choose_arg(data, &p->pc_ptr, args, 5))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	get_len_write(args, args_len, 4);
	if (((arg[0] = get_argument(data, &point, args_len[0])) > 16 && args[0] == T_REG)
		|| ((arg[1] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG)
		|| ((arg[2] = get_argument(data, &point, args_len[2])) > 16 && args[2] == T_REG))
		return (free_for_functions(args, args_len, 0));
	tmp_arg = arg;
//	printf("[%d]\n", arg[1]);
	ft_for_and_or_xor(data, p, &tmp_arg, args);
	p->r[tmp_arg[2]] = tmp_arg[0] & tmp_arg[1];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	change_carry(p, p->r[tmp_arg[2]]);
	return (free_for_functions(args, args_len, 1));
}
