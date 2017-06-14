#include "asm.h"

void    fill_mark(t_asm *file)
{
    t_mark          *tmp_mark;
    t_mark_inside   *inside;

    tmp_mark = file->mark;
    while (tmp_mark)
    {
        inside = tmp_mark->start;
        while(inside){
            file->i = inside->place_of_byte;
            if (inside->rdi == T_IND)
                write_ind(file, file->prog, (unsigned short)(tmp_mark->steps - inside->before_command_byte));
            else
                write_dir(file, file->prog, (unsigned int)(tmp_mark->steps - inside->before_command_byte));
            inside = inside->next;
        }
        tmp_mark = tmp_mark->next;
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
    file->prog_len = file->i;
    file->i = 136;
    write_dir(file, file->header, (unsigned int)file->prog_len);
    fill_mark(file);
}