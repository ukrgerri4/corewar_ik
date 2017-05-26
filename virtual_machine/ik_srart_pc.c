#include "virtual_machine.h"

void    start_vm(t_struct *pl)
{
    int i;

    i = pl->num_pl;
    while (i > 0)
    {
        pl->players[i]->first.pc_ptr = pl->map + ;
        i--;
    }
}
