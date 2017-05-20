#include "asm.h"

int		find_quantity_elem_in_line(char **line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

void    make_prog(t_asm *file)
{
    t_line  *tmp;
    char    **line;
    int     i;

    tmp = file->code;
    while (tmp && tmp->next)
    {
        //ft_printf("%s\n", tmp->line);
        line = ft_strsplit(tmp->line, ' ');
        i = find_quantity_elem_in_line(line);
        if (i == 1)
            init_mark(file, ft_strsub(line[0], 0, ft_strlen(line[0]) - 1), file->byte);
        else if (i == 2)
            write_command(file, line);
        else if (i == 3){
            init_mark(file, ft_strsub(line[0], 0, ft_strlen(line[0]) - 1), file->byte);
            //   write_command;
        }
        tmp = tmp->next;
        i = 0;
        while (line[i])
            ft_strdel(&line[i++]);
    }
    //delete
    while (file->mark)
    {
        ft_printf("%s\n", file->mark->mark);
        file->mark = file->mark->next;
    }
    print_memory(file->prog, CHAMP_MAX_SIZE);
    //delete
}