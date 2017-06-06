#include "virtual_machine.h"

void init_window(void) {
    initscr(); //инициализируем библиотеку
    cbreak();  //Не использовать буфер для функции getch()
    //raw();
    nonl();
    noecho(); //Не печатать на экране то, что набирает пользователь на клавиатуре
    curs_set(0); //Убрать курсор
    keypad(stdscr, TRUE); //Активировать специальные клавиши клавиатуры (например, если хотим использовать горячие клавиши)
    if (has_colors() == FALSE) //На практике столкнулся с линуксом, на котором не было поддержки цвета.
    {
        endwin();
        puts("\nYour terminal does not support color\n");
    }
    start_color(); //Активируем поддержку цвета
    use_default_colors(); //Фон stscr будет "прозрачным"
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


void	visualization(t_struct *pl, size_t size)
{
    unsigned char	*mem;
    size_t			i;
    size_t			j;

    move(0, 0);
    i = 0;
    j = 1;
    mem = pl->map;
    while (i < size)
    {
        while (i < j * 64)
        {
            if (i < size)
            {
                attron(A_BOLD | COLOR_PAIR(pl->color[i]));
                printw("%02x", mem[i]);
                attroff(A_BOLD | COLOR_PAIR(pl->color[i]));
            }
                printw(" ");
            i++;
        }
        printw("\n");
        j++;
    }
    mvprintw(10, 200, "Cycles = ");
    attron(A_BOLD | COLOR_PAIR(6));
    printw("%d", pl->iterator++);
    attroff(A_BOLD | COLOR_PAIR(6));
    i = 0;
    j = 12;
    while ((int)i < pl->num_pl){
        attron(A_BOLD | COLOR_PAIR(i + 1));
        mvprintw((int)j, 200, "Player[%d] say live - [%d] times", (int)pl->players[i]->player_number, pl->players[i]->count_live);
        attroff(A_BOLD | COLOR_PAIR(i + 1));
        j += 2;
        i++;
    }
}

