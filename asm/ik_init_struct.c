#include "asm.h"

void    init_mark(t_asm *file, char *name, int steps)
{
    t_mark *tmp;

    if (!(tmp = (t_mark*)malloc(sizeof(t_mark))))
        exit(1);
    tmp->mark = ft_strdup(name);
    tmp->steps = steps;
    if (file->mark)
        tmp->next = file->mark;
    else
        tmp->next = NULL;
    file->mark = tmp;
    ft_strdel(&name);
}