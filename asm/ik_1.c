#include "asm.h"

void    write_reg(char *f_line, int *i, unsigned char reg)
{
    f_line[(*i)++] = reg;
}

void    write_ind(char *f_line, int *i, unsigned short ind)
{
    int j;
    unsigned short tmp;

    j = 0;
    while (j < 2) {
        tmp = ind;
        f_line[(*i)++] = (char) (tmp >> (24 - 8 * j++));
    }
}

void    write_dir(char *f_line, int *i, unsigned int dir)
{
    int j;
    unsigned int tmp;

    j = 0;
    while (j < 4) {
        tmp = dir;
        f_line[(*i)++] = (char) (tmp >> (24 - 8 * j++));
    }
}

void    make_cor(t_asm *file)
{
    char *f_line;
    int i;

    i = 0;
    f_line = ft_strnew(4 + PROG_NAME_LENGTH + 1 + COMMENT_LENGTH + 1 + CHAMP_MAX_SIZE + 1);
    ft_bzero(f_line, 4 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE);
    write_dir(f_line, &i, COREWAR_EXEC_MAGIC);
    int j = 0;
    while (file->name[j])
        f_line[i++] = file->name[j++];

    print_memory(f_line, 32);
}
