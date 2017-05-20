#include "asm.h"

void	print_memory(const void *addr, size_t size)
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
                write(1, &base[c / 16], 1);
                c %= 16;
                write(1, &base[c % 16], 1);
            }
            else
                write(1, "  ", 2);
            if (i % 2 == 1 || i == 1)
                write(1, " ", 1);
            i++;
        }
        write(1, "\n", 1);
        j++;
    }
}

