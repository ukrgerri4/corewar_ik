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
    if (cur->cycles > 0)
        return 1;
    while (i < 16)
    {
        if (g_tab[i].opcode == *(cur->pc_ptr))
        {
            cur->cycles = g_tab[i].nb_tours;
            return 1 ;
        }
        i++;
    }
    return 0 ;
}

void    go_some_cycles(t_struct *pl, int cycles)
{
    int     i;
    t_pc    *tmp;

    i = 0;
    while (i < cycles)
    {
        /*--------------------
        move(0,0);
        //halfdelay(1);
        getch();
        refresh();
        visualization(pl, 4096);
        -------------------*/
        tmp = pl->first;
        while (tmp)
        {
            if (tmp->cycles == 0) {
                if (!g_fun[*(tmp->pc_ptr)](pl, tmp))
                    move_ptr(pl, &tmp->pc_ptr, 1);
                tmp->cycles = -1;
            }
            else
            {
                if (set_cycles(tmp))
                    tmp->cycles--;
                else
                    move_ptr(pl, &tmp->pc_ptr, 1);
            }
            /*--------------------
            int xc = (tmp->pc_ptr - pl->map) / 64;
            int yc = ((tmp->pc_ptr - pl->map) % 64) * 3;
            mvchgat(xc, yc, 1, 0, 7, NULL);
            --------------------*/
            tmp = tmp->next;
        }
        i++;
    }
}

int     check_ending(t_struct *pl)
{
    t_pc    *tmp;
    t_pc    *del;

    tmp = pl->first;
    while (tmp){
        if (!tmp->live) {
            del = tmp;
            tmp = tmp->next;
            delete_pc(pl, &del);
        }
        else {
            tmp->live = 0;
            tmp = tmp->next;
        }
    }
    if (!pl->first)
        return 1;
    //проверить
    //проверить 10
    return 0;
}

void    start_vm(t_struct *pl)
{
    write_code_to_field(pl);
    go_some_cycles(pl, pl->glob_cycles);
    while (check_ending(pl) != 1)
        go_some_cycles(pl, pl->glob_cycles);
}

