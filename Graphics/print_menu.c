/*
** print_menu.c for print_menu in /home/augustin/Bureau/augustin/projets_groupes/Tetris/PSU_2016_tetris/Graphics/
**
** Made by augustin leconte
** Login   <augustin.leconte@epitech.eu>
**
** Started on  Tue Feb 21 16:03:30 2017 augustin leconte
** Last update Thu Mar  2 11:18:49 2017 augustin leconte
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <wait.h>
#include <curses.h>
#include <ncurses.h>
#include "tetris.h"

int my_strlen();

void print_line(int where)
{
  int i;

  i = -1;
  start_color();
  init_pair(4, COLOR_WHITE, COLOR_WHITE);
  attron(COLOR_PAIR(4));
  while (++i < COLS)
    mvprintw(where, i, "-");
  attroff(COLOR_PAIR(4));
}

void print_name()
{
  int len;

  start_color();
  init_pair(3, COLOR_BLUE, COLOR_BLUE);
  attron(COLOR_PAIR(3));
  len = 53 / 2;
  mvprintw(1, COLS / 2 - len, "**********");
  mvprintw(1, COLS / 2 - len + 11, "********");
  mvprintw(1, COLS / 2 - len + 20, "**********");
  mvprintw(1, COLS / 2 - len + 31, "******");
  mvprintw(1, COLS / 2 - len + 42, "**");
  mvprintw(1, COLS / 2 - len + 45, "******");
  mvprintw(2, COLS / 2 - len + 4, "**");
  mvprintw(2, COLS / 2 - len + 11, "**");
  mvprintw(2, COLS / 2 - len + 24, "**");
  mvprintw(2, COLS / 2 - len + 31, "**");
  mvprintw(2, COLS / 2 - len + 37, "**");
  mvprintw(2, COLS / 2 - len + 42, "**");
  mvprintw(2, COLS / 2 - len + 45, "**");
  mvprintw(3, COLS / 2 - len + 4, "**");
  mvprintw(3, COLS / 2 - len + 11, "******");
  mvprintw(3, COLS / 2 - len + 24, "**");
  mvprintw(3, COLS / 2 - len + 31, "******");
  mvprintw(3, COLS / 2 - len + 42, "**");
  mvprintw(3, COLS / 2 - len + 45, "******");
  mvprintw(4, COLS / 2 - len + 4, "**");
  mvprintw(4, COLS / 2 - len + 11, "**");
  mvprintw(4, COLS / 2 - len + 24, "**");
  mvprintw(4, COLS / 2 - len + 31, "**");
  mvprintw(4, COLS / 2 - len + 37, "**");
  mvprintw(4, COLS / 2 - len + 42, "**");
  mvprintw(4, COLS / 2 - len + 49, "**");
  mvprintw(5, COLS / 2 - len + 4, "**");
  mvprintw(5, COLS / 2 - len + 11, "********");
  mvprintw(5, COLS / 2 - len + 24, "**");
  mvprintw(5, COLS / 2 - len + 31, "**");
  mvprintw(5, COLS / 2 - len + 37, "**");
  mvprintw(5, COLS / 2 - len + 42, "**");
  mvprintw(5, COLS / 2 - len + 45, "******");
  attroff(COLOR_PAIR(3));
}

void play()
{
  int len;

  attron(COLOR_PAIR(3));
  len = 35 / 2;
  mvprintw(20, COLS / 2 - len, "********");
  mvprintw(20, COLS / 2 - len + 9, "**");
  mvprintw(20, COLS / 2 - len + 18, "****");
  mvprintw(20, COLS / 2 - len + 25, "**");
  mvprintw(20, COLS / 2 - len + 33, "**");
  mvprintw(21, COLS / 2 - len, "**");
  mvprintw(21, COLS / 2 - len + 6, "**");
  mvprintw(21, COLS / 2 - len + 9, "**");
  mvprintw(21, COLS / 2 - len + 16, "**");
  mvprintw(21, COLS / 2 - len + 22, "**");
  mvprintw(21, COLS / 2 - len + 25, "**");
  mvprintw(21, COLS / 2 - len + 33, "**");
  mvprintw(22, COLS / 2 - len, "********");
  mvprintw(22, COLS / 2 - len + 9, "**");
  mvprintw(22, COLS / 2 - len + 16, "********");
  mvprintw(22, COLS / 2 - len + 27, "**");
  mvprintw(22, COLS / 2 - len + 31, "**");
  mvprintw(23, COLS / 2 - len, "**");
  mvprintw(23, COLS / 2 - len + 9, "**");
  mvprintw(23, COLS / 2 - len + 16, "**");
  mvprintw(23, COLS / 2 - len + 22, "**");
  mvprintw(23, COLS / 2 - len + 29, "**");
  mvprintw(24, COLS / 2 - len, "**");
  mvprintw(24, COLS / 2 - len + 9, "******");
  mvprintw(24, COLS / 2 - len + 16, "**");
  mvprintw(24, COLS / 2 - len + 22, "**");
  mvprintw(24, COLS / 2 - len + 29, "**");
  attroff(COLOR_PAIR(3));
  // attron(COLOR_PAIR(4) | A_UNDERLINE);
  // mvprintw(25, COLS / 2 - len, "                              ");
  // attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void quit()
{
  int len;

  attron(COLOR_PAIR(3));
  len = my_strlen("  __                _______") / 2;
  mvprintw(30, COLS / 2 - len, "  __                _______");
  mvprintw(31, COLS / 2 - len, " /  \\  |     |   |     |");
  mvprintw(32, COLS / 2 - len, "|    | |     |   |     |");
  mvprintw(33, COLS / 2 - len , "\\__/   \\___/    |     |");
  mvprintw(34, COLS / 2 - len, "    \\");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(35, COLS / 2 - len, "                              ");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}

void help()
{
  int len;

  len = my_strlen("_    _   ____         ____") / 2;
  attron(COLOR_PAIR(3));
  mvprintw(40, COLS / 2 - len, "_    _   ____         ____");
  mvprintw(41, COLS / 2 - len, "|    |  |       |     |   \\");
  mvprintw(42, COLS / 2 - len, "|====|  |___    |     |___/");
  mvprintw(43, COLS / 2 - len, "|    |  |       |     |");
  mvprintw(44, COLS / 2 - len, "|    |  |_____  |____ |");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(4) | A_UNDERLINE);
  mvprintw(45, COLS / 2 - len, "                          ");
  attroff(COLOR_PAIR(4) | A_UNDERLINE);
}
