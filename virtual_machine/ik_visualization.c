#include "virtual_machine.h"

void    out_cycles(t_struct *pl)
{
    int i;
    int j;

    i = 0;
    j = 8;
    while (i < pl->num_pl){
        wattron(info1, A_BOLD | COLOR_PAIR(i + 1));
        mvwprintw(info1, j, 2, "Player[%d] say live - [%d] times",
                 (int)pl->players[i]->player_number, pl->players[i]->count_live);
        wattroff(info1, A_BOLD | COLOR_PAIR(i + 1));
        j += 2;
        i++;
    }
}

void    out_winner(t_struct *pl)
{
    int row;
    int col;

    wclear(map);
    getmaxyx(map, row, col);
    wattron(map, A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    mvwprintw(map, row / 2, (col - 22) / 2, "Winner is player N[%d]", (int) pl->number_last_live_player);
    wattroff(map, A_BOLD | COLOR_PAIR((int) ((pl->number_last_live_player * -1) - 1)));
    wrefresh (map);
    halfdelay(200);
    wgetch(map);
}

void	visualization(t_struct *pl, size_t size)
{
    size_t			i;
    size_t			j;

    i = 0;
    j = 1;
    wmove(map, 0, 0);
    while (i < size)
    {
        while (i < j * 64)
        {
            if (i < size)
            {
                wattron(map, A_BOLD | COLOR_PAIR(pl->color[i]));
                wprintw(map, "%02x", pl->map[i]);
                wattroff(map, A_BOLD | COLOR_PAIR(pl->color[i]));
            }
            if (i != j * 64 - 1)
                wprintw(map, " ");
            i++;
        }
        wprintw(map, "\n");
        j++;
    }
    out_cycles(pl);
}

