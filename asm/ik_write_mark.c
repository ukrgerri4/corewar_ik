#include "asm.h"

void    write_mark_place(t_asm *file, char *mark, int rdi)
{
    t_mark  *tmp;

    tmp = file->mark;
    while (tmp)
    {
        if (!ft_strcmp(tmp->mark, mark)) {
            ft_strdel(&mark);
            break;
        }
        tmp = tmp->next;
    }
    if (tmp == 0)
    {
        init_mark(file, mark, -1);
        tmp = file->mark;
    }
    init_mark_inside(file, &tmp, rdi);
}

