#include "asm.h"

void    write_reg(t_asm *file, unsigned char reg)
{
    file->header[file->i++] = reg;
}

void    write_ind(t_asm *file, unsigned short ind)
{
    int j;
    unsigned short tmp;

    j = 0;
    while (j < 2) {
        tmp = ind;
        file->header[file->i++] = (char) (tmp >> (8 - 8 * j++));
    }
}

void    write_dir(t_asm *file, unsigned int dir)
{
    int j;
    unsigned int tmp;

    j = 0;
    while (j < 4) {
        tmp = dir;
        file->header[file->i++] = (char) (tmp >> (24 - 8 * j++));
    }
}

void    make_cor(t_asm *file)
{
    int j;

    file->header = ft_strnew(4 + PROG_NAME_LENGTH + 8 + 4 + COMMENT_LENGTH);
    file->prog = ft_strnew(CHAMP_MAX_SIZE);
    ft_bzero(file->header, 4 + PROG_NAME_LENGTH + 8 + 4 + COMMENT_LENGTH);
    ft_bzero(file->prog, CHAMP_MAX_SIZE);
    write_dir(file, COREWAR_EXEC_MAGIC);
    j = 0;
    while (file->name[j])
        file->header[file->i++] = file->name[j++];
    file->i = 136;
    write_dir(file, 0); // there must be champ_size
    j = 0;
    while (file->comment[j])
        file->header[file->i++] = file->comment[j++];
    make_prog(file);
    print_memory(file->header, 4 + PROG_NAME_LENGTH + 8 + 4 + COMMENT_LENGTH);
}
