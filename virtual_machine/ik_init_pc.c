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
    if (pl->players[i]->last) {
        pl->players[i]->last->next = tmp;
        tmp->prev = pl->players[i]->last;
    }
    else
        tmp->prev = NULL;
    pl->players[i]->last = tmp;
    if (pl->players[i]->first == NULL)
        pl->players[i]->first = tmp;
    tmp->next = NULL;
}

void    delete_pc(t_struct *pl, int i, t_pc **del)
{
    if (!(*del)->prev)
        pl->players[i]->first = (*del)->next;
    (*del)->next->prev = NULL;
    else
    {
        (*del)->prev->next = (*del)->next;
        (*del)->next->prev = (*del)->prev;
    }
    free(*del);
    *del = NULL;
}