#include "virtual_machine.h"

static void    write_code_to_field(t_struct *pl)
{
    t_pc            *tmp;
    unsigned char   *ptr;
    int             i;
    int             j;

    i = 0;
    tmp = pl->last;
    while (i < pl->num_pl)
    {
        ptr = tmp->pc_ptr;
        j = 0;
        while (j < pl->players[i]->size_cd)
        {
            ptr[j] = pl->players[i]->code[j];
            pl->color[&(ptr[j]) - pl->map] = i + 1;
            ++j;
        }
        i++;
        tmp = tmp->prev;
    }
}

static void    set_start_cycles(t_struct *pl)
{
    t_pc *tmp;

    if (pl->v)
        out_map(pl);
    tmp = pl->first;
    while (tmp)
    {
        tmp->cycles--;
        set_cycles(tmp);
        if (pl->v)
            mvwchgat(map, (tmp->pc_ptr - pl->map) / 64,
            ((tmp->pc_ptr - pl->map) % 64) * 3,
            2, 0, 7, NULL);
        tmp = tmp->next;
    }
    if (pl->v)
    {
        wrefresh (map);
        out_info1(pl);
        //out_info2(pl);
        out_info3(pl);
        if (wgetch(map) == ' ')
            set_del();
    }
}

static void    go_some_cycles(t_struct *pl, int cycles)
{
    int     i;
    int     ch;

    i = 0;
    while (i < cycles)
    {
        if (pl->v)
            out_map(pl);
        move_pc(pl);
        if (pl->v)
        {
            wrefresh (map);
            out_info1(pl);
            //out_info2(pl);
            out_info3(pl);
            ch = wgetch(map);
            if (ch == '+')
            {
                if (pl->speed > 2000)
                    pl->speed -= 2000;
            }
            else if (ch == '-')
                pl->speed += 2000;
            else if (ch == ' ')
                set_del();
            usleep(pl->speed);
        }
        i++;
        if (i == pl->fl_dump) {
            out_dump(pl);
            exit(0);
        }
    }
}

static int     check_ending(t_struct *pl)
{
    int i;

    kill_or_save_pc(pl);
    i = 0;
    while (i < pl->num_pl)
        pl->players[i++]->count_live = 0;
    if (!pl->first)
        return 1;
    if (pl->nbr_live >= NBR_LIVE || pl->max_checks == 1)
    {
        pl->glob_cycles -= CYCLE_DELTA;
        pl->max_checks = MAX_CHECKS;
    }
    else
        pl->max_checks--;
    pl->nbr_live = 0;
    if (pl->glob_cycles > 0)
        return 0;
    return 1;
}

void    start_vm(t_struct *pl)
{
    write_code_to_field(pl);
    set_start_cycles(pl);
    go_some_cycles(pl, pl->glob_cycles);
    while (check_ending(pl) != 1)
        go_some_cycles(pl, pl->glob_cycles);
    if (pl->v)
        out_winner(pl);
    //else
    //   ft_printf("Winner: Player[%d] - \"%s\"", pl->number_last_live_player, pl->players[pl->number_last_live_player * -1 -1]->name);
}

