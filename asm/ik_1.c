#include "asm.h"

unsigned int    put_int()
{

}

void    write_magic(char *fline, char *f_line)
{
    int magic = COREWAR_EXEC_MAGIC;
    fline[0] = magic;
    ft_printf("%s", (char*)fline);
}

void    make_cor(t_asm *file)
{
    char *f_line;
    char now;

    f_line = ft_strnew(4 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE);
    ft_bzero(f_line, 4 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE);
    now = f_line;
    write_magic(f_line, &now);
}

