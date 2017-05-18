#include "asm.h"

void	print_char(unsigned char *mem, size_t i, size_t j, size_t size)
{
    while (i < j * 16 && i < size)
    {
        if (mem[i] >= 32 && mem[i] <= 126)
            write(1, &mem[i], 1);
        else
            write(1, ".", 1);
        i++;
    }
}

void	print_memory(const void *addr, size_t size)
{
    char			base[17] = "0123456789abcdef";
    unsigned char	*mem;
    unsigned char	c;
    size_t			i;
    size_t			j;
    size_t			a;

    i = 0;
    j = 1;
    mem = (unsigned char*)addr;
    while (i < size)
    {
        a = i;
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
//        print_char(mem, a, j, size);
        write(1, "\n", 1);
        j++;
    }
}

