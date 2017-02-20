/*
** navy_bonus.c for navy_bonus in /home/augustin/Bureau/augustin/projets_groupes/Navy/PSU_2016_navy/bonus/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Wed Feb  1 14:16:45 2017 augustin leconte
** Last update Mon Feb 20 13:24:35 2017 augustin leconte
*/

#include "tetris.h"

void print_name(void)
{
  clear();
  int i;
  int len;

  i = 0;
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  len = my_strlen("_______  ______   _______    ____            _____") / 2;
  mvprintw(1, COLS / 2 - len, "_______  ______   _______    ____             _____");
  mvprintw(2, COLS / 2 - len, "   |     |           |       |   \\    |     /");
  mvprintw(3, COLS / 2 - len, "   |     |__         |       |_  /     |     \\__");
  mvprintw(4, COLS / 2 - len, "   |     |           |       |  \\     |         \\");
  mvprintw(5, COLS / 2 - len, "   |     |_____      |       |   \\    |     ____/");
  print_line(4);
  print_line(LINES - 13);
  attroff(COLOR_PAIR(1));
  refresh();
}
