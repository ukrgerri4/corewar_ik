/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_comand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:19:23 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/06/15 15:20:51 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_command_number(t_asm *file, char *command_name)
{
	file->tab_nb = 0;
	while (file->tab_nb < 17)
	{
		if (!ft_strcmp(g_tab[file->tab_nb].name, command_name))
			break ;
		file->tab_nb++;
	}
	write_reg(file, file->prog, (unsigned char)(file->tab_nb + 1));
}

void	write_argumens_byte(t_asm *file, int argument, int place)
{
	if (g_tab[file->tab_nb].params_byte)
	{
		if (argument == T_REG)
			file->prog[file->arg_byte] |= 64 >> 2 * place;
		else if (argument == T_IND)
			file->prog[file->arg_byte] |= 192 >> 2 * place;
		else if (argument == T_DIR)
			file->prog[file->arg_byte] |= 128 >> 2 * place;
	}
}

void	write_arguments_number(t_asm *file, char **arg)
{
	int	i;
	int	len;

	len = find_quantity_elem_in_line(arg);
	i = 0;
	while (i < len)
	{
		if (arg[i][0] == 'r')
		{
			write_argumens_byte(file, T_REG, i);
			write_reg(file, file->prog, (unsigned char)ft_atoi(arg[i] + 1));
		}
		else if (ft_isdigit(arg[i][0]) || arg[i][0] == '-' || arg[i][0] == ':')
		{
			write_argumens_byte(file, T_IND, i);
			check_ind_number(file, arg[i]);
		}
		else if (arg[i][0] == '%')
		{
			write_argumens_byte(file, T_DIR, i);
			check_dir_number(file, arg[i] + 1);
		}
		i++;
	}
	free_arr(&arg);
}
