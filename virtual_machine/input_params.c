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

void        init_fun_arg(t_fun_arg *arg)
{
    arg->type_and_len = (unsigned char**)malloc(sizeof(arg->type_and_len) * 3);
    arg->type_and_len[0] = (unsigned char*)ft_strnew(3);
    arg->type_and_len[1] = (unsigned char*)ft_strnew(3);
    arg->type_and_len[2] = NULL;
}

int		input_params(unsigned char **type_and_len, int *args, t_struct *data, t_pc *p)
{
	unsigned char	*point;
	int 			i;

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

int 		ft_check_arguments(unsigned char *arg, int n)
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
    int 			i;

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

int		exit_with_move(t_struct *data, unsigned char **type_and_len, t_pc *p, int i)
{
    move_ptr(data, &p->pc_ptr, (type_and_len[1][0] + type_and_len[1][1] + type_and_len[1][2] + 1));
    ft_free_db_array((char**)type_and_len);
    return (i);
}


unsigned int	get_argument(t_struct *data, unsigned char **p, int size) // зчитує аргументи для команди
{
    unsigned int args;
    int 		i;

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

void set_arguments(t_struct *data, unsigned int reg, unsigned char *p, int color)
{
    unsigned int    tmp;
    unsigned char   *start_ptr;
    int             i;

    i = 0;
    start_ptr = p;
    while (i < 4)
    {
        tmp = reg << i * 8;
        p[0] = tmp >> 24;
        move_ptr(data, &p, 1);
        i++;
    }
    if (data->v)
        set_color(data, start_ptr, color);
}

void change_carry(t_pc *p, unsigned int value)
{
    if (value == 0)
        p->carry = 1;
    else
        p->carry = 0;
}

void	get_last_value(t_struct *data, t_fun_arg *arg, int nb, t_pc *p)
{
    short int       res;
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

void	get_last_long_value(t_struct *data, t_fun_arg *arg, int nb, t_pc *p)
{
    short int       res;
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