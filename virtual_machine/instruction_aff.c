#include "virtual_machine.h"

int 	aff(t_struct *data, t_pc *p)
{
    t_fun_arg       arg;

    init_fun_arg(&arg);
    arg.start_point = p->pc_ptr;
    move_ptr(data, &p->pc_ptr, 1);
    ft_choose_arg(&p->pc_ptr, arg.type_and_len, 15);
    if (!ft_check_arguments(arg.type_and_len[0], 15))
        return (exit_with_move(data, arg.type_and_len, p, 0));
    if (!input_params(arg.type_and_len, arg.args, data, p))
        return (exit_with_move(data, arg.type_and_len, p, 0));
    get_last_value(data, &arg, 0, p);
    ft_printf("aff[%s]: %c\n", data->players[p->owner]->name, arg.args[0] % 256);
    return (exit_with_move(data, arg.type_and_len, p, 1));
}

