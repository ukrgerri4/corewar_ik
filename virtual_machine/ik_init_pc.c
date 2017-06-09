#include "virtual_machine.h"

void init_pc(t_struct *pl, unsigned char *ptr, int i)
{
    t_pc *tmp;

    if (!(tmp = (t_pc*)malloc(sizeof(t_pc))))
        exit(1);
    tmp->pc_ptr = ptr;
    tmp->owner = i;
    tmp->live = 0;
    tmp->cycles = 0;
    tmp->carry = 0;
    ft_fill_int(tmp->r, 17, 0);
    if (pl->first) {
        pl->first->prev = tmp;
        tmp->next = pl->first;
    }
    else
        tmp->next = NULL;
    pl->first = tmp;
    if (pl->last == NULL)
        pl->last = tmp;
    tmp->prev = NULL;
}


void    delete_pc(t_struct *pl, t_pc **del)
{
    if (*del == pl->first && *del == pl->last)
    {
        pl->first = NULL;
        pl->last = NULL;
    }
    else if (*del == pl->first && *del != pl->last)
    {
        (*del)->next->prev = NULL;
        pl->first = (*del)->next;
    }
    else if (*del != pl->first && *del == pl->last)
    {
        (*del)->prev->next = NULL;
        pl->last = (*del)->prev;
    }
    else
    {
        (*del)->prev->next = (*del)->next;
        (*del)->next->prev = (*del)->prev;
    }
    free(*del);
}
