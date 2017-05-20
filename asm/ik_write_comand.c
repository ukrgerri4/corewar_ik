#include "asm.h"

void    write_command_number(t_asm *file, char *command_name)
{
    int i;

    i = 0;
    while (i < 17)
        if (!ft_strcmp(g_tab[i++].name, command_name))
            break ;
    write_reg(file, file->prog, (unsigned char)i);
}

void    write_command(t_asm *file, char **line)
{
    write_command_number(file, line[0]);
}

