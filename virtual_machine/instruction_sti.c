#include "virtual_machine.h"

int 	sti(t_struct *data, t_pc *p)
{
	long int 		arg[2];
	unsigned int 	reg;
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	move_ptr(data, &p->pc_ptr, 1);
	point = p->pc_ptr;
	if (!ft_choose_arg(data, &point, args, 10))
		return (0);
	get_len_write(args, args_len, 2);
	if (((reg = get_argument(data, &point, args_len[0])) > 16) ||
			((arg[0] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG) ||
			((arg[1] = get_argument(data, &point, args_len[2])) > 16 && args[2] == T_REG))
		return (free_for_functions(args, args_len, 0));
	if (args[1] == T_IND)
	{
		point = p->pc_ptr - 1;
		arg[0] = cast_if_negative(arg[0]);
		arg[0] = arg[0] % IDX_MOD;
		move_ptr(data, &point, arg[0]);
		arg[0] = get_argument(data, &point, 2);
	}
	else if (args[1] == T_REG)
		arg[0] = p->r[arg[0]];
	if (args[2] == T_REG)
		arg[1] = p->r[arg[1]];
	point = p->pc_ptr - 1;
	move_ptr(data, &point, arg[0] + arg[1]);
    set_arguments(data, p->r[reg], point, p->owner + 1);
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	return (free_for_functions(args, args_len, 1));
}
