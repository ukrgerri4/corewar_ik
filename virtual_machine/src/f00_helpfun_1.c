/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f00_helpfun_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:25:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/15 14:21:33 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned int	get_argument(t_struct *data, unsigned char **p, int size)
{
	unsigned int	args;
	int				i;

	args = 0;
	i = 0;
	while (i < size)
	{
		args = args << 8;
		args |= **p;
		move_ptr(data, p, 1);
		i++;
	}
	return (args);
}

void			set_arguments(t_struct *data,
							unsigned int reg, unsigned char *p, int color)
{
	unsigned int	tmp;
	unsigned char	*start_ptr;
	int				i;

	i = 0;
	start_ptr = p;
	while (i < 4)
	{
		tmp = reg << i * 8;
		p[0] = tmp >> 24;
		move_ptr(data, &p, 1);
		i++;
	}
	if (data->fl_v)
		set_color(data, start_ptr, color);
}

void			change_carry(t_pc *p, unsigned int value)
{
	if (value == 0)
		p->carry = 1;
	else
		p->carry = 0;
}

void			get_last_value(t_struct *data, t_fun_arg *arg, int nb, t_pc *p)
{
	short int		res;
	unsigned char	*tmp_ptr;

	tmp_ptr = arg->start_point;
	if (arg->type_and_len[0][nb] == T_IND)
	{
		res = (short int)arg->args[nb];
		res = (short int)(res % IDX_MOD);
		move_ptr(data, &tmp_ptr, (int)res);
		arg->args[nb] = (int)get_argument(data, &tmp_ptr, 4);
	}
	else if (arg->type_and_len[0][nb] == T_REG)
	{
		arg->args[nb] = p->r[arg->args[nb]];
	}
}

void			get_last_long_value(t_struct *data,
									t_fun_arg *arg, int nb, t_pc *p)
{
	short int		res;
	unsigned char	*tmp_ptr;

	tmp_ptr = arg->start_point;
	if (arg->type_and_len[0][nb] == T_IND)
	{
		res = (short int)arg->args[nb];
		move_ptr(data, &tmp_ptr, (int)res);
		arg->args[nb] = (short int)get_argument(data, &tmp_ptr, 2);
	}
	else if (arg->type_and_len[0][nb] == T_REG)
	{
		arg->args[nb] = p->r[arg->args[nb]];
	}
}
