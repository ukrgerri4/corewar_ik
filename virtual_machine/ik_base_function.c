#include "virtual_machine.h"

void    move_ptr(t_struct *pl, unsigned char **ptr, int i)
{
    long   diff;

    diff = *ptr - pl->map + i;
    if (diff >= 0 && diff < MEM_SIZE)
        *ptr = *ptr + i;
    else if (diff < 0 )
        *ptr = pl->map + (MEM_SIZE + diff % MEM_SIZE);
    else
        *ptr = pl->map + diff % MEM_SIZE;
}

void set_color(t_struct *pl, unsigned char *ptr, int color)
{
    int i;
    int j;

    i = 0;
    j = (int)(ptr - pl->map);
    while (i < 4){
        pl->color[j] = (unsigned char)(color);
        if (pl->v) {
            attron(A_BOLD | COLOR_PAIR(color + 10));
            move(j / 64, j % 64 * 3);
            printw("%02x", pl->map[j]);
            attroff(A_BOLD | COLOR_PAIR(color + 10));
        }
        j++;
        i++;
    }
}

void	ft_fill_int(unsigned int *arr, int size, unsigned int n)
{
    int i;

    i = 0;
    while (size-- > 0)
        arr[i++] = n;
}

void	ft_bchar(unsigned char *arr, int size, unsigned char c)
{
    int i;

    i = 0;
    while (size-- > 0)
        arr[i++] = c;
}