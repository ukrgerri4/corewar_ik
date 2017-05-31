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
    init_pair(0, COLOR_RED,     COLOR_BLACK);
    init_pair(1, COLOR_GREEN,    COLOR_BLACK);
    init_pair(2, COLOR_YELLOW,  COLOR_BLACK);
    init_pair(3, COLOR_BLUE,    COLOR_BLACK);

    init_pair(4, COLOR_WHITE,   COLOR_BLACK);

    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_BLACK,   COLOR_YELLOW);
}


void	visualization(t_struct *pl, size_t size)
{
    char			base[17] = "0123456789abcdef";
    unsigned char	*mem;
    unsigned char	c;
    size_t			i;
    size_t			j;


    i = 0;
    j = 1;
    mem = pl->map;
    attron(COLOR_PAIR(4));
    while (i < size)
    {
        while (i < j * 64)
        {
            c = mem[i];
            if (i < size)
            {
                printw("%c", base[c / 16]);
                c %= 16;
                printw("%c", base[c % 16]);
            }
                printw(" ");
            i++;
        }
        printw("\n");
        j++;
    }

    attroff(COLOR_PAIR(4));
    mvprintw(10, 200, "Cycles = ");
    attron(A_BOLD | COLOR_PAIR(5));
    printw("%d", pl->iterator++);
    attroff(A_BOLD | COLOR_PAIR(5));
    i = 0;
    j = 12;
    while ((int)i < pl->num_pl){
        attron(A_BOLD | COLOR_PAIR(i));
        mvprintw((int)j, 200, "Player[%d] say live - [%d] times", (int)pl->players[i]->player_number, pl->players[i]->count_live);
        attroff(A_BOLD | COLOR_PAIR(i));
        j += 2;
        i++;
    }
    move(0, 0);

}

