/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 11:37:53 by apoplavs          #+#    #+#             */
/*   Updated: 2017/05/18 11:38:04 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		set_args(char *a1, char *a2, char *a3, char **params)
{
	*a1 = 0;
	*a2 = 0;
	*a3 = 0;
	if (params[0])
		*a1 = type_arg(params[0]);
	if (params[1])
		*a2 = type_arg(params[1]);
	if (params[1] && params[2])
		*a3 = type_arg(params[2]);
	if (params[1] && params[2] && params[3])
		exit_notice("invalid argument ", params[3]);
}

int 		get_instruction(char *inst)
{
	int 	i;

	i = 0;
	while(i < 16)
	{
		if (ft_strequ(inst, g_tab[i].name))
			return (i);
		i++;
	}
	exit_notice("invalid instruction ", inst);
	return (-1);
}

char 		type_arg(char *arg)
{
	if (arg[0] == 'r' && ft_isdigit(arg[1]))
	{
		check_t_reg(arg);
		return (T_REG);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		check_t_dir(arg);
		return (T_DIR);
	}
	else if (arg[0] == '-' || ft_isdigit(arg[0]) || arg[0] == LABEL_CHAR)
	{
		check_t_ind(arg);
		return (T_IND);
	}
	else
		exit_notice("invalid argument ", arg);
	return (0);
}

void 		check_arguments(char a1, char a2, char a3, int n)
{
	if (g_tab[n].nb_param == 1)
	{
		if ((a1 & g_tab[n].params_types[0]) == 0
			|| a2 > 0 || a3 > 0)
			ft_error("invalid parameter");
	}
	if (g_tab[n].nb_param == 2)
	{
		if ((a2 & g_tab[n].params_types[1]) == 0 || a3 > 0)
			ft_error("invalid parameter");
	}
	else if (g_tab[n].nb_param == 3)
	{
		if ((a2 & g_tab[n].params_types[1]) == 0
			|| (a3 & g_tab[n].params_types[2]) == 0)
			ft_error("invalid type of parameter");
	}
}

