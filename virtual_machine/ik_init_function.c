#include "virtual_machine.h"

void    init_function(void)
{
    g_fun[0] = NULL;
    g_fun[1] = live;
    g_fun[2] = ld;
    g_fun[3] = st;
    g_fun[4] = add;
    g_fun[5] = sub;
    g_fun[6] = and;
    g_fun[7] = or;
    g_fun[8] = xor;
    g_fun[9] = zjmp;
    g_fun[10] = ldi;
    g_fun[11] = sti;
    g_fun[12] = my_fork;
    g_fun[13] = lld;
    g_fun[14] = lldi;
    g_fun[15] = lfork;
    g_fun[16] = aff;
}

/*
void    use_function(t_struct *pl, t_pc *current_pc)
{

}*/
