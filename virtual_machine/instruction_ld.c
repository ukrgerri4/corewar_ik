/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_ld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsemench <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:23:44 by dsemench          #+#    #+#             */
/*   Updated: 2017/05/30 17:23:46 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

int 	ld(t_struct *data, t_pc *p)
{
	int 			args[3];
	unsigned char 	**type_and_len;
	unsigned char	*start_point;

	type_and_len = init_type_len();
	start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	if (!ft_choose_arg(data, &p->pc_ptr, type_and_len[0], 1))
	{
		ft_free_db_array((char**)type_and_len);
		return (0);
	}
	get_len_write(type_and_len[0], type_and_len[1], 4);
	input_params(type_and_len, args, data, p);
	if (type_and_len[0][0] == T_IND)
		get_indirect_value(start_point, &args[0], data);
	p->r[args[1]] = (unsigned int)args[0];
	change_carry(p, p->r[args[1]]);
	move_ptr(data, &p->pc_ptr, (type_and_len[1][0] + type_and_len[1][1] + 1));
	ft_free_db_array((char**)type_and_len);
	return (1);
}
