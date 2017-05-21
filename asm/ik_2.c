#include "asm.h"

void    fill_mark(t_asm *file)
{
    t_mark *tmp;

    tmp = file->mark;
    while (tmp)
    {
        while(tmp->start){
            file->i = tmp->start->place_of_byte;
            if (tmp->start->rdi == T_IND)
                write_ind(file, file->prog, (unsigned short)(tmp->steps - tmp->start->before_command_byte));
            else
                write_dir(file, file->prog, (unsigned int)(tmp->steps - tmp->start->before_command_byte));
            tmp->start = tmp->start->next;
        }
        tmp = tmp->next;
    }
}

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
        line = ft_strsplit(tmp->line, ' ');
        i = find_quantity_elem_in_line(line);
        if (i == 1)
            init_mark(file, ft_strsub(line[0], 0, ft_strlen(line[0]) - 1), file->i);
        else if (i == 2)
            write_command(file, line);
        else if (i == 3) {
            init_mark(file, ft_strsub(line[0], 0, ft_strlen(line[0]) - 1), file->i);
            write_command(file, &line[1]);
        }
        tmp = tmp->next;
        i = 0;
        while (line[i])
            ft_strdel(&line[i++]);
        free(line);
    }
    fill_mark(file);
    //delete
    while (file->mark)
    {
        ft_printf("STEPS = %d, %s  ", file->mark->steps,file->mark->mark);
        while(file->mark->start){
            ft_printf("[com.b = %d, this.b = %d] ", file->mark->start->before_command_byte,file->mark->start->place_of_byte);
            file->mark->start = file->mark->start->next;
        }
        ft_printf("\n");
        file->mark = file->mark->next;
    }
    print_memory(file->prog, CHAMP_MAX_SIZE);
    //delete
}