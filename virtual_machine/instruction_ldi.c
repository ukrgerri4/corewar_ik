#include "virtual_machine.h"

void	overwrite_t_ind_ldi(long int *arg, t_struct *data, unsigned char *point)
{
	*arg = cast_if_negative(*arg);
	*arg = *arg % IDX_MOD;
	move_ptr(data, &point, *arg);
	*arg = get_argument(data, &point, 4);
}

int 	ldi(t_struct *data, t_pc *p)
{
	long int 		arg[3];
	unsigned char 	*args;
	unsigned char 	*args_len;
	unsigned char	*point;

	move_ptr(data, &p->pc_ptr, 1);
	args = (unsigned char *)ft_strnew(3);
	args_len = (unsigned char *)ft_strnew(3);
	if (!ft_choose_arg(data, &p->pc_ptr, args, 9))
		return (free_for_functions(args, args_len, 0));
	point = p->pc_ptr;
	move_ptr(data, &point, 1);
	get_len_write(args, args_len, 2);
	if (((arg[0] = get_argument(data, &point, args_len[0])) > 16 && args[0] == T_REG) ||
		((arg[1] = get_argument(data, &point, args_len[1])) > 16 && args[1] == T_REG)
		|| ((arg[2] = get_argument(data, &point, args_len[2])) > 16))
		return (free_for_functions(args, args_len, 0));
	if (args[0] == T_IND)
		overwrite_t_ind_ldi(&arg[0], data, p->pc_ptr - 1);
	else if (args[0] == T_REG)
		arg[0] = p->r[arg[0]];
	if (args[1] == T_REG)
		arg[1] = p->r[arg[1]];
	point = p->pc_ptr - 1;
	arg[0] = cast_if_negative(arg[0]);
	arg[1] = cast_if_negative(arg[1]);
	arg[0] = cast_if_negative(arg[0] + arg[1]);
	arg[0] = arg[0] % IDX_MOD;
	move_ptr(data, &point, arg[0]);
	arg[0] = get_argument(data, &point, 4);
	p->r[arg[2]] = arg[0];
	move_ptr(data, &p->pc_ptr, (args_len[0] + args_len[1] + args_len[2] + 1));
	return (free_for_functions(args, args_len, 1));
}
