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
