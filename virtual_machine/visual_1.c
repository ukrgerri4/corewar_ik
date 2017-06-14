#include "vm.h"

void out_map(t_struct *pl)
{
    int			i;
    int			j;

    i = 0;
    j = 1;
    wmove(out.map, 0, 0);
    while (i < MEM_SIZE)
    {
        while (i < j * 64)
        {
            if (i < MEM_SIZE)
            {
                wattron(out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
                wprintw(out.map, "%02x", pl->map[i]);
                wattroff(out.map, A_BOLD | COLOR_PAIR(pl->color[i]));
            }
            if (i != j * 64 - 1)
                wprintw(out.map, " ");
            i++;
        }
        wprintw(out.map, "\n");
        j++;
    }
}

void    out_info1(t_struct *pl)
{
    int i;
    int j;

    werase(out.info1);
    wattron(out.info1, A_BOLD);
    mvwprintw(out.info1, 0, 24, "Status info:");
    wattroff(out.info1, A_BOLD);
    mvwprintw(out.info1, 5, 2, "Cycle = ");
    wattron(out.info1, A_BOLD | COLOR_PAIR(6));
    wprintw(out.info1, "%d", pl->current_cycle++);
    wattroff(out.info1, A_BOLD | COLOR_PAIR(6));
    i = 0;
    j = 8;
    while (i < pl->num_pl){
        wattron(out.info1, COLOR_PAIR(i + 1));
        mvwprintw(out.info1, j, 2, "Player[%d] say live - [%d] times %s",
        (int)pl->players[i]->player_number, pl->players[i]->count_live,
        pl->players[i]->name);
        wattroff(out.info1, COLOR_PAIR(i + 1));
        j += 2;
        i++;
    }
    mvwprintw(out.info1, 30, 2, "Winner: ");
    wattron(out.info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    wprintw(out.info1, "[%d]", pl->number_last_live_player);
    wattroff(out.info1, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    wrefresh(out.info1);
}

void    out_info2(t_struct *pl)
{
    werase(out.info2);
    mvwprintw(out.info2, 1, 2, "CYCLE_TO_DIE = %d", pl->glob_cycles);
    mvwprintw(out.info2, 2, 2, "NBR_LIVE = %d", pl->nbr_live);
    mvwprintw(out.info2, 3, 2, "MAX_CHECKS = %d", pl->max_checks);
    wrefresh(out.info2);
}

void    out_info3(t_struct *pl)
{
    werase(out.info3);
    wattron(out.info3, A_BOLD);
    mvwprintw(out.info3, 0, 25, "Help info:");
    wattroff(out.info3, A_BOLD);
    mvwprintw(out.info3, 2, 1, "- press +/- to control speed: ");
    wattron(out.info3, A_BOLD | COLOR_PAIR(6));
    wprintw(out.info3, "%d", 51 - pl->speed/2000);
    wattroff(out.info3, A_BOLD | COLOR_PAIR(6));
    mvwprintw(out.info3, 3, 1, "- press \"spase\" to stop VM");
    mvwprintw(out.info3, 4, 1, "- when VM stoped, press any key to go 1 cycle");
    wrefresh(out.info3);
}

void    out_start_position(t_struct *pl)
{
    t_pc *tmp;

    out_map(pl);
    tmp = pl->first;
    while (tmp)
    {
        mvwchgat(out.map, (tmp->pc_ptr - pl->map) / 64,
                 ((tmp->pc_ptr - pl->map) % 64) * 3,
                 2, 0, 7, NULL);
        tmp = tmp->next;
    }
    wrefresh (out.map);
    out_info1(pl);
    out_info2(pl);
    out_info3(pl);
    if (wgetch(out.map) == ' ')
        set_del();
}

void    out_winner(t_struct *pl)
{
    int row;
    int col;

    wclear(out.map);
    getmaxyx(out.map, row, col);
    wattron(out.map, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    mvwprintw(out.map, row / 2, (col - 22) / 2, "Winner is player N[%d]", (int) pl->number_last_live_player);
    wattroff(out.map, A_BOLD | COLOR_PAIR((int) ((pl->number_last_live_player * -1) - 1)));
    wrefresh (out.map);
    halfdelay(200);
    wgetch(out.map);
}