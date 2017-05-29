#include "virtual_machine.h"

void    write_code_to_field(t_struct *pl)
{
    t_pc            *tmp;
    unsigned char   *ptr;
    int             i;
    int             j;

    i = 0;
    tmp = pl->last;
    while (i < pl->num_pl) {
        ptr = tmp->pc_ptr;
        j = 0;
        while (j < pl->players[i]->size_cd)
        {
            ptr[j] = pl->players[i]->code[j];
            ++j;
        }
        i++;
        tmp = tmp->prev;
    }
}

int     set_cycles(t_pc *cur)
{
    int i;

    i = 0;
    if (cur->cycles)
        return 1 ;
    while (i < 17)
    {
        if (g_tab[i].opcode == *(cur->pc_ptr))
        {
            cur->cycles = g_tab[i].nb_tours;
            return 1;
        }

        i++;
    }
}

void    go_some_cycles(t_struct *pl, int cycles)
{
    int     i;
    t_pc    *tmp;

    i = 0;
    while (i < cycles)
    {
        tmp = pl->first;
        while (tmp) {
            if (set_cycles(tmp))
                move_ptr(pl, &tmp->pc_ptr, 1);
            else
                go_to_function();
            tmp = tmp->next;
        }
        i++;
    }
}


void    start_vm(t_struct *pl)
{
    write_code_to_field(pl);
    visualization(pl, 4096);
    go_some_cycles(pl, CYCLE_TO_DIE);
    //while (check_live(pl) != 1)        //пока не выполнится условие (1 и жива) будем добавлять по CYCLE_DELTA
    //    go_some_cycles(pl, CYCLE_TO_DIE - CYCLE_DELTA);
}

