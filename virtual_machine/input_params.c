/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:25:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/11 15:25:33 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "virtual_machine.h"

unsigned char	**init_type_len(void)
{
	unsigned char 	**type_and_len;

	type_and_len = (unsigned char**)malloc(sizeof(type_and_len) * 3);
	type_and_len[0] = (unsigned char*)ft_strnew(3);
	type_and_len[1] = (unsigned char*)ft_strnew(3);
	type_and_len[2] = NULL;
	return (type_and_len) ;
}

void	get_indirect_value(unsigned char *point, int *args, t_struct *data)
{
	short int res;

	res = (short int)*args;
	res = (short int)(res % IDX_MOD);
	move_ptr(data, &point, (int)res);
	*args = (int)get_argument(data, &point, 4);
}


void	init_args(int *args)
{
	args[0] = 0;
	args[1] = 0;
	args[2] = 0;
}

int		input_params(unsigned char **type_and_len, int *args, t_struct *data, t_pc *p)
{
	unsigned char	*point;
	int 			i;

	i = 0;
	init_args(args);
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	while (i < 3)
	{
		args[i] = (int)get_argument(data, &point, type_and_len[1][i]);
		if ((args[i] > 16 || args[i] <= 0) && type_and_len[0][i] == T_REG)
			return (0);
		i++;
	}
	return (1);
}

