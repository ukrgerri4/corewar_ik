
#include "virtual_machine.h"

int 		rearange_point(t_struct *data, unsigned char **p, unsigned char *args, int n)
{
	int 	i;

	i = 0;
	while (i < g_tab[n].nb_param)
	{
		if (args[i] == T_REG)
			move_ptr(data, p, 1);
		else if (args[i] == T_IND)
			move_ptr(data, p, 2);
		else if (args[i] == T_DIR)
		{
			if (g_tab[n].index_size == 0)
				move_ptr(data, p, 4);
			else
				move_ptr(data, p, 2);
		}
		i++;
	}
	move_ptr(data, p, 1);
	return (0);
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


int		ft_choose_arg(t_struct *data, unsigned char **p, unsigned char *args, int n)
{
	unsigned char tmp;

	tmp = **p;
	args[0] = tmp >> 6;
	tmp = tmp << 2;
	args[1] = tmp >> 6;
	tmp = **p;
	tmp = tmp << 4;
	args[2] = tmp >> 6;
	if (args[0] == 3)
		args[0] = 4;
	if (args[1] == 3)
		args[1] = 4;
	if (args[2] == 3)
		args[2] = 4;
	if (!ft_check_arguments(args, n))
		return (rearange_point(data, p, args, n));
	return (1);
}

long int		cast_if_negative(long int arg)
{
	if (arg > 32767)
	{
		arg = arg - 65535;
		if (arg <= 0)
			arg -= 1;
	}
	return (arg);
}

long int		cast_if_negative_int(long int arg)
{
	if (arg > 2147483647)
	{
		arg = arg - 4294967295;
		if (arg <= 0)
			arg -= 1;
	}
	return (arg);
}
