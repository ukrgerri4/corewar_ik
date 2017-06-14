#include "vm.h"

t_op 		*init_tab(void)
{
    static t_op	tab[17] =
            {
                    {"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
                    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
                    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
                    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
                    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
                    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
                            "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
                    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
                            "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
                    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
                            "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
                    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
                    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
                            "load index", 1, 1},
                    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
                            "store index", 1, 1},
                    {"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
                    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
                    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
                            "long load index", 1, 1},
                    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
                    {"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
                    {0, 0, {0}, 0, 0, 0, 0, 0}
            };
    return (tab);
}

void 	ft_init_st(t_struct	*pl)
{
    pl->fl_dump = -1;
    pl->fl_n = -1;
    pl->num_pl = 0;
    pl->glob_cycles = CYCLE_TO_DIE;
    pl->number_last_live_player = 0;
    pl->nbr_live = 0;
    pl->max_checks = MAX_CHECKS;
    pl->players = NULL;
    pl->first = NULL;
    pl->last = NULL;
    if (!(pl->map = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
        exit(1);
    ft_bzero(pl->map, MEM_SIZE);
    if (!(pl->color = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE)))
        exit(1);
    ft_bchar(pl->color, MEM_SIZE, 8);
    pl->current_cycle = 0;
    pl->fl_v = 0;
    pl->speed = 2000;
}

void init_pc(t_struct *pl, unsigned char *ptr, int i)
{
    t_pc *tmp;

    if (!(tmp = (t_pc*)malloc(sizeof(t_pc))))
        exit(1);
    tmp->pc_ptr = ptr;
    tmp->owner = i;
    tmp->live = 0;
    tmp->cycles = 0;
    tmp->carry = 0;
    ft_fill_int(tmp->r, 17, 0);
    if (pl->first) {
        pl->first->prev = tmp;
        tmp->next = pl->first;
    }
    else
        tmp->next = NULL;
    pl->first = tmp;
    if (pl->last == NULL)
        pl->last = tmp;
    tmp->prev = NULL;
}

void    delete_pc(t_struct *pl, t_pc **del)
{
    if (*del == pl->first && *del == pl->last)
    {
        pl->first = NULL;
        pl->last = NULL;
    }
    else if (*del == pl->first && *del != pl->last)
    {
        (*del)->next->prev = NULL;
        pl->first = (*del)->next;
    }
    else if (*del != pl->first && *del == pl->last)
    {
        (*del)->prev->next = NULL;
        pl->last = (*del)->prev;
    }
    else
    {
        (*del)->prev->next = (*del)->next;
        (*del)->next->prev = (*del)->prev;
    }
    free(*del);
}

void    init_function(void)
{
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
