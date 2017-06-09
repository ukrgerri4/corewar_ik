#include "virtual_machine.h"

static void    set_my_color(void)
{
    start_color();
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
}

void    set_frame(void)
{
    int i;
    int j;

    i = 0;
    while (i < 68){
        attron(COLOR_PAIR(5));
        if (i == 0 || i == 33 || i == 67)
        {
            if (i == 33)
                j = 196;
            else
                j = 0;
            while (j < 258)
                mvprintw(i, j++, " ");
        }
        mvprintw(i, 0, " ");
        mvprintw(i, 196, " ");
        mvprintw(i, 257, " ");
        attroff(COLOR_PAIR(5));
        i++;
    }
    refresh();
}

void init_window(void)
{
    initscr();
    cbreak();
    nonl();
    noecho();
    curs_set(0);
    set_my_color();
    set_frame();
    map = newwin(64, 192, 2, 3);
    info1 = newwin(32, 60, 1, 197);
    info2 = newwin(32, 60, 34, 197);
    wrefresh(map);
    wrefresh(info1);
    wrefresh(info2);
}

