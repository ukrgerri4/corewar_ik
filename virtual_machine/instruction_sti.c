#include "virtual_machine.h"



int 	sti(t_struct *data, t_pc *p)
{
	int 			args[3];
	int 			addr;
	unsigned char 	**type_and_len;
	unsigned char	*start_point;


	type_and_len = init_type_len();
	start_point = p->pc_ptr;
	move_ptr(data, &p->pc_ptr, 1);
	if (!ft_choose_arg(data, &p->pc_ptr, type_and_len[0], 10))
	{
		ft_free_db_array((char**)type_and_len);
		return (0);
	}
	get_len_write(type_and_len[0], type_and_len[1], 2);
	input_params(type_and_len, args, data, p);
	//кейс с IND
	addr = args[1] + args[2];
	addr = addr % IDX_MOD;
	move_ptr(data, &start_point, addr);
    set_arguments(data, p->r[args[0]], start_point, p->owner + 1);
	move_ptr(data, &p->pc_ptr, (type_and_len[1][0] + type_and_len[1][1] + type_and_len[1][2] + 1));
	ft_free_db_array((char**)type_and_len);
	return (1);
}
