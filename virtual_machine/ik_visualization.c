#include "virtual_machine.h"

void init_window(void) {
    initscr(); //инициализируем библиотеку
    cbreak();  //Не использовать буфер для функции getch()
    //raw();
    nonl();
    noecho(); //Не печатать на экране то, что набирает пользователь на клавиатуре
    curs_set(0); //Убрать курсор
    keypad(stdscr, TRUE); //Активировать специальные клавиши клавиатуры (например, если хотим использовать горячие клавиши)
    start_color(); //Активируем поддержку цвета

    init_pair(1, COLOR_RED,     COLOR_BLACK);
    init_pair(11, COLOR_WHITE,   COLOR_RED);
    init_pair(2, COLOR_GREEN,    COLOR_BLACK);
    init_pair(12, COLOR_WHITE,   COLOR_GREEN);
    init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(13, COLOR_WHITE,   COLOR_YELLOW);
    init_pair(4, COLOR_BLUE,    COLOR_BLACK);
    init_pair(14, COLOR_WHITE,   COLOR_BLUE);

    init_pair(5, COLOR_WHITE,   COLOR_BLACK);

    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_BLACK,   COLOR_YELLOW);
    init_pair(8, COLOR_BLACK,   COLOR_BLACK);
}

void    out_cycles(t_struct *pl)
{
    int i;
    int j;

    mvprintw(10, 200, "Cycles = ");
    attron(A_BOLD | COLOR_PAIR(6));
    printw("%d", pl->iterator++);
    attroff(A_BOLD | COLOR_PAIR(6));
    i = 0;
    j = 12;
    while (i < pl->num_pl){
        attron(A_BOLD | COLOR_PAIR(i + 1));
        mvprintw(j, 200, "Player[%d] say live - [%d] times",
                 (int)pl->players[i]->player_number, pl->players[i]->count_live);
        attroff(A_BOLD | COLOR_PAIR(i + 1));
        j += 2;
        i++;
    }
}

void    out_winner(t_struct *pl)
{
    int row;
    int col;

    clear();
    getmaxyx(stdscr, row, col);
    attron(A_BOLD | COLOR_PAIR(pl->number_last_live_player * -1));
    mvwprintw(stdscr, row / 2, (col - 22) / 2, "Winner is player N[%d]", (int) pl->number_last_live_player);
    attroff(A_BOLD | COLOR_PAIR((int) ((pl->number_last_live_player * -1) - 1)));
    refresh();
    halfdelay(200);
    getch();
}

void	visualization(t_struct *pl, size_t size)
{
    size_t			i;
    size_t			j;

    i = 0;
    j = 1;
    move(0, 0);
    while (i < size)
    {
        while (i < j * 64)
        {
            if (i < size)
            {
                attron(A_BOLD | COLOR_PAIR(pl->color[i]));
                printw("%02x", pl->map[i]);
                attroff(A_BOLD | COLOR_PAIR(pl->color[i]));
            }
                printw(" ");
            i++;
        }
        printw("\n");
        j++;
    }
    out_cycles(pl);
}

