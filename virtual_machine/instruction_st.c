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

void	set_indirect(short int addr, t_pc *p, t_struct *data, unsigned int value)
{
	unsigned char *start_point;

	start_point = p->pc_ptr - 1;
	addr = (short int)(addr % IDX_MOD);
	move_ptr(data, &start_point, addr);
	set_arguments(data , value, start_point, p->owner + 1);
}


int 	st(t_struct *data, t_pc *p)
{
	int 		args[3];
	unsigned char 	**type_and_len;

	type_and_len = init_type_len();
	move_ptr(data, &p->pc_ptr, 1);
	if (!ft_choose_arg(data, &p->pc_ptr, type_and_len[0], 2))
	{
		ft_free_db_array((char**)type_and_len);
		return (0);
	}
	get_len_write(type_and_len[0], type_and_len[1], 2);
	input_params(type_and_len, args, data, p);
	if (type_and_len[0][1] == T_IND)
		set_indirect((short int)args[1], p, data, p->r[args[0]]);
	else if (type_and_len[0][1] == T_REG)
		p->r[args[1]] = p->r[args[0]];
	move_ptr(data, &p->pc_ptr, (type_and_len[1][0] + type_and_len[1][1] + 1));
	ft_free_db_array((char**)type_and_len);
	return (1);
}
