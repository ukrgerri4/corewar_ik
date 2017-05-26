#include "virtual_machine.h"

void    init_pc(t_struct *pl, int i, unsigned char *ptr)
{
    t_pc *tmp;

    if (!(tmp = (t_pc*)malloc(sizeof(t_pc))))
        exit(1);
    tmp->pc_ptr = ptr;
    tmp->carry = 0;
    tmp->cycles = 0;
    tmp->live = 0;
    ft_fill_int(tmp->r, 17, -1);
    tmp->r[1] = pl->players[i]->player_number;
    if (pl->players[i]->first)
        pl->players[i]->first->next = tmp;
    else
        pl->players[i]->first = tmp;
    tmp->next = NULL;
}

