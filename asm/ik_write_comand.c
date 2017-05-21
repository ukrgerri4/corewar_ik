#include "asm.h"

void    write_command_number(t_asm *file, char *command_name)
{
    file->tab_nb = 0;
    while (file->tab_nb < 17)
    {
        if (!ft_strcmp(g_tab[file->tab_nb].name, command_name))
            break;
        file->tab_nb++;
    }
    write_reg(file, file->prog, (unsigned char)(file->tab_nb + 1));
}

void    check_dir_number(t_asm *file, char *dir)
{
    if (ft_isdigit(dir[0]) || dir[0] == '-')
    {
        if (g_tab[file->tab_nb].index_size)
            write_ind(file, file->prog, (unsigned short)ft_atoi(dir));
        else
            write_dir(file, file->prog, (unsigned int)ft_atoi(dir));
    }
    else if (dir[0] == ':')
    {
        if (g_tab[file->tab_nb].index_size)
        {
            write_mark_place(file, ft_strsub(dir, 1, ft_strlen(dir)), T_IND);
            write_ind(file, file->prog, (unsigned short) 0);
        }
        else
        {
            write_mark_place(file, ft_strsub(dir, 1, ft_strlen(dir)), T_DIR);
            write_dir(file, file->prog, (unsigned int) 0);
        }
    }
}

void    check_ind_number(t_asm *file, char *ind)
{

    if (ft_isdigit(ind[0]) || ind[0] == '-')
        write_ind(file, file->prog, (unsigned short)ft_atoi(ind));
    else
    {
        write_mark_place(file, ft_strsub(ind, 1, ft_strlen(ind)), T_IND);
        write_ind(file, file->prog, (unsigned short)ft_atoi(ind));
    }
}

void    write_argumens_byte(t_asm *file, int argument, int place)
{
    if (g_tab[file->tab_nb].params_byte)
    {
        if (argument == T_REG)
            file->prog[file->arg_byte] |= 64 >> 2 * place;
        else if (argument == T_IND)
            file->prog[file->arg_byte] |= 192 >> 2 * place;
        else if (argument == T_DIR)
            file->prog[file->arg_byte] |= 128 >> 2 * place;
    }
}

void    write_arguments_number(t_asm *file, char **arg)
{
    int i;
    int len;

    len = find_quantity_elem_in_line(arg);
    i = 0;
    while (i < len)
    {
        if (arg[i][0] == 'r')
        {
            write_argumens_byte(file, T_REG, i);
            write_reg(file, file->prog, (unsigned char) ft_atoi(arg[i] + 1));
        }
        else if (ft_isdigit(arg[i][0]) || arg[i][0] == '-' || arg[i][0] == ':')
        {
            write_argumens_byte(file, T_IND, i);
            check_ind_number(file, arg[i]);
        }
        else if (arg[i][0] == '%')
        {
            write_argumens_byte(file, T_DIR, i);
            check_dir_number(file, arg[i] + 1);
        }
        i++;
    }
}

void    write_command(t_asm *file, char **line)
{
    file->command_byte = file->i;
    write_command_number(file, line[0]);
    file->arg_byte = file->i;
    if (g_tab[file->tab_nb].params_byte)
        file->i++;
    write_arguments_number(file, ft_strsplit(line[1], ','));
}

