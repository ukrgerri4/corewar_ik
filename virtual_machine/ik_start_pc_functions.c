#include "virtual_machine.h"

int     set_cycles(t_pc *cur)
{
    int i;

    i = 0;
    if (cur->cycles > 0) {
        return 1;
    }
    while (i < 16)
    {
        if (g_tab[i].opcode == *(cur->pc_ptr))
        {
            cur->cycles = g_tab[i].nb_tours - 1;
            cur->cur_fun = *(cur->pc_ptr);
            return 1 ;
        }
        i++;
    }
    return 0 ;
}

void    set_del(void)
{
    static int flag;

    if (flag == 0) {
        nodelay(map, TRUE);
        flag = 1;
    }
    else {
        nodelay(map, FALSE);
        flag = 0;
    }
}

void    move_pc(t_struct *pl)
{
    t_pc *tmp;

    tmp = pl->first;
    while (tmp)
    {
        tmp->cycles--;
        if (tmp->cycles == 0)
        {
            if (pl->v)
                out_info2(tmp);
            g_fun[tmp->cur_fun](pl, tmp);
            tmp->cycles = -1;
            tmp->cur_fun = 0;
        }
        else
        {
            if (!set_cycles(tmp))
                move_ptr(pl, &tmp->pc_ptr, 1);
        }
        if (pl->v)
            mvwchgat(map, (tmp->pc_ptr - pl->map) / 64,
            ((tmp->pc_ptr - pl->map) % 64) * 3, 2, 0, 7, NULL);
        tmp = tmp->next;
    }
}

void kill_or_save_pc(t_struct *pl)
{
    t_pc *tmp;
    t_pc *del;

    tmp = pl->first;
    while (tmp){
        if (!tmp->live)
        {
            del = tmp;
            delete_pc(pl, &del);
        }
        else
            tmp->live = 0;
        tmp = tmp->next;
    }
}
