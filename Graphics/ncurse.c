/*
** ncurse.c for ncurses in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Mon Feb 20 11:01:37 2017 augustin leconte
** Last update Mon Feb 20 13:51:03 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

void print_line(int where)
{
  int i;

  i = -1;
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  while (++i < COLS)
    mvprintw(where, i, "-");
  attroff(COLOR_PAIR(1));
}

void print_name()
{
  int len;

  clear();
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  len = my_strlen("_______  ______   _______    ____            _____") / 2;
  attron(COLOR_PAIR(1));
  mvprintw(1, COLS / 2 - len, "_______  ______   _______    ____            ____");
  mvprintw(2, COLS / 2 - len, "   |     |           |       |   \\    |     / ");
  mvprintw(3, COLS / 2 - len, "   |     |__         |       |_  /    |     \\__");
  mvprintw(4, COLS / 2 - len, "   |     |           |       |  \\     |        \\");
  mvprintw(5, COLS / 2 - len, "   |     |_____      |       |   \\    |     ___/");
  print_line(7);
  print_line(LINES - 13);
  refresh();
  attroff(COLOR_PAIR(1));
}

int  main()
{
  int i;

  i = 0;
  initscr();
  clear();
  noecho();
  curs_set(FALSE);
  while (1)
    print_name();
  endwin();
  return (0);
}
