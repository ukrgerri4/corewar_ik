#include "virtual_machine.h"

void init_window(void) {
    int row;
    int col;

    initscr(); //инициализируем библиотеку
    start_color(); //Активируем поддержку цвета
    use_default_colors();
    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(11, COLOR_WHITE,   COLOR_RED);
    init_pair(2, COLOR_GREEN,    COLOR_BLACK);
    init_pair(12, COLOR_WHITE,   COLOR_GREEN);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(13, COLOR_WHITE,   COLOR_YELLOW);
    init_pair(4, COLOR_BLUE,    COLOR_BLACK);
    init_pair(14, COLOR_WHITE,   COLOR_BLUE);
    init_pair(5, COLOR_WHITE,   COLOR_WHITE);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_BLACK,   COLOR_YELLOW);
    init_pair(8, COLOR_BLACK,   COLOR_BLACK);

    cbreak();  //Не использовать буфер для функции getch()
    nonl();
    noecho(); //Не печатать на экране то, что набирает пользователь на клавиатуре
    curs_set(0); //Убрать курсор
    keypad(stdscr, TRUE); //Активировать специальные клавиши клавиатуры (например, если хотим использовать горячие клавиши)
    getmaxyx(stdscr, col, row);
    int i = 0, j = 0;
    while (i < 68){
        j = 0;
        while (j < 258){
            //if (i == 0 || j == 0 || i == col - 1 || j == row - 1) {
                attron(COLOR_PAIR(5));
                printw(" ");
                attroff(COLOR_PAIR(5));
            //}
            //else
            //    printw(" ");
            j++;
        }
        printw("\n");
        i++;
    }
    refresh();
    map = newwin(66, 195, 1, 1);
    info = newwin(66, 60, 1, 197);
    wrefresh(info);
}

void    out_cycles(t_struct *pl)
{
    int i;
    int j;

    mvwprintw(map, 10, 200, "Cycles = ");
    wattron(map, A_BOLD | COLOR_PAIR(6));
    wprintw(map, "%d", pl->iterator++);
    wattroff(map, A_BOLD | COLOR_PAIR(6));
    i = 0;
    j = 12;
    while (i < pl->num_pl){
        wattron(map, A_BOLD | COLOR_PAIR(i + 1));
        mvwprintw(map, j, 200, "Player[%d] say live - [%d] times",
                 (int)pl->players[i]->player_number, pl->players[i]->count_live);
        wattroff(map, A_BOLD | COLOR_PAIR(i + 1));
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
    wmove(map, 1, 0);
    while (i < size)
    {
        wprintw(map, " ");
        while (i < j * 64)
        {
            if (i < size)
            {
                wattron(map, A_BOLD | COLOR_PAIR(pl->color[i]));
                wprintw(map, " %02x", pl->map[i]);
                wattroff(map, A_BOLD | COLOR_PAIR(pl->color[i]));
            }
            if (i == j * 64 - 1)
                wprintw(map, " ");
            i++;
        }
        wprintw(map, "\n");
        j++;
    }
    out_cycles(pl);
}

