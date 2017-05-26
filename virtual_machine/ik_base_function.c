#include "virtual_machine.h"

void	ft_fill_int(int *arr, int size, int n)
{
    int i;

    i = 0;
    while (size-- > 0)
        arr[i++] = n;
}
