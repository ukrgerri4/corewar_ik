#include "asm.h"

void	print_memory(t_asm *file, const void *addr, size_t size)
{
    unsigned char	*mem;
    unsigned char	c;
    size_t			i;

    i = 0;
    mem = (unsigned char*)addr;
    while (i < size) {
        c = mem[i];
        write(file->fd_filename, &c, 1);
        i++;
    }
}

/*void	print_memory(t_asm *file, const void *addr, size_t size)
{
    char			base[17] = "0123456789abcdef";
    unsigned char	*mem;
    unsigned char	c;
    size_t			i;
    size_t			j;

    i = 0;
    j = 1;
    mem = (unsigned char*)addr;
    while (i < size)
    {
        while (i < j * 16)
        {
            c = mem[i];
            if (i < size)
            {
                write(file->fd_filename, &base[c / 16], 1);
                c %= 16;
                write(file->fd_filename, &base[c % 16], 1);
            }
            if ((i % 2 == 1 || i == 1) && (i + 1) % 16 != 0 && i < size)
                write(file->fd_filename, " ", 1);
            i++;
        }
        if (i < size)
            write(file->fd_filename, "\n", 1);
        j++;
    }
}*/
