/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f00_helpfun_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 15:25:29 by apoplavs          #+#    #+#             */
/*   Updated: 2017/06/15 14:21:33 by dsemench         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_fun_arg(t_fun_arg *arg)
{
	arg->type_and_len = (unsigned char**)malloc(sizeof(arg->type_and_len) * 3);
	arg->type_and_len[0] = (unsigned char*)ft_strnew(3);
	arg->type_and_len[1] = (unsigned char*)ft_strnew(3);
	arg->type_and_len[2] = NULL;
}

int		input_params(unsigned char **type_and_len,
						int *args, t_struct *data, t_pc *p)
{
	unsigned char	*point;
	int				i;

	i = 0;
	while (i < 3)
		args[i++] = 0;
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	i = 0;
	while (i < 3)
	{
		if (type_and_len[1][i] == 2)
			args[i] = (short int)get_argument(data, &point, type_and_len[1][i]);
		else
			args[i] = (int)get_argument(data, &point, type_and_len[1][i]);
		if ((args[i] > 16 || args[i] <= 0) && type_and_len[0][i] == T_REG)
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_arguments(unsigned char *arg, int n)
{
	if (g_tab[n].nb_param == 1)
	{
		if ((arg[0] & g_tab[n].params_types[0]) == 0
				|| arg[1] > 0 || arg[2] > 0)
			return (0);
	}
	else if (g_tab[n].nb_param == 2)
	{
		if ((arg[0] & g_tab[n].params_types[0]) == 0
				|| (arg[1] & g_tab[n].params_types[1]) == 0 || arg[2] > 0)
			return (0);
	}
	else if (g_tab[n].nb_param == 3)
	{
		if ((arg[0] & g_tab[n].params_types[0]) == 0
				|| (arg[1] & g_tab[n].params_types[1]) == 0
				|| (arg[2] & g_tab[n].params_types[2]) == 0)
			return (0);
	}
	return (1);
}

void	ft_choose_arg(unsigned char **p, unsigned char **type_and_len, int n)
{
	unsigned char	tmp;
	int				i;

	i = 0;
	while (i < g_tab[n].nb_param)
	{
		tmp = **p;
		tmp = tmp << (i * 2);
		type_and_len[0][i] = tmp >> 6;
		if (type_and_len[0][i] == 3)
			type_and_len[0][i] = 4;
		if (type_and_len[0][i] == T_DIR)
		{
			if (g_tab[n].index_size)
				type_and_len[1][i] = 2;
			else
				type_and_len[1][i] = 4;
		}
		else if (type_and_len[0][i] == T_IND)
			type_and_len[1][i] = 2;
		else if (type_and_len[0][i] == T_REG)
			type_and_len[1][i] = 1;
		i++;
	}
}

int		exit_with_move(t_struct *data,
						unsigned char **type_and_len, t_pc *p, int i)
{
	move_ptr(data, &p->pc_ptr,
			(type_and_len[1][0] + type_and_len[1][1] + type_and_len[1][2] + 1));
	ft_free_db_array((char**)type_and_len);
	return (i);
}
